#pragma once
#include <iostream>
#include <vector>

namespace Settings
{
	int settingselected = 0;

	static int Tab = 1;

	bool english = true;

	bool leftHoldActive = false;

	//LeftClicker
	bool leftClickEnabled = false;
	float leftClickgrad = 0;
	float leftClickrate = 0;
	bool leftHold = false;
	int leftKeyBind = 0;
	const char* leftStateEnglish = "set Keybind";
	const char* leftStateGerman = "setze Tastenkombination";

	//RightClicker
	bool rightClickEnabled = false;
	float rightClickgrad = 0;
	float rightClickrate = 0;
	bool rightHold = false;
	int rightKeyBind = 0;

	bool rightHoldActive = false;

	bool Selfdestruct = false;

	const char* rightStateEnglish = "set Keybind";
	const char* rightStateGerman = "setze Tastenkombination";

	char settingText[20];
}