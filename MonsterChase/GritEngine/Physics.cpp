#include "Physics.h"
#include<windows.h>
char bufferrrr[1000];

namespace GritEngine
{
	std::vector<Physics*> Physics::PhysicsList = std::vector<Physics*>();

	void Physics::update(float dt)
	{
		for (auto& element : PhysicsList)
		{
			if (element->phyactive == true && element->isalive == true)
			{
				element->updateposition(dt);
			}
			//if ((element->isalive)==false)
			//{
			//	delete &element->Gameobject;
			//	delete element;
			//} 
		}
	}



	void Physics::updateposition(float dt)
	{
		Smart_Ptr<GameObject> SmartGO(Gameobject);
		if((&SmartGO))
		{
 		//	float vfx = (velocity.x() + (float)(accelaration.x() * dt)) - (velocity.x() * (1 - 0.8) * dt);        // 0.5 is coefficient of friction
			//float vfy = (velocity.y() + (float)(accelaration.y() * dt))  - (velocity.y() * (1 - 0.8) * dt);		 // 0.5 is coefficient of friction
			//if (velocity.x() < 0.005 && velocity.x() > -0.005)
			//{
			//	accelaration.setx(0);
			//	velocity.setx(0);
			//}
			//if (velocity.y() < 0.005 && velocity.y() > -0.005)
			//{
			//	accelaration.sety(0);
			//	velocity.sety(0);
			//}
			//velocity.setx(vfx);
			//Gameobject->position.setx(Gameobject->position.x() + (velocity.x() * dt));										// euler
			//velocity.sety(vfy);
			//Gameobject->position.sety(Gameobject->position.y() + (velocity.y() * dt));


		sprintf_s(bufferrrr, 1000, "position is : %f , %f || velocity is : %f, %f || delta time: %f || accelration : %f, %f\n", SmartGO->getpos().x(), SmartGO->getpos().y(), SmartGO->velocity.x(), SmartGO->velocity.y(), dt, accelaration.x(), accelaration.y());
		OutputDebugStringA(bufferrrr);
		Point2D currentdrag = { (float)(SmartGO->velocity.x() * -drag.x()),(float)(SmartGO->velocity.y() * -drag.y()) };
		Point2D TotalForce = { force.x() + currentdrag.x() , force.y() + currentdrag.y() };
		//if (currentdrag.mag() > force.mag())
		//{
		//	TotalForce = {0,0};
		//}
		accelaration.sety(TotalForce.y() / mass);
		accelaration.setx(TotalForce.x() / mass);
		float tempy =0 ; float tempx =0;
		
		tempy = SmartGO->velocity.y() + (accelaration.y() * (dt / 2));
		SmartGO->position.sety(SmartGO->position.y() + tempy * dt);
		accelaration.sety(TotalForce.y() / mass);
		SmartGO->velocity.sety(tempy + (accelaration.y() * (dt / 2)));
		//Log::print("dt value %f \n", dt);
		/*if (velocity.y() > 0)
			velocity.sety(velocity.y() * 0.98);
		else if (velocity.y() < 0)
			velocity.sety(velocity.y() * 0.98);*/
																				//Velocity Verlet
		tempx = SmartGO->velocity.x() + (accelaration.x() * (dt / 2));
		SmartGO->position.setx(SmartGO->position.x() + tempx * dt);
		accelaration.setx(TotalForce.x() / mass);
		SmartGO->velocity.setx(tempx + (accelaration.x() * (dt / 2)));
		//if (velocity.x() > 0)
		//	velocity.setx(velocity.x() * 0.98);
		//else if (velocity.x() < 0)
		//	velocity.setx(velocity.x() * 0.98);

		//if (velocity.x() < 0.1 && velocity.x() > -0.1)
		//{
		//	accelaration.setx(0);
		//	velocity.setx(0);
		//	force.setx(0);
		//}
		//if (velocity.y() < 0.1  && velocity.y() > -0.1)
		//{
		//	accelaration.sety(0);
		//	velocity.sety(0);
		//	force.sety(0);
		//}
		if (SmartGO->velocity.mag() < 0.5 && force.mag() == 0)
		{
			SmartGO->velocity = { 0,0 };
		}
		}
		else if (!&SmartGO)
		{
			delete &Gameobject;
		}
	}


	
	void Physics::moveto(Smart_Ptr<GameObject> target, float speed)
	{
		Smart_Ptr<GameObject> current(this->Gameobject);
		auto tar = target->getpos();
		auto cur = current->getpos();
		auto vel = (tar - cur);
		auto velnormalized = vel / (sqrt((vel.x() * vel.x()) + vel.y() * vel.y()));
		current->velocity = (velnormalized)*speed;
	}
}