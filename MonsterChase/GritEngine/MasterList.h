#pragma once
#include<Vector>
#include "Physics.h"
#include "Components.h"
#include "interface.h"
#include "Rendering.h"
#include "Collision.h"
#include <unordered_map>
//Masterlist is basically a mastermap that keeps track of all the objects and its components.
namespace GritEngine 
{
	struct MasterObject
	{
		Smart_Ptr<GameObject> gameobject;
		PhysicsComponent* physicscomponent = nullptr;
		RenderComponent* rendercomponent = nullptr;
		collision* collisioncomponent = nullptr;
		MasterObject(GritEngine::Smart_Ptr<GameObject> gameobj) :gameobject(gameobj) {};

		~MasterObject()
		{
			delete physicscomponent;
			delete rendercomponent;
			delete collisioncomponent;
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
	collision* getcollisioncomponent(Smart_Ptr<GameObject> gameobj);
	Smart_Ptr<GameObject> GetGameObjectByName(std::string Name);
	
}