#pragma once
#include "Physics.h"
#include"MasterList.h"
#include"ClockTimer.h"
namespace GritEngine
{
	static class Application 
	{
	public:
		static void application_end();
		static void application_update();
		static bool ApplicationRunning;
	};
}