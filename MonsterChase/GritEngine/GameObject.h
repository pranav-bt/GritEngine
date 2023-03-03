#pragma once
#include<string.h>
#include<String>
#include"Point2D.h"
#include"Smart_Ptr.h"
namespace GritEngine {
class GameObject 
{
protected: 
	std::string name;
	GameObject() { };
public:
	GritEngine::Point2D position;
	GritEngine::Point2D velocity = {0,0};
	GameObject(std::string ObjName, GritEngine::Point2D pos) { name = ObjName; position = pos;   };
	GameObject(GritEngine::Point2D pos) { name = "Default"; position = pos; };
	GameObject(std::string ObjName) { name = ObjName; position.set(0,0);};
	virtual ~GameObject() {};
	void setname(std::string namee)
	{
		name = namee;
	}
	std::string getname() const
	{
		return name;
	}
	void setpos(GritEngine::Point2D pos)
	{
		position = pos; 
	}
	GritEngine::Point2D getpos() const
	{
		return position;
	}
	void update();
private:

};
}
