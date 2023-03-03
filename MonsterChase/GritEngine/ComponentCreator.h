#pragma once
#include "MasterList.h"
#include "../Library/json.hpp"
//#include "interface.h"
namespace GritEngine
{
	void CreatePhysicsComponent(Smart_Ptr<GameObject>& GO, nlohmann::json& physicsdata);
	void CreateRenderComponent(Smart_Ptr<GameObject>& GO, nlohmann::json& renderdata);
	void CreateCollisionComponent(Smart_Ptr<GameObject>& GO, nlohmann::json& renderdata);
}