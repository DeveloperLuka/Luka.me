#pragma once
#include <Windows.h>
#include <iostream>
#include <imgui.h>
#include <imgui_internal.h>
#include <vector>
#include "settings.h"

enum GAME_STATUS
{
	UNDETECTED,
	UPDATING,
	DETECTED,
	COMING_SOON
};

namespace Functions
{
	void Rainbow();
	void Helpmarker(const char* Text, ImColor Color);
	void Line(const char* Id, int width, int height);
	void LineEx(const char* Id);
	void LineVertical();

	std::string encryptString(std::string string);
	std::string decryptString(std::string string);

	std::vector<std::string> getSettings();
	void loadSetting(std::string name);
	void exportSetting();
	void importSetting();
	void saveSetting(std::string name);
	void removeSetting(std::string name);
	void Inject(std::string game);
}

