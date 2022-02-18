#pragma once
#include <Windows.h>
static class Log 
{
public:
	template <typename T>
	static void print(const char* const ,T value);
};

template<typename T>
inline void Log::print(const char* const text,T value)
{
	char p[100];
	sprintf_s(p, 50, text, value); 
	OutputDebugStringA(p);
}
