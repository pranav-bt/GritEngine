#include "Collision.h"
#include "Collision.h"

namespace GritEngine
{
	std::vector<collision*> collision::collisionlist = std::vector<collision*>();
	
	void collision::AddCollisionEvent(std::function<void(collision* other)> Event)
	{
		CollisionHandle = Event;		
	}

	void collision::update(float dt)
	{
		for (auto element : collision::collisionlist)
		{
			Smart_Ptr<GameObject> Object1(element->WeakGO);
			for (auto other : collision::collisionlist)
			{
				Smart_Ptr<GameObject> Object2(other->WeakGO);
				if (Object2 == Object1)
				{

				}
				else
				{
					bool collision = checkcustomcollision(dt, Object2, Object1, other, element);
					if (collision && element->CollisionHandle != nullptr)
					{
						element->CollisionHandle(other);
						if(other->CollisionHandle)
							other->CollisionHandle(element);
					}
				}
			}
		}
	}
	
	bool collision::checkcustomcollision(float dt, Smart_Ptr<GameObject> obj1, Smart_Ptr<GameObject> obj2, collision* obj1col, collision* obj2col)
	{
		float tstart = 0.0f;
		float tend = dt;
		float tclose = 0;
		float topen = 0;
		{
			Matrix obj1toworld = Matrix::CreateTranslation(obj1->getpos().x(), obj1->getpos().y(), 1);
			Matrix obj2toworld = Matrix::CreateTranslation(obj2->getpos().x(), obj2->getpos().y(), 1);
			Matrix worldtoobj2 = obj2toworld.GetNewInvertMatrix();
			Matrix obj1toobj2 = worldtoobj2 * obj1toworld;
			Vector4 obj1postoobj2 = obj1toobj2.VectorRightMulitply(Vector4(obj1->getpos().x(), obj1->getpos().y(), 1.0f, 1.0f));
			if (obj1col && obj2col) 
			{
				Vector4 obj1BBCenterinobj2 = obj1toobj2.VectorRightMulitply(Vector4(obj1col->aabb->center.x(), obj1col->aabb->center.y(), 1.0f, 1.0f));
				Vector4 obj1ExtentXInobj2 = obj1toobj2.VectorRightMulitply(Vector4(obj1col->aabb->extents.x(), 0.0f, 0.0f, 0.0f));
				Vector4 obj1ExtentYInobj2 = obj1toobj2.VectorRightMulitply(Vector4(0.0f, obj1col->aabb->extents.y(), 0.0f, 0.0f));

				float obj1projontoobj2 = fabs(obj1ExtentXInobj2.GetX()) + fabs(obj1ExtentYInobj2.GetX());
				Vector4 obj1centerinobj2 = obj1toobj2.VectorRightMulitply(Vector4(obj1col->aabb->center.x(), obj1col->aabb->center.y(), 1.0f, 1.0f));

				float 	obj1LeftEdgeInobj2 = obj1centerinobj2.x - obj1projontoobj2;
				float 	obj1RightEdgeInobj2 = obj1centerinobj2.x + obj1projontoobj2;
				float 	obj1TopEdgeInobj2 = obj1centerinobj2.y + obj1projontoobj2;
				float 	obj1DownEdgeInobj2 = obj1centerinobj2.y - obj1projontoobj2;
				Point2D AvelRelToB = obj1->velocity - obj2->velocity;
				Vector4 AvelRelToBInB = worldtoobj2.VectorRightMulitply(Vector4(AvelRelToB.x(), AvelRelToB.y(), 0, 0));
				float obj2leftedge = (obj2col->aabb->center.x() - obj2col->aabb->extents.x());
				float obj2Rightedge = (obj2col->aabb->center.x() + obj2col->aabb->extents.x());
				float tcloseAX = (obj2leftedge - obj1RightEdgeInobj2) / AvelRelToBInB.x;
				float topenAX = (obj2Rightedge - obj1LeftEdgeInobj2) / AvelRelToBInB.x;
				tclose = tcloseAX;
				topen = topenAX;
				if (topenAX < tcloseAX)
				{
					std::swap(topenAX, tcloseAX);
				}
				if (tcloseAX > tend || topenAX < 0)
				{
					return false;
				}
				if (AvelRelToBInB.x == 0)
				{
					if (obj1centerinobj2.x <  obj2leftedge && obj1centerinobj2.x > obj2Rightedge)
					{
						return false;
					}
				}
				float obj2topedge = (obj2col->aabb->center.y() - obj2col->aabb->extents.y());
				float obj2downedge = (obj2col->aabb->center.y() + obj2col->aabb->extents.y());
				float tcloseAY = (obj2topedge - obj1DownEdgeInobj2) / AvelRelToBInB.y;
				float topenAY = (obj2downedge - obj1TopEdgeInobj2) / AvelRelToBInB.y;
				if (topenAY < tcloseAY)
				{
					std::swap(topenAY, tcloseAY);
				}
				if (topenAY < topen)
				{
					topen = topenAY;
				}
				if (tcloseAY > tclose)
				{
					tclose = tcloseAY;
				}
				if (tcloseAY > tend || topenAY < 0)
				{
					return false;
				}
				if (AvelRelToBInB.y == 0)
				{
					if (obj1centerinobj2.y <  obj2topedge && obj1centerinobj2.y > obj2downedge)
					{
						return false;
					}
				}


				/*bool bSeparationX = fabs(obj1postoobj2.x + obj1centerinobj2.x - obj2->getpos().x() + obj2col->aabb->center.x()) > fabs(obj1ExtentXInobj2.x + obj2col->aabb->extents.x());
				bool bSeparationY = fabs(obj1postoobj2.y + obj1centerinobj2.y - obj2->getpos().y() + obj2col->aabb->center.y()) > fabs(obj1ExtentYInobj2.y + obj2col->aabb->extents.y());
				if (!bSeparationY && !bSeparationX)
				{ 
					Log::print("Collision Detected AontoB\n", obj1);
					return true;
				}*/
			}
		}
		{
			Matrix obj1toworld = Matrix::CreateTranslation(obj1->getpos().x(), obj1->getpos().y(), 1);
			Matrix obj2toworld = Matrix::CreateTranslation(obj2->getpos().x(), obj2->getpos().y(), 1);
			Matrix worldtoobj1 = obj1toworld.GetNewInvertMatrix();
			Matrix obj2toobj1 =  worldtoobj1 * obj2toworld;
			Vector4 obj2postoobj1 = obj2toobj1.VectorRightMulitply(Vector4(obj2->getpos().x(), obj2->getpos().y(), 1.0f, 1.0f));
			if (obj1col && obj2col)
			{
				Vector4 obj2BBCenterinobj1 = obj2toobj1.VectorRightMulitply(Vector4(obj2col->aabb->center.x(), obj2col->aabb->center.y(), 1.0f, 1.0f));
				Vector4 obj2ExtentXInobj1 = obj2toobj1.VectorRightMulitply(Vector4(obj2col->aabb->extents.x(), 0.0f, 0.0f, 0.0f));
				Vector4 obj2ExtentYInobj1 = obj2toobj1.VectorRightMulitply(Vector4(0.0f, obj2col->aabb->extents.y(), 0.0f, 0.0f));

				float obj2projontoobj1 = fabs(obj2ExtentXInobj1.GetX()) + fabs(obj2ExtentYInobj1.GetX());
				Vector4 obj2centerinobj1 = obj2toobj1.VectorRightMulitply(Vector4(obj2col->aabb->center.x(), obj2col->aabb->center.y(), 1.0f, 1.0f));
				float obj2LeftEdgeInobj1 = obj2centerinobj1.x - obj2projontoobj1;
				float obj2RightEdgeInobj1 = obj2centerinobj1.x + obj2projontoobj1;
				float obj2TopEdgeInobj1 = obj2centerinobj1.y + obj2projontoobj1;
				float obj2DownEdgeInobj1 = obj2centerinobj1.y - obj2projontoobj1;


				Point2D BvelRelToA = obj2->velocity - obj1->velocity;
				Vector4 BvelRelToAInA = worldtoobj1.VectorRightMulitply(Vector4(BvelRelToA.x(), BvelRelToA.y(), 0, 0));
				float obj1leftedge = (obj1col->aabb->center.x() - obj1col->aabb->extents.x());
				float obj1Rightedge = (obj1col->aabb->center.x() + obj1col->aabb->extents.x());
				float obj1Topedge = (obj1col->aabb->center.y() - obj1col->aabb->extents.y());
				float obj1Downedge = (obj1col->aabb->center.y() + obj1col->aabb->extents.y());
				float tcloseAX = (obj1leftedge - obj2RightEdgeInobj1) / BvelRelToAInA.x;
				float topenAX = (obj1Rightedge - obj2LeftEdgeInobj1) / BvelRelToAInA.x;
				if (topenAX < tcloseAX)
				{
					std::swap(topenAX, tcloseAX);
				}
				if (tcloseAX > tend || topenAX < 0)
				{
					return false;
				}
				if (BvelRelToAInA.x == 0)
				{
					if (obj2centerinobj1.x <  obj1leftedge && obj2centerinobj1.x > obj1Rightedge)
					{
						return false;
					}
				}
				
				if (topenAX < topen)
				{
					topen = topenAX;
				}
				if (tcloseAX > tclose)
				{
					tclose = tcloseAX;
				}
				float tcloseAY = (obj1Topedge - obj2DownEdgeInobj1) / BvelRelToAInA.y;
				float topenAY = (obj1Downedge - obj2TopEdgeInobj1) / BvelRelToAInA.y;
				if (topenAY < tcloseAY)
				{
					std::swap(topenAY, tcloseAY);
				}
				if (tcloseAY > tend || topenAY < 0)
				{
					return false;
				}
				if (BvelRelToAInA.y == 0)
				{
					if (obj2centerinobj1.y <  obj1Topedge && obj2centerinobj1.y > obj1Downedge)
					{
						return false;
					}
				}

				if (topenAY < topen)
				{
					topen = topenAY;
				}
				if (tcloseAY > tclose)
				{
					tclose = tcloseAY;
				}

				/*bool aSeparationX = fabs(obj2postoobj1.x + obj2centerinobj1.x - obj1->getpos().x() + obj1col->aabb->center.x()) > fabs(obj2ExtentXInobj1.x + obj1col->aabb->extents.x());
				bool aSeparationY = fabs(obj2postoobj1.y + obj2centerinobj1.y - obj1->getpos().y() + obj1col->aabb->center.y()) > fabs(obj2ExtentYInobj1.y + obj1col->aabb->extents.y());
				if (!aSeparationY && !aSeparationX)
				{
					Log::print("Collision Detected BontoA\n", obj1);
					return true;
				}*/
			}
		}
		return tclose < topen;
	}
	
}