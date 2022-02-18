#include <stdio.h>
#include "EngineInitializer.h"
#include "ClockTimer.h"
namespace GritEngine
{
	void initialize()
	{
		GritEngine::InitializeClock();
		//printf("Grit Engine has started.\n");
	}
}