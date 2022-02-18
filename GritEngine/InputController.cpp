#include "InputController.h"



bool InputController::GetKeyPressW()
{
	return true;
}
bool InputController::GetKeyPressS()
{
	return true;
}
bool InputController::GetKeyPressA()
{
	return true;
}
bool InputController::GetKeyPressD()
{
	return true;
}

void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
{

	//const size_t	lenBuffer = 65;
	//char			Buffer[lenBuffer];
	//sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	//OutputDebugStringA(Buffer);
	if (bWentDown == true)
	{
		int KEYID = i_VKeyID;
	}
	else if (bWentDown == false)
	{
		int KEYID = NULL;
	}

}

void InputController::initialize()
{
	GLib::SetKeyStateChangeCallback(TestKeyCallback);
}
