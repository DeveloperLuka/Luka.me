#include "functions.h"

#include <fstream>
#include <filesystem>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include "libs/cryptopp/include/cryptopp/base64.h"
#include "libs/cryptopp/include/cryptopp/aes.h"
#include "libs/cryptopp/include/cryptopp/modes.h"
#include "xorstr.hpp"

void Functions::Inject(std::string game)
{
	
}

void Functions::Rainbow()
{
	//This function was not made by me (xo1337), i found it off unknown cheats.
	float rainbowSpeed = 0.00060;
	static float staticHue = 0;
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	ImVec2 panelPos = ImGui::GetWindowPos();
	staticHue -= rainbowSpeed;
	if (staticHue < -1.f) staticHue += 1.f;
	for (int i = 0; i < 1200; i++)
	{
		float hue = staticHue + (1.f / (float)1200) * i;
		if (hue < 0.f) hue += 1.0f;
		ImColor cRainbow = ImColor::HSV(hue, 1.f, 1.f);
		draw_list->AddRectFilled(ImVec2(panelPos.x + i, panelPos.y + 2), ImVec2(panelPos.x + i + 1, panelPos.y + 4), cRainbow);
	}
}

void Functions::Line(const char* Id, int width = ImGui::GetContentRegionAvailWidth(), int height = 1)
{
	ImGui::BeginChild(Id, ImVec2(width, height), TRUE);
	ImGui::EndChild();
}

void Functions::LineEx(const char* Id)
{
	Functions::Line(Id, ImGui::GetContentRegionAvailWidth(), 1);
}

void Functions::LineVertical()
{
	ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
}

void Functions::Helpmarker(const char* Text, ImColor Color)
{
	ImGui::TextColored(Color, "(?)");
	if (ImGui::IsItemHovered())
		ImGui::SetTooltip(Text);
}

std::vector<std::string> Functions::getSettings()
{
	std::vector<std::string> res;

	auto string = getenv("APPDATA");
	std::string appdata = string;
	appdata += "\\Luka.me";
	int status = _mkdir(appdata.c_str());
	//if (status != 75 && status != 0)
	//	return res;

	
	for (auto& p : std::filesystem::recursive_directory_iterator(appdata))
	{
		if (p.path().extension() == ".setting")
		{
			res.push_back(p.path().stem().string());
		}
	}

	return res;
}

void Functions::loadSetting(std::string name)
{
	auto string = getenv(XorStr("APPDATA").c_str());
	std::string appdata = string;
	appdata += XorStr("\\Luka.me").c_str();

	std::fstream file;

	file.open(appdata + "\\" + name + XorStr(".setting").c_str(), std::fstream::in);
	if (!file)
	{
		return;
	}

	std::string s1;
	file >> s1;
	std::string settings = Functions::decryptString(s1);

	file.close();

	const char separator = '|';

	std::vector<std::string> outputArray;

	std::stringstream streamData(settings);

	std::string val;

	while (std::getline(streamData, val, separator)) {
		outputArray.push_back(val);
	}

	int i = 0;

	for (auto& val : outputArray) {
		switch (i)
		{
			//left
		case 0:
		{
			if (val == "0")
				Settings::leftClickEnabled = false;
			else if (val == "1")
				Settings::leftClickEnabled = true;
			break;
		}
		case 1:
		{
			Settings::leftClickgrad = strtof(val.c_str(), NULL);
			break;
		}
		case 2:
		{
			Settings::leftClickrate = strtof(val.c_str(), NULL);
			break;
		}
		case 3:
		{
			if (val == "0")
				Settings::leftHold = false;
			else if (val == "1")
				Settings::leftHold = true;
			break;
		}
		case 4:
		{
			Settings::leftKeyBind = std::stoi(val);
		}
		//right
		case 5:
		{
			if (val == "0")
				Settings::rightClickEnabled = false;
			else if (val == "1")
				Settings::rightClickEnabled = true;
			break;
		}
		case 6:
		{
			Settings::rightClickgrad = strtof(val.c_str(), NULL);
			break;
		}
		case 7:
		{
			Settings::rightClickrate = strtof(val.c_str(), NULL);
			break;
		}
		case 8:
		{
			if (val == "0")
				Settings::rightHold = false;
			else if (val == "1")
				Settings::rightHold = true;
			break;
		}
		case 9:
		{
			Settings::rightKeyBind = std::stoi(val);
		}
		}
		i++;
	}
}

void Functions::exportSetting()
{
	std::string setting;

	//left
	setting += std::to_string(Settings::leftClickEnabled) + "|";
	setting += std::to_string(Settings::leftClickgrad) + "|";
	setting += std::to_string(Settings::leftClickrate) + "|";
	setting += std::to_string(Settings::leftHold) + "|";
	setting += std::to_string(Settings::leftKeyBind) + "|";

	//right
	setting += std::to_string(Settings::rightClickEnabled) + "|";
	setting += std::to_string(Settings::rightClickgrad) + "|";
	setting += std::to_string(Settings::rightClickrate) + "|";
	setting += std::to_string(Settings::rightHold) + "|";
	setting += std::to_string(Settings::rightKeyBind) + "|";

	std::string encrypted = encryptString(setting);

	const size_t len = strlen(encrypted.c_str()) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), encrypted.c_str(), len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}

void Functions::importSetting()
{
	OpenClipboard(nullptr);
	HANDLE hData = GetClipboardData(CF_TEXT);

	char* pszText = static_cast<char*>(GlobalLock(hData));
	std::string e(pszText);
	std::string text = decryptString(e);

	GlobalUnlock(hData);
	CloseClipboard();
	


	const char separator = '|';

	std::vector<std::string> outputArray;

	std::stringstream streamData(text);
	
	std::string val;
	
	while (std::getline(streamData, val, separator)) {
		outputArray.push_back(val);
	}
	
	int i = 0;

	for (auto& val : outputArray) {
		switch (i)
		{
			//left
			case 0:
			{
				if (val == "0")
					Settings::leftClickEnabled = false;
				else if (val == "1")
					Settings::leftClickEnabled = true;
				break;
			}
			case 1:
			{
				Settings::leftClickgrad = strtof(val.c_str(), NULL);
				break;
			}
			case 2:
			{
				Settings::leftClickrate = strtof(val.c_str(), NULL);
				break;
			}
			case 3:
			{
				if (val == "0")
					Settings::leftHold = false;
				else if (val == "1")
					Settings::leftHold = true;
				break;
			}
			case 4:
			{
				Settings::leftKeyBind = std::stoi(val);
			}
			//right
			case 5:
			{
				if (val == "0")
					Settings::rightClickEnabled = false;
				else if (val == "1")
					Settings::rightClickEnabled = true;
				break;
			}
			case 6:
			{
				Settings::rightClickgrad = strtof(val.c_str(), NULL);
				break;
			}
			case 7:
			{
				Settings::rightClickrate = strtof(val.c_str(), NULL);
				break;
			}
			case 8:
			{
				if (val == "0")
					Settings::rightHold = false;
				else if (val == "1")
					Settings::rightHold = true;
				break;
			}
			case 9:
			{
				Settings::rightKeyBind = std::stoi(val);
			}
		}
		i++;
	}
}

void Functions::saveSetting(std::string name)
{
	std::fstream file;

	auto string = getenv("APPDATA");
	std::string appdata = string;
	appdata += "\\Luka.me";

	file.open(appdata + "\\" + name + ".setting", std::fstream::out);

	if (!file)
	{
		return;
	}

	std::string setting;

	//left
	setting += std::to_string(Settings::leftClickEnabled) + "|";
	setting += std::to_string(Settings::leftClickgrad) + "|";
	setting += std::to_string(Settings::leftClickrate) + "|";
	setting += std::to_string(Settings::leftHold) + "|";
	setting += std::to_string(Settings::leftKeyBind) + "|";

	//right
	setting += std::to_string(Settings::rightClickEnabled) + "|";
	setting += std::to_string(Settings::rightClickgrad) + "|";
	setting += std::to_string(Settings::rightClickrate) + "|";
	setting += std::to_string(Settings::rightHold) + "|";
	setting += std::to_string(Settings::rightKeyBind) + "|";

	std::string encrpt = Functions::encryptString(setting);

	file << encrpt;

	file.close();
}

void Functions::removeSetting(std::string name)
{
	auto string = getenv("APPDATA");
	std::string appdata = string;
	appdata += "\\Luka.me";

	remove((appdata + "\\" + name + ".setting").c_str());
}

std::string encrypt(const std::string& str_in, const std::string& key, const std::string& iv)
{

	std::string str_out;
	CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption encryption((byte*)key.c_str(), key.length(), (byte*)iv.c_str());
	CryptoPP::StringSource encryptor(str_in, true,
		new CryptoPP::StreamTransformationFilter(encryption,
			new CryptoPP::Base64Encoder(
				new CryptoPP::StringSink(str_out),
				false // do not append a newline
			)
		)
	);
	return str_out;
}


std::string decrypt(const std::string& str_in, const std::string& key, const std::string& iv)
{

	std::string str_out;
	CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption decryption((byte*)key.c_str(), key.length(), (byte*)iv.c_str());

	CryptoPP::StringSource decryptor(str_in, true,
		new CryptoPP::Base64Decoder(
			new CryptoPP::StreamTransformationFilter(decryption,
				new CryptoPP::StringSink(str_out)
			)
		)
	);
	return str_out;
}

std::string Functions::encryptString(std::string string)
{
	std::string key = "qwertyuiopasdfghjklzxcvbnmqwerty";
	std::string IV = "0123456789123456";

	return encrypt(string, key, IV);
}

std::string Functions::decryptString(std::string string)
{
	std::string key = "qwertyuiopasdfghjklzxcvbnmqwerty";
	std::string IV = "0123456789123456";

	return decrypt(string, key, IV);
}