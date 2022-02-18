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


		sprintf_s(bufferrrr, 1000, "position is : %f , %f || velocity is : %f, %f || delta time: %f || accelration : %f, %f\n", SmartGO->getpos().x(), SmartGO->getpos().y(), velocity.x(), velocity.y(), dt, accelaration.x(), accelaration.y());
		OutputDebugStringA(bufferrrr);

		accelaration.sety(force.y() / mass);
		accelaration.setx(force.x() / mass);
		float tempy =0 ; float tempx =0;
		
		tempy = velocity.y() + (accelaration.y() * (dt / 2));
		SmartGO->position.sety(SmartGO->position.y() + tempy * dt);
		accelaration.sety(force.y() / mass);
		velocity.sety(tempy + (accelaration.y() * (dt / 2)));
		if (force.y() > 0)
			force.sety(force.y() - 0.01);
		else if (force.y() < 0)
			force.sety(force.y() + 0.01);
																				//Velocity Verlet
		tempx = velocity.x() + (accelaration.x() * (dt / 2));
		SmartGO->position.setx(SmartGO->position.x() + tempx * dt);
		accelaration.setx(force.x() / mass);
		velocity.setx(tempx + (accelaration.x() * (dt / 2)));
		if (force.x() > 0)
			force.setx(force.x() - 0.01);
		else if (force.x() < 0)
			force.setx(force.x() + 0.01);

		if (velocity.x() < 0.2 && velocity.x() > -0.2)
		{
			accelaration.setx(0);
			velocity.setx(0);
			force.setx(0);
		}
		if (velocity.y() < 0.2 && velocity.y() > -0.2)
		{
			accelaration.sety(0);
			velocity.sety(0);
			force.sety(0);
		}
		}
		else if (!&SmartGO)
		{
			delete &Gameobject;
		}
	}
	
	//void Physics::moveto(GameObject* target, float dt)
	//{
	//	//if (velocity.x() == 0 && velocity.y() == 0 && force.x() == 0 && force.y()==0)
	//	//{
	//	//	velocity = { 0.3,0.3 };
	//	//	force = { 0.5,0.5 };
	//	//}
	//	
	//	if (target->getpos().x() - SmartGO->getpos().x() > 0)
	//	{
	//		if (accelaration.x() < 0)
	//		{
	//			accelaration.setx(-(accelaration.x()));
	//			updateposition(dt);
	//		}
	//	}
	//	if (target->getpos().x() - Gameobject->getpos().x() < 0)
	//	{
	//		if (accelaration.x() > 0)
	//		{
	//			accelaration.setx(-(accelaration.x()));
	//			updateposition(dt);
	//		}
	//	}
	//	if (target->getpos().y() - Gameobject->getpos().y() > 0)
	//	{
	//		if (accelaration.y() < 0)
	//		{
	//			accelaration.setx(-(accelaration.y()));
	//			updateposition(dt);
	//		}
	//	}
	//	if (target->getpos().y() - Gameobject->getpos().y() < 0)
	//	{
	//		if (accelaration.y() > 0)
	//		{
	//			accelaration.sety(-(accelaration.y()));
	//			updateposition(dt);
	//		}
	//	}
	//}
}