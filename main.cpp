#include "includes.h"
#include <ctime>
#include <random>
#include <Windows.h>


inline std::string const BoolToString(bool b)
{
	return b ? "True" : "False";
}

std::string random_string(const int len) {
	const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str) {
		it = alpha_numeric[distribution(generator)];
	}

	return str;
}


int main() 
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	SetConsoleTitle(random_string(30).c_str());
	init();
	DiscordRequests Discord;
	LocalPlayer::setLocalPlayer();
	Discord.WebhookSendMessage(GlobalState::webhook, "[*] Forsaken initialized");
	while (!GetAsyncKeyState(VK_END))
	{
		if (GetKeyState(VK_F2) & 0x8000) 
		{
			GlobalState::bhopenable = !GlobalState::bhopenable;
			Discord.WebhookSendMessage(GlobalState::webhook, std::string("[*] Bhop Enabled: ") += BoolToString(GlobalState::bhopenable));
		}
		else if (GetKeyState(VK_F7) & 0x8000) 
		{
			GlobalState::triggerbotenable = !GlobalState::triggerbotenable;
			Discord.WebhookSendMessage(GlobalState::webhook, std::string("[*] Triggerbot Enabled: ") += BoolToString(GlobalState::triggerbotenable));
		}
		else if (GetKeyState(VK_F8) & 0x8000) 
		{
			GlobalState::glowespenable = !GlobalState::glowespenable;
			Discord.WebhookSendMessage(GlobalState::webhook, std::string("[*] GlowESP Enabled: ") += BoolToString(GlobalState::glowespenable));
		}
		else if (GetKeyState(VK_F6) & 0x8000) {
			GlobalState::noflash = !GlobalState::noflash;
			Discord.WebhookSendMessage(GlobalState::webhook, std::string("[*] NoFlash Enabled: ") += BoolToString(GlobalState::noflash));
		}

		if (GlobalState::bhopenable)
		{
			Cheat::bhop();
		}
		if (GlobalState::triggerbotenable)
		{
			Cheat::triggerbot();
		}
		if (GlobalState::glowespenable) 
		{
			Cheat::LoopGlowESP();
		}
		if (GlobalState::noflash)
		{
			Cheat::NoFlash();
		}
		LocalPlayer::setLocalPlayer();
	}
	Discord.WebhookSendMessage(GlobalState::webhook, "Forsaken exiting...");
	CloseHandle(hProc);
	return 0;
}


bool WINAPI Dllmain()