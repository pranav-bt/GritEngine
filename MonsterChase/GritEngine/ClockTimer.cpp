#include"ClockTimer.h"
namespace GritEngine 
{
	DWORD previouscounter = 0;
	LARGE_INTEGER Frequency = {0};
	void InitializeClock()
	{
		previouscounter = 0;
		Frequency = { 0 };
		QueryPerformanceFrequency(&Frequency);
	}
	DWORD GetCurrentTickCounter()
	{
		LARGE_INTEGER CurrentFrame;
		if (QueryPerformanceCounter(&CurrentFrame))
		{
			return CurrentFrame.QuadPart;
		}
	}
	float DeltaTime()
	{
		DWORD startcounter = GetCurrentTickCounter();
		float deltatime = (1000 * static_cast<float>(startcounter - previouscounter)) / Frequency.QuadPart;
		previouscounter = startcounter;
		if(deltatime>0.4)
		{
			return 0.4f;
		}
		else
		return deltatime;
	}
}