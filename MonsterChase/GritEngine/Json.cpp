#include "Json.h"
namespace GritEngine
{
    //static std::unordered_map < std::string, std::function<void(Smart_Ptr<GameObject>&, nlohmann::json&)>> ComponentCreator = std::unordered_map < std::string, std::function<void(Smart_Ptr<GameObject>&, nlohmann::json&)>>();
    
    std::vector<uint8_t> LoadFile(const std::string& i_pFilename)
    {
        std::vector<uint8_t> Contents;
        if (!i_pFilename.empty())
        {
            FILE* pFile = NULL;
            errno_t fopenError = fopen_s(&pFile, i_pFilename.c_str(), "rb");
            if (fopenError == 0)
            {
                assert(pFile != NULL);

                int FileIOError = fseek(pFile, 0, SEEK_END);
                assert(FileIOError == 0);

                long FileSize = ftell(pFile);
                assert(FileSize >= 0);

                FileIOError = fseek(pFile, 0, SEEK_SET);
                assert(FileIOError == 0);

                Contents.reserve(FileSize);
                Contents.resize(FileSize);

                size_t FileRead = fread(&Contents[0], 1, FileSize, pFile);
                assert(FileRead == FileSize);

                fclose(pFile);
            }

        }
        return Contents;
    }



    void registerGO(GritEngine::Smart_Ptr<GameObject>* gameobj)
    {
        MasterObject* masterobject = new MasterObject(*gameobj);
        TempMasterMap.insert(std::pair<GameObject*, MasterObject*>(gameobj->getptr(), masterobject));
    }

    MasterObject* GritEngine::GetMasterObject(Smart_Ptr<GameObject> gameobject)
    {
        return TempMasterMap[(&gameobject)->getptr()];
    }

    Smart_Ptr<GameObject> Instantiate(const std::string& JSONfile)
    {
        Smart_Ptr<GameObject> gameobject;
        std::vector<uint8_t> content = LoadFile(JSONfile);
        if (!content.empty())
        {
            nlohmann::json Json = nlohmann::json::parse(content);
            gameobject = CreateGOfromJson(Json);
            
        }
        return gameobject;
    }
     
    
    Smart_Ptr<GameObject> CreateGOfromJson(nlohmann::json Data)
    {
        Smart_Ptr<GameObject> GO(new GameObject("Default"));
        AddNewGameObject(GO);
        Point2D GOposition = { 0,0 };
        std::string GOname = "";
        auto type = Data.type_name();
        if (Data.contains("initial_position"))
        {
            nlohmann::json Position = Data["initial_position"];
            assert(Position.is_array());
            GOposition = { Position[0], Position[1] };
            GO->setpos(GOposition);
        }
        if (Data.contains("name"))
        {
            nlohmann::json Name = Data["name"];
            assert(Name.is_string());
            GOname = Name;
            GO->setname(GOname);
        }
        if (Data.contains("components"))
        {
            assert(Data["components"].is_object());
            for (nlohmann::json::iterator it = Data["components"].begin(); it != Data["components"].end(); ++it)
            {
                nlohmann::json componentdata = it.value();
                std::string key = it.key();
                auto func = ComponentCreator[key];
                if(func)
                func(GO, componentdata);
            }
        }
        return GO;
    }

    void ProcessFileContents(uint8_t* i_pFileContents, size_t i_sizeFileContents, std::function<void(uint8_t*, size_t)> i_Processor)
    {
        if (i_pFileContents)
        {
            if (i_sizeFileContents && !Engine::JobSystem::ShutdownRequested())
                i_Processor(i_pFileContents, i_sizeFileContents);
        }

        delete[] i_pFileContents;

        std::cout << "ProcessFileContents finished processing file.\n";
    }


    Engine::Mutex NewGameObjectMutex;    
    // This adds a new GameObject to GameObjectsMasterlist
    void AddNewGameObject(Smart_Ptr<GameObject> i_pNewGameObject)
    {
        if (&i_pNewGameObject)
        {
            // Acquire a scoped lock on the mutex
            Engine::ScopeLock Lock(NewGameObjectMutex);
            registerGO(&i_pNewGameObject);
        }
    }

    // This will move GameObjects from TempMasterMap -> MasterMap
    void CheckForNewGameObjects()
    {
        Engine::ScopeLock Lock(NewGameObjectMutex);
           
        if (!TempMasterMap.empty())
        {
            for (auto it : TempMasterMap)
            {
                if (& it.first)
                {
                    Log::print("Moving Gameobject to AllObjectsMasterMap\n", it.first);
                    MasterList::mastermap.insert(std::pair<GameObject*, MasterObject*>(it.first,it.second));
                }
            }

            TempMasterMap.clear();
            TempMasterMap.reserve(0);
        }
    }

    // Helper function to create new GameObjects from a list of names in a text file
    void creategameobjects(uint8_t* i_pfilecontents, size_t i_sizefilecontents)
    {
        assert(i_pfilecontents && i_sizefilecontents);

        uint8_t* pendfilecontents = i_pfilecontents + i_sizefilecontents;

        while (i_pfilecontents < pendfilecontents)
        {
            size_t namelength = 0;
            const char* i_pnextname = reinterpret_cast<const char*>(i_pfilecontents);

            while ((i_pfilecontents < pendfilecontents) && *i_pfilecontents++ != '\r')
                namelength++;

            if (namelength)
            {
                std::string name(i_pnextname, namelength);
                Instantiate(name);
            }

            i_pfilecontents++;
        }
    }

    void CreateGameObject()
    {
        using namespace std::placeholders;

        {
            const char* CustomQueueName = "GameObjectLoader";

            Engine::HashedString QueueName = Engine::JobSystem::CreateQueue(CustomQueueName, 2);

            {
                Engine::JobSystem::RunJob(QueueName, std::bind(ProcessFile("GameObjects.txt", std::bind(creategameobjects, _1, _2))));

                do
                {
                    CheckForNewGameObjects();
                    Sleep(10);
                } while (Engine::JobSystem::HasJobs(CustomQueueName));
            }
            CheckForNewGameObjects();
        }

    }

}