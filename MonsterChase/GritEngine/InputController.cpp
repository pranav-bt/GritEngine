#include "InputController.h"

bool InputController::GetKeyPressW()
{
	if (CCUSTOMKEYID == 0x0057)
		return true;
	else
		return false;

}
bool InputController::GetKeyPressS()
{
	if (CCUSTOMKEYID == 0x0053)
		return true;
	else
		return false;
}
bool InputController::GetKeyPressA()
{
	if (CCUSTOMKEYID == 0x0041)
		return true;
	else
		return false;
}
bool InputController::GetKeyPressD()
{
	if (CCUSTOMKEYID == 0x0044)
		return true;
	else
		return false;
}

bool InputController::GetKeyPressQ()
{
	if (CCUSTOMKEYID == 0x0051)
		return true;
	else
		return false;
}

void CustomTestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
{
	if (bWentDown == true)
	{
		CCUSTOMKEYID = i_VKeyID;
	}
	else if (bWentDown == false)
	{
		CCUSTOMKEYID = NULL;
	}

}

void InputController::initialize()
{
	GLib::SetKeyStateChangeCallback(CustomTestKeyCallback);
}
