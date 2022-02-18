#pragma once
#include "Point2D.h"
#include "GameObject.h"
#include<vector>
#include "Weak_Ptr.h"
namespace GritEngine
{
	class Physics 
	{
	public:
		bool isalive = true;
		bool phyactive = false;
		float mass = 1;
		Point2D force = {0,0};
		Point2D accelaration = {0,0};
		Point2D velocity = { 0,0 };
		static std::vector<Physics*> PhysicsList;
		
		GritEngine::Weak_Ptr<GameObject> Gameobject;

		

		static void update(float dt);
		void updateposition(float dt);
		void moveto(GameObject* gameobject, float dt);
	};
}