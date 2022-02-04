#include <Windows.h>
#include <thread>
#include "clicker.h"
#include "settings.h"

void clicker::checkKeybind(int n)
{
	if (n == 'L')
	{
		if (GetKeyState(VK_XBUTTON1) & 0x8000)
		{
			Settings::leftKeyBind = VK_XBUTTON1;
			Settings::leftStateEnglish = "Keybind set to XButton1";
		}

		else if (GetKeyState(VK_XBUTTON2) & 0x8000)
		{
			Settings::leftKeyBind = VK_XBUTTON2;
			Settings::leftStateEnglish = "Keybind set to XButton2";
		}

		else if (GetKeyState(VK_LBUTTON) & 0x8000)
		{
			Settings::leftKeyBind = VK_LBUTTON;
			Settings::leftStateEnglish = "Keybind set to Left Click";
		}

		else if (GetKeyState(VK_RBUTTON) & 0x8000)
		{
			Settings::leftKeyBind = VK_RBUTTON;
			Settings::leftStateEnglish = "Keybind set to Right Click";
		}

		else if (GetKeyState('Q') & 0x8000)
		{
			Settings::leftKeyBind = 'Q';
			Settings::leftStateEnglish = "Keybind set to Q";
		}

		else if (GetKeyState('W') & 0x8000)
		{
			Settings::leftKeyBind = 'W';
			Settings::leftStateEnglish = "Keybind set to Q";
		}

		else if (GetKeyState('E') & 0x8000)
		{
			Settings::leftKeyBind = 'E';
			Settings::leftStateEnglish = "Keybind set to E";
		}

		else if (GetKeyState('R') & 0x8000)
		{
			Settings::leftKeyBind = 'R';
			Settings::leftStateEnglish = "Keybind set to R";
		}

		else if (GetKeyState('T') & 0x8000)
		{
			Settings::leftKeyBind = 'T';
			Settings::leftStateEnglish = "Keybind set to T";
		}

		else if (GetKeyState('Z') & 0x8000)
		{
			Settings::leftKeyBind = 'Z';
			Settings::leftStateEnglish = "Keybind set to Z";
		}

		else if (GetKeyState('U') & 0x8000)
		{
			Settings::leftKeyBind = 'U';
			Settings::leftStateEnglish = "Keybind set to U";
		}

		else if (GetKeyState('I') & 0x8000)
		{
			Settings::leftKeyBind = 'I';
			Settings::leftStateEnglish = "Keybind set to I";
		}

		else if (GetKeyState('O') & 0x8000)
		{
			Settings::leftKeyBind = 'O';
			Settings::leftStateEnglish = "Keybind set to O";
		}

		else if (GetKeyState('P') & 0x8000)
		{
			Settings::leftKeyBind = 'P';
			Settings::leftStateEnglish = "Keybind set to P";
		}

		else if (GetKeyState('Ü') & 0x8000)
		{
			Settings::leftKeyBind = 'Ü';
			Settings::leftStateEnglish = "Keybind set to Ü";
		}

		else if (GetKeyState('A') & 0x8000)
		{
			Settings::leftKeyBind = 'A';
			Settings::leftStateEnglish = "Keybind set to A";
		}

		else if (GetKeyState('S') & 0x8000)
		{
			Settings::leftKeyBind = 'S';
			Settings::leftStateEnglish = "Keybind set to S";
		}

		else if (GetKeyState('D') & 0x8000)
		{
			Settings::leftKeyBind = 'D';
			Settings::leftStateEnglish = "Keybind set to D";
		}

		else if (GetKeyState('F') & 0x8000)
		{
			Settings::leftKeyBind = 'F';
			Settings::leftStateEnglish = "Keybind set to F";
		}

		else if (GetKeyState('G') & 0x8000)
		{
			Settings::leftKeyBind = 'G';
			Settings::leftStateEnglish = "Keybind set to G";
		}

		else if (GetKeyState('H') & 0x8000)
		{
			Settings::leftKeyBind = 'H';
			Settings::leftStateEnglish = "Keybind set to H";
		}

		else if (GetKeyState('J') & 0x8000)
		{
			Settings::leftKeyBind = 'J';
			Settings::leftStateEnglish = "Keybind set to J";
		}

		else if (GetKeyState('K') & 0x8000)
		{
			Settings::leftKeyBind = 'K';
			Settings::leftStateEnglish = "Keybind set to K";
		}

		else if (GetKeyState('L') & 0x8000)
		{
			Settings::leftKeyBind = 'L';
			Settings::leftStateEnglish = "Keybind set to L";
		}

		else if (GetKeyState('Ö') & 0x8000)
		{
			Settings::leftKeyBind = 'Ö';
			Settings::leftStateEnglish = "Keybind set to Ö";
		}

		else if (GetKeyState('Ä') & 0x8000)
		{
			Settings::leftKeyBind = 'Ä';
			Settings::leftStateEnglish = "Keybind set to Ä";
		}

		else if (GetKeyState('Y') & 0x8000)
		{
			Settings::leftKeyBind = 'Y';
			Settings::leftStateEnglish = "Keybind set to Y";
		}

		else if (GetKeyState('X') & 0x8000)
		{
			Settings::leftKeyBind = 'X';
			Settings::leftStateEnglish = "Keybind set to X";
		}

		else if (GetKeyState('C') & 0x8000)
		{
			Settings::leftKeyBind = 'C';
			Settings::leftStateEnglish = "Keybind set to C";
		}

		else if (GetKeyState('V') & 0x8000)
		{
			Settings::leftKeyBind = 'V';
			Settings::leftStateEnglish = "Keybind set to V";
		}

		else if (GetKeyState('B') & 0x8000)
		{
			Settings::leftKeyBind = 'B';
			Settings::leftStateEnglish = "Keybind set to B";
		}

		else if (GetKeyState('N') & 0x8000)
		{
			Settings::leftKeyBind = 'N';
			Settings::leftStateEnglish = "Keybind set to N";
		}

		else if (GetKeyState('M') & 0x8000)
		{
			Settings::leftKeyBind = 'M';
			Settings::leftStateEnglish = "Keybind set to M";
		}
	}
	else if (n == 'R')
	{
		if (GetKeyState(VK_XBUTTON1) & 0x8000)
		{
			Settings::rightKeyBind = VK_XBUTTON1;
			Settings::rightStateEnglish = "Keybind set to XButton1";
		}

		else if (GetKeyState(VK_XBUTTON2) & 0x8000)
		{
			Settings::rightKeyBind = VK_XBUTTON2;
			Settings::rightStateEnglish = "Keybind set to XButton2";
		}

		else if (GetKeyState(VK_LBUTTON) & 0x8000)
		{
			Settings::rightKeyBind = VK_LBUTTON;
			Settings::rightStateEnglish = "Keybind set to left Click";
		}

		else if (GetKeyState(VK_RBUTTON) & 0x8000)
		{
			Settings::rightKeyBind = VK_RBUTTON;
			Settings::rightStateEnglish = "Keybind set to Right Click";
		}

		else if (GetKeyState('Q') & 0x8000)
		{
			Settings::rightKeyBind = 'Q';
			Settings::rightStateEnglish = "Keybind set to Q";
		}

		else if (GetKeyState('W') & 0x8000)
		{
			Settings::rightKeyBind = 'W';
			Settings::rightStateEnglish = "Keybind set to Q";
		}

		else if (GetKeyState('E') & 0x8000)
		{
			Settings::rightKeyBind = 'E';
			Settings::rightStateEnglish = "Keybind set to E";
		}

		else if (GetKeyState('R') & 0x8000)
		{
			Settings::rightKeyBind = 'R';
			Settings::rightStateEnglish = "Keybind set to R";
		}

		else if (GetKeyState('T') & 0x8000)
		{
			Settings::rightKeyBind = 'T';
			Settings::rightStateEnglish = "Keybind set to T";
		}

		else if (GetKeyState('Z') & 0x8000)
		{
			Settings::rightKeyBind = 'Z';
			Settings::rightStateEnglish = "Keybind set to Z";
		}

		else if (GetKeyState('U') & 0x8000)
		{
			Settings::rightKeyBind = 'U';
			Settings::rightStateEnglish = "Keybind set to U";
		}

		else if (GetKeyState('I') & 0x8000)
		{
			Settings::rightKeyBind = 'I';
			Settings::rightStateEnglish = "Keybind set to I";
		}

		else if (GetKeyState('O') & 0x8000)
		{
			Settings::rightKeyBind = 'O';
			Settings::rightStateEnglish = "Keybind set to O";
		}

		else if (GetKeyState('P') & 0x8000)
		{
			Settings::rightKeyBind = 'P';
			Settings::rightStateEnglish = "Keybind set to P";
		}

		else if (GetKeyState('Ü') & 0x8000)
		{
			Settings::rightKeyBind = 'Ü';
			Settings::rightStateEnglish = "Keybind set to Ü";
		}

		else if (GetKeyState('A') & 0x8000)
		{
			Settings::rightKeyBind = 'A';
			Settings::rightStateEnglish = "Keybind set to A";
		}

		else if (GetKeyState('S') & 0x8000)
		{
			Settings::rightKeyBind = 'S';
			Settings::rightStateEnglish = "Keybind set to S";
		}

		else if (GetKeyState('D') & 0x8000)
		{
			Settings::rightKeyBind = 'D';
			Settings::rightStateEnglish = "Keybind set to D";
		}

		else if (GetKeyState('F') & 0x8000)
		{
			Settings::rightKeyBind = 'F';
			Settings::rightStateEnglish = "Keybind set to F";
		}

		else if (GetKeyState('G') & 0x8000)
		{
			Settings::rightKeyBind = 'G';
			Settings::rightStateEnglish = "Keybind set to G";
		}

		else if (GetKeyState('H') & 0x8000)
		{
			Settings::rightKeyBind = 'H';
			Settings::rightStateEnglish = "Keybind set to H";
		}

		else if (GetKeyState('J') & 0x8000)
		{
			Settings::rightKeyBind = 'J';
			Settings::rightStateEnglish = "Keybind set to J";
		}

		else if (GetKeyState('K') & 0x8000)
		{
			Settings::rightKeyBind = 'K';
			Settings::rightStateEnglish = "Keybind set to K";
		}

		else if (GetKeyState('L') & 0x8000)
		{
			Settings::rightKeyBind = 'L';
			Settings::rightStateEnglish = "Keybind set to L";
		}

		else if (GetKeyState('Ö') & 0x8000)
		{
			Settings::rightKeyBind = 'Ö';
			Settings::rightStateEnglish = "Keybind set to Ö";
		}

		else if (GetKeyState('Ä') & 0x8000)
		{
			Settings::rightKeyBind = 'Ä';
			Settings::rightStateEnglish = "Keybind set to Ä";
		}

		else if (GetKeyState('Y') & 0x8000)
		{
			Settings::rightKeyBind = 'Y';
			Settings::rightStateEnglish = "Keybind set to Y";
		}

		else if (GetKeyState('X') & 0x8000)
		{
			Settings::rightKeyBind = 'X';
			Settings::rightStateEnglish = "Keybind set to X";
		}

		else if (GetKeyState('C') & 0x8000)
		{
			Settings::rightKeyBind = 'C';
			Settings::rightStateEnglish = "Keybind set to C";
		}

		else if (GetKeyState('V') & 0x8000)
		{
			Settings::rightKeyBind = 'V';
			Settings::rightStateEnglish = "Keybind set to V";
		}

		else if (GetKeyState('B') & 0x8000)
		{
			Settings::rightKeyBind = 'B';
			Settings::rightStateEnglish = "Keybind set to B";
		}

		else if (GetKeyState('N') & 0x8000)
		{
			Settings::rightKeyBind = 'N';
			Settings::rightStateEnglish = "Keybind set to N";
		}

		else if (GetKeyState('M') & 0x8000)
		{
			Settings::rightKeyBind = 'M';
			Settings::rightStateEnglish = "Keybind set to M";
		}
	}

	/*for (size_t i = 3; i < 256; i++)
	{
		if (i != 13)
		{
			if (GetAsyncKeyState((i)&SHRT_MAX))
			{
				if (n == 'L')
				{
					Settings::leftKeyBind = i;
					Settings::leftStateEnglish = getbindtext(i).c_str();
					Sleep(200);
				}

				if (n == 'R')
				{
					Settings::rightKeyBind = i;
					Settings::rightStateEnglish = "Keybind set to " + (const char)getbindtext(i).c_str();
				}
			}
		}
	}*/
}

void clicker::main()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)clicker::keybind, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)clicker::left, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)clicker::right, 0, 0, 0);
}

void clicker::left()
{
	while (true)
	{
		if (Settings::leftHold)
		{
			if (Settings::leftClickEnabled && Settings::leftHoldActive)
			{
				click('L');
			}
		}
		else
		{
			if (Settings::leftClickEnabled && (GetKeyState(Settings::leftKeyBind) & 0x8000) != 0)
			{
				click('L');
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void clicker::right()
{
	while (true)
	{
		if (Settings::rightHold)
		{
			if (Settings::rightClickEnabled && Settings::rightHoldActive)
			{
				click('R');
			}
		}
		else
		{
			if (Settings::rightClickEnabled && (GetKeyState(Settings::rightKeyBind) & 0x8000) != 0)
			{
				click('R');
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void clicker::keybind()
{
	while (true)
	{
		if (Settings::leftHold == true && Settings::leftClickEnabled && (GetKeyState(Settings::leftKeyBind) & 0x8000) != 0)
			Settings::leftHoldActive = !Settings::leftHoldActive;

		if (Settings::rightHold == true && Settings::rightClickEnabled && (GetKeyState(Settings::rightKeyBind) & 0x8000) != 0)
			Settings::rightHoldActive = !Settings::rightHoldActive;

		if (Settings::leftStateEnglish == "Press Key")
		{
			Sleep(20);
			checkKeybind('L');
		}
		if (Settings::rightStateEnglish == "Press Key")
		{
			Sleep(20);
			checkKeybind('R');
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void clicker::click(int n)
{
	float cps = 0;
	float clickgrad = 0;

	if (n == 'L')
	{
		cps = Settings::leftClickgrad;
		clickgrad = Settings::leftClickrate;
	}
	else if (n == 'R')
	{
		cps = Settings::rightClickgrad;
		clickgrad = Settings::rightClickrate;
	}

	float clickgrd = (clickgrad * 0.01);
	float e = 1000 / cps;
	float delay = e * clickgrd;
	
	float i = fabs(clickgrd - 1);
	float delay2 = e * i;


	if (n == 'L')
	{
		
		INPUT    Input = { 0 };

		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		::SendInput(1, &Input, sizeof(INPUT));

		Sleep(delay);
		
		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		::SendInput(1, &Input, sizeof(INPUT));

		Sleep(delay2);
	}

	else if (n == 'R')
	{
		INPUT    Input = { 0 };

		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		::SendInput(1, &Input, sizeof(INPUT));

		Sleep(delay);

		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		::SendInput(1, &Input, sizeof(INPUT));

		Sleep(delay2);
	}

}