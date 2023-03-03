#pragma once
#include "GameObject.h"
#include<vector>
class Monster : public GritEngine::GameObject
{
private:
	Monster() { };
public:
	Monster(std::string Mname, GritEngine::Point2D pos) : GameObject(Mname, pos) { };
	Monster(std::string ObjName) : GameObject(ObjName) {  };


};