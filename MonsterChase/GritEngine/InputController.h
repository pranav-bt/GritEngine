#pragma once
#include "GLib.h"
// InputController class provides access to all the controls which could be used in the game. 
// Create a new imputcontroller at the start of the game 
class InputController
{
private:
	void initialize();
public:
	InputController() { initialize(); }
	bool KeyW = false;
	bool KeyS = false;
	bool KeyA = false;
	bool KeyD = false;
	bool KeyQ = false;
	bool GetKeyPressW();
	bool GetKeyPressS();
	bool GetKeyPressA();
	bool GetKeyPressD();
	bool GetKeyPressQ();
};
static unsigned int CCUSTOMKEYID = NULL;
void CustomTestKeyCallback(unsigned int i_VKeyID, bool bWentDown);

