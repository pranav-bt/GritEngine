#include "ComponentCreator.h"
#include "String"
namespace GritEngine
{
	void CreatePhysicsComponent(Smart_Ptr<GameObject>& GO, nlohmann::json& physicsdata)
	{
		PhysicsComponent* PC = new PhysicsComponent(GO);
		if (physicsdata.contains("mass"))
		{
			PC->physics->mass = physicsdata["mass"];
		}
		if (physicsdata.contains("force"))
		{
			nlohmann::json FORCE = physicsdata["force"];
			PC->physics->force = { FORCE[0],FORCE[1] };
		}
		if (physicsdata.contains("accelaration"))
		{
			PC->physics->accelaration = { physicsdata["accelaration"][0],physicsdata["accelaration"][1] };
		}
		if (physicsdata.contains("velocity"))
		{
			//PC->physics->velocity = { physicsdata["velocity"][0],physicsdata["velocity"][1] };
			GO->velocity = { physicsdata["velocity"][0],physicsdata["velocity"][1] };
		}

		GetMasterObject(GO)->physicscomponent = PC;
	}

	void CreateRenderComponent(Smart_Ptr<GameObject>& GO, nlohmann::json& renderdata)
	{
		RenderComponent* RC = new RenderComponent(GO);
		if (renderdata.contains("scale"))
		{
			RC->scale = renderdata["scale"];
		}
		if (renderdata.contains("sprite_texture"))
		{
			std::string value = renderdata["sprite_texture"] ;
			char* spritedir;
			spritedir = &value[0];
			RC->addsprite(spritedir);
		}
		GetMasterObject(GO)->rendercomponent = RC;
	}

	void CreateCollisionComponent(Smart_Ptr<GameObject>& GO, nlohmann::json& collisiondata)
	{
		collision* CC = new collision(GO);
		if (collisiondata.contains("centre"))
		{
			CC->aabb->center = { collisiondata["centre"][0], collisiondata["centre"][1]};
		}
		if (collisiondata.contains("extents"))
		{
			CC->aabb->extents = { collisiondata["extents"][0],collisiondata["extents"][1] };
		}
		GetMasterObject(GO)->collisioncomponent = CC;
	}
}