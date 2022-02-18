#pragma once
#include "GLib.h"
class InputController
{
public:
	bool KeyW = false;
	bool KeyS = false;
	bool KeyA = false;
	bool KeyD = false;

	bool GetKeyPressW();
	bool GetKeyPressS();
	bool GetKeyPressA();
	bool GetKeyPressD();
	static void initialize();
	

	
};
