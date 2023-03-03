#pragma once
#include "Physics.h"
#include "Weak_Ptr.h"
namespace GritEngine
{
	// This is a wrapper class on physics engine. This was done keeping in mind that there might be more physics related components. 
struct PhysicsComponent {
	PhysicsComponent(Smart_Ptr<GameObject> gameobj):temp(gameobj) {   physics = new Physics(); 
	Physics::PhysicsList.push_back(physics); 
	physicsactive = false; };
	Physics* physics = nullptr;
	Weak_Ptr<GameObject> temp;
	void setphysics(bool value)
	{
		physicsactive = value;
		if (physicsactive == true)
		{
			physics->phyactive = true;
			physics->Gameobject = temp;
		}
		else { physics->phyactive = false;  }
	}



	~PhysicsComponent()
	{
		physics->isalive = false;
		delete physics;
	}
private:
	PhysicsComponent() {};
	bool physicsactive = false;
};


}