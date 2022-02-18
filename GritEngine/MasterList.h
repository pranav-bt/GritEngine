#pragma once
#include<Vector>
#include "Physics.h"
#include "Components.h"
#include "interface.h"
#include "Rendering.h"
#include <Map>
#include <unordered_map>
namespace GritEngine 
{
	struct MasterObject
	{
		Smart_Ptr<GameObject> gameobject;
		PhysicsComponent* physicscomponent = nullptr;
		RenderComponent* rendercomponent = nullptr;
		MasterObject(GritEngine::Smart_Ptr<GameObject> gameobj) :gameobject(gameobj) { physicscomponent = new PhysicsComponent(gameobject); rendercomponent = new RenderComponent(gameobject); };

		~MasterObject()
		{
			delete physicscomponent;
			delete rendercomponent;
		}
		private:
		MasterObject() {};
	};

	class MasterList 
	{
	public :
		static std::unordered_map<GameObject*, MasterObject*> mastermap;
    private:
			MasterList() {};
	};

	PhysicsComponent* getphysicscomponent(Smart_Ptr<GameObject> gameobj);
	RenderComponent* getrendercomponent(Smart_Ptr<GameObject> gameobj);
}