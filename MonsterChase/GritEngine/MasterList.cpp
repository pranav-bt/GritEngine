#include"MasterList.h"
namespace GritEngine
{
	std::unordered_map<GameObject*, MasterObject*> MasterList::mastermap = std::unordered_map<GameObject*, MasterObject*>();
	
	/*void registerGO(GritEngine::Smart_Ptr<GameObject>* gameobj)
	{
		MasterObject* masterobject = new MasterObject(*gameobj);
		TempMasterMap.insert(std::pair<GameObject*, MasterObject*>(gameobj->getptr(), masterobject));
	}*/

	PhysicsComponent* getphysicscomponent(GritEngine::Smart_Ptr<GameObject> gameobject)
	{
		return MasterList::mastermap[(&gameobject)->getptr()]->physicscomponent;
	}

	RenderComponent* getrendercomponent(Smart_Ptr<GameObject> gameobject)
	{
		return MasterList::mastermap[(&gameobject)->getptr()]->rendercomponent;
	}

	collision* getcollisioncomponent(Smart_Ptr<GameObject> gameobj)
	{
		return MasterList::mastermap[(&gameobj)->getptr()]->collisioncomponent;
	}

	Smart_Ptr<GameObject> GetGameObjectByName(std::string Name)
	{
		for (auto it : MasterList::mastermap)
		{
			if (Name == it.first->getname())
			{
				return it.second->gameobject;
			}
		}
	}

	

}