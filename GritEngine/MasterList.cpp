#include"MasterList.h"
namespace GritEngine
{
	std::unordered_map<GameObject*, MasterObject*> MasterList::mastermap = std::unordered_map<GameObject*, MasterObject*>();

	void registerGO(GritEngine::Smart_Ptr<GameObject>* gameobj)
	{
		MasterObject* masterobject = new MasterObject(*gameobj);
		MasterList::mastermap.insert(std::pair<GameObject*, MasterObject*>(gameobj->getptr(), masterobject));
	}

	PhysicsComponent* getphysicscomponent(GritEngine::Smart_Ptr<GameObject> gameobject)
	{
		return MasterList::mastermap[(&gameobject)->getptr()]->physicscomponent;
	}

	RenderComponent* getrendercomponent(Smart_Ptr<GameObject> gameobject)
	{
		return MasterList::mastermap[(&gameobject)->getptr()]->rendercomponent;
	}
}