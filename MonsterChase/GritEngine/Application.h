#pragma once
#include"ClockTimer.h"
#include "ComponentCreator.h"
#include "Json.h"
#include "Collision.h"
namespace GritEngine
{
	// delay timer mechanism
	struct Delay
	{
		float value = 0;
		static std::vector<Delay*> DelayHandleList;
		Delay(float val) { DelayHandleList.push_back(this); value = val*600; }
	public:
		bool done = false;
	};
	static class Application 
	{
	public:

		static void application_end();
		static void application_update();
		static void application_initialize();
		static bool ApplicationRunning;
	};
}