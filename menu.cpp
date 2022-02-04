#include "menu.h"
#include "settings.h"
#include "clicker.h"
#include "functions.h"
#include "imguipp.h"
#include "icons.h"

#include <fstream>
#include <filesystem>

void Menu::Render()
{
	ImGui::Columns(2);
	ImGui::SetColumnOffset(1, 180);

	{
		//Left side

		static ImVec4 active = imguipp::to_vec4(41, 40, 41, 255);
		static ImVec4 inactive = imguipp::to_vec4(31, 30, 31, 255);

		if (Settings::english == true)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
			if (ImGui::Button(ICON_FA_USER " Home            ", ImVec2(180 - 15, 41)))
				Settings::Tab = 1;

			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
			if (ImGui::Button(ICON_FA_GAMEPAD " Left               ", ImVec2(180 - 15, 41)))
				Settings::Tab = 2;

			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
			if (ImGui::Button(ICON_FA_GAMEPAD " Right             ", ImVec2(180 - 15, 41)))
				Settings::Tab = 3;

			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
			if (ImGui::Button(ICON_FA_BOOK " Settings        ", ImVec2(180 - 15, 41)))
				Settings::Tab = 4;

			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? active : inactive);
			if (ImGui::Button(ICON_FA_TIMES_CIRCLE " Selfdestruct", ImVec2(180 - 15, 41)))
			{
				Functions::saveSetting("main");
				exit(-1);
			}

			ImGui::PopStyleColor(5);

			ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);
			imguipp::center_text("Premium", 1, false);
		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
			if (ImGui::Button(ICON_FA_USER " Hauptseite", ImVec2(180 - 15, 41)))
				Settings::Tab = 1;

			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
			if (ImGui::Button(ICON_FA_GAMEPAD " LinksClicker", ImVec2(180 - 15, 41)))
				Settings::Tab = 2;

			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
			if (ImGui::Button(ICON_FA_GAMEPAD " RechtsClicker", ImVec2(180 - 15, 41)))
				Settings::Tab = 3;

			ImGui::Spacing();
			ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
			if (ImGui::Button(ICON_FA_TIMES_CIRCLE " Schließen", ImVec2(180 - 15, 41)))
				Settings::Tab = 4;

			ImGui::PopStyleColor(4);
			
			
		}
	}

	ImGui::NextColumn();

	//Right side
	{
		if (Settings::english == true)
		{
			//Main Tab
			if (Settings::Tab == 1)
			{
				ImGui::Text("Luka.me clicker");
				ImGui::Text("I forgot what should be here");
			}

			//LeftClicker Tab
			if (Settings::Tab == 2)
			{
				ImGui::Checkbox("Enabled", &Settings::leftClickEnabled);

				ImGui::InputFloat("Click rate", &Settings::leftClickgrad, 0.0, 0.0);
				if (Settings::leftClickgrad > 3000)
					Settings::leftClickgrad = 3000;
				if (Settings::leftClickgrad < 1)
					Settings::leftClickgrad = 1;
				bool leftHold = Settings::leftHold;
				bool leftSwitch = !Settings::leftHold;

				if (leftHold)
				{
					if (ImGui::Button("Hold", ImVec2(270, 35)))
						Settings::leftHold = !Settings::leftHold;
					//if (ImGui::Checkbox("Halten", &rightHold))
					//	Settings::rightHold = rightHold;
				}
				else
				{
					if (ImGui::Button("Switch", ImVec2(270, 35)))
						Settings::leftHold = !Settings::leftHold;
				}

				ImGui::InputFloat("Click degree", &Settings::leftClickrate, 0.0f, 1.0f);
				if (Settings::leftClickrate > 100)
					Settings::leftClickrate = 100;
				if (Settings::leftClickrate < 0)
					Settings::leftClickrate = 0;

				if (ImGui::Button(Settings::leftStateEnglish, ImVec2(270, 35)))
				{
					Settings::leftStateEnglish = "Press Key";
				}
			}

			//RightClicker Tab
			if (Settings::Tab == 3)
			{
				ImGui::Checkbox("Enabled", &Settings::rightClickEnabled);

				ImGui::InputFloat("Click rate", &Settings::rightClickgrad, 0.0, 0.0);
				if (Settings::rightClickgrad > 3000)
					Settings::rightClickgrad = 3000;
				if (Settings::rightClickgrad < 1)
					Settings::rightClickgrad = 1;

				bool rightHold = Settings::rightHold;
				bool rightSwitch = !Settings::rightHold;

				if (rightHold)
				{
					if (ImGui::Button("Hold", ImVec2(270, 35)))
						Settings::rightHold = !Settings::rightHold;
					//if (ImGui::Checkbox("Halten", &rightHold))
					//	Settings::rightHold = rightHold;
				}
				else
				{
					if (ImGui::Button("Switch", ImVec2(270, 35)))
						Settings::rightHold = !Settings::rightHold;
				}

				ImGui::InputFloat("Click degree", &Settings::rightClickrate, 0.0, 100.0);
				if (Settings::rightClickrate > 100)
					Settings::rightClickrate = 100;
				if (Settings::rightClickrate < 0)
					Settings::rightClickrate = 0;


				if (ImGui::Button(Settings::rightStateEnglish, ImVec2(270, 35)))
				{
					Settings::rightStateEnglish = "Press Key";
				}
			}

			if (Settings::Tab == 4)
			{
				ImGui::ListBoxHeader("##Settings");
				for (int i = 0; i < Functions::getSettings().size(); i++)
				{
					const bool selected = (Settings::settingselected == i);
					if (ImGui::Selectable(Functions::getSettings()[i].c_str(), selected))
						Settings::settingselected = i;
					if (selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::ListBoxFooter();

				if (ImGui::Button(("Load Settings " + Functions::getSettings()[Settings::settingselected]).c_str(), ImVec2(270, 30)))
				{
					Functions::loadSetting(Functions::getSettings()[Settings::settingselected].c_str());
				}

				if (ImGui::Button("Export Current Settings", ImVec2(270, 30)))
				{
					Functions::exportSetting();
				}

				if (ImGui::Button("Import Settings", ImVec2(270, 30)))
				{
					Functions::importSetting();
				}

				ImGui::InputText("Settings Name", Settings::settingText, 30);
				std::string s = Settings::settingText;
				if (ImGui::Button(("Save Settings as " + s).c_str(), ImVec2(270, 30)))
				{
					Functions::saveSetting(s);
				}

				if (ImGui::Button(("Remove Settings " + Functions::getSettings()[Settings::settingselected]).c_str(), ImVec2(270, 30)))
				{
					Functions::removeSetting(Functions::getSettings()[Settings::settingselected].c_str());
				}
			}
		}
		else
		{
			if (Settings::Tab == 1)
			{
				ImGui::Text("Ventaz.me gemacht von Ventaz#8766");

				bool english = Settings::english;
				bool german = !Settings::english;

				if (ImGui::Checkbox("Englisch", &english))
					Settings::english = english;
				if (ImGui::Checkbox("Deutsch", &german))
					Settings::english = !english;
			}
			//LeftClicker Tab
			if (Settings::Tab == 2)
			{
				ImGui::InputFloat("Klickrate", &Settings::leftClickgrad, 0.0, 0.0);
				bool leftHold = Settings::leftHold;
				bool leftSwitch = !Settings::leftHold;
				if (ImGui::Checkbox("Halten", &leftHold))
					Settings::leftHold = leftHold;

				if (ImGui::Checkbox("Wechseln", &leftSwitch))
					Settings::leftHold = !leftHold;

				ImGui::InputFloat("Klickgrad", &Settings::leftClickrate, 0.0, 100.0);
				if (Settings::leftClickrate > 100)
					Settings::leftClickrate = 100;
				if (Settings::leftClickrate < 0)
					Settings::leftClickrate = 0;

				if (ImGui::Button(Settings::leftStateGerman, ImVec2(220, 41)))
				{
					Settings::leftStateGerman = "Drücke taste";
				}
			}

			//RightClicker Tab
			if (Settings::Tab == 3)
			{
				ImGui::InputFloat("Klickrate", &Settings::rightClickgrad, 0.0, 0.0);

				bool rightHold = Settings::rightHold;
				bool rightSwitch = !Settings::rightHold;

				if (rightHold)
				{
					if (ImGui::Button("Halten", ImVec2(270, 35)))
						Settings::rightHold = !Settings::rightHold;
					//if (ImGui::Checkbox("Halten", &rightHold))
					//	Settings::rightHold = rightHold;
				}
				else
				{
					if (ImGui::Button("Wechseln", ImVec2(270, 35)))
						Settings::rightHold = !Settings::rightHold;
				}

				ImGui::InputFloat("Klickgrad", &Settings::rightClickrate, 0.0, 100.0);
				if (Settings::rightClickrate > 100)
					Settings::rightClickrate = 100;
				if (Settings::rightClickrate < 0)
					Settings::rightClickrate = 0;


				if (ImGui::Button(Settings::rightStateGerman, ImVec2(270, 41)))
				{
					Settings::rightStateGerman = "Drücke taste";
				}
			}
		}
	}
}

void Menu::Theme()
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowBorderSize = 0;
	style->WindowTitleAlign = ImVec2(0.5, 0.5);
	style->WindowMinSize = ImVec2(600, 440);

	style->FramePadding = ImVec2(8, 6);

	style->Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 255);
	style->Colors[ImGuiCol_TitleBgActive] = ImColor(0, 0, 0, 255);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 130);

	style->Colors[ImGuiCol_Button] = ImColor(31, 30, 31, 255);
	style->Colors[ImGuiCol_ButtonActive] = ImColor(31, 30, 31, 255);
	style->Colors[ImGuiCol_ButtonHovered] = ImColor(41, 40, 41, 255);

	style->Colors[ImGuiCol_Separator] = ImColor(70, 70, 70, 255);
	style->Colors[ImGuiCol_SeparatorActive] = ImColor(76, 76, 76, 255);
	style->Colors[ImGuiCol_SeparatorHovered] = ImColor(76, 76, 76, 255);

	style->Colors[ImGuiCol_FrameBg] = ImColor(37, 36, 37, 255);
	style->Colors[ImGuiCol_FrameBgActive] = ImColor(37, 36, 37, 255);
	style->Colors[ImGuiCol_FrameBgHovered] = ImColor(37, 36, 37, 255);

	style->Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_HeaderHovered] = ImColor(46, 46, 46, 255);

	style->Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
}