#pragma once
#include "GameObject.h"
class Player : public GritEngine::GameObject
{
private:
	Player() { };
public:
	Player(std::string Mname, GritEngine::Point2D pos) : GameObject(Mname, pos) { };
	Player(std::string ObjName) : GameObject(ObjName) { };
};