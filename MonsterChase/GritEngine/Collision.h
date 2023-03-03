#pragma once
#include "GameObject.h"
#include "Weak_Ptr.h"
#include <vector>
#include "Matrix.h"
#include "Physics.h"
#include <functional>
namespace GritEngine
{
	class collision
	{
	private:
		
		
		static bool checkcustomcollision(float dt, Smart_Ptr<GameObject> obj1, Smart_Ptr<GameObject> obj2, collision* obj1col, collision* obj2col);
		collision() {};
	public:
		struct AABB { Point2D center; Point2D extents; };
		Weak_Ptr<GameObject> WeakGO;
		AABB* aabb = nullptr;
		std::function<void(collision* other)> CollisionHandle = nullptr;
		collision(Smart_Ptr<GameObject> SmartGO) : WeakGO(SmartGO) { collisionlist.push_back(this); aabb = new AABB; };
		void AddCollisionEvent(std::function<void(collision* other)> Event);
		static std::vector<collision*> collisionlist;
		static void update(float dt);
		
		~collision()
		{
			if (aabb)
			{
				delete aabb;
			}
		}
	};
}