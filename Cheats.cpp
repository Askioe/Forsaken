#include "includes.h"

#define FL_ON_GROUND                     257
#define FL_ON_GROUND_CROUCHED             263
#define FL_IN_AIR_STAND                    256
#define FL_IN_AIR_MOVING_TO_STAND         258
#define FL_ON_GROUND_MOVING_TO_STAND     259
#define FL_IN_AIR_MOVING_TO_CROUCH         260
#define FL_ON_GROUND_MOVING_TO_CROUCH     261
#define FL_IN_AIR_CROUCHED                 262
#define FL_IN_WATER                     1280
#define FL_IN_PUDDLE                     1281
#define FL_IN_WATER_CROUCHED             1286
#define FL_IN_PUDDLE_CROUCHED             1287
#define FL_PARTIALGROUND (1 << 18)

//Team IDs
#define TEAM_ID_GOTV 1
#define TEAM_ID_T 2
#define TEAM_ID_CT 3


void Cheat::bhop()
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && (LocalPlayer::getLocalFlags() == FL_ON_GROUND))
	{
		LocalPlayer::forceJump(35);
	}

}

void Cheat::NoFlash() {
	if (RPM<int>(LocalPlayer::getLocalPlayer() + offsets::m_flFlashDuration) > 0.0f) {
		LocalPlayer::WriteFlashDuration();
	}
}


void Cheat::triggerbot()
{
	if ((GetAsyncKeyState(0x05) & 0x8000))
	{
		auto xhair = LocalPlayer::getLocalCrossID();
		if (xhair > -1)
		{
			auto EnCross = Entity::GetEntBase(xhair - 1);
			if (Entity::GetEntTeam(EnCross) != LocalPlayer::getLocalTeam()) {
				Sleep(50);
				LocalPlayer::forceattack();
				Sleep(10);
			}
		}
	}

}

void Cheat::GlowESP(int idx) 
{
	auto plr = Entity::GetEntBase(idx);
	auto gObj = Entity::getGlowObj();
	auto gIdx = Entity::getGlowIndex(plr);


	if (Entity::GetEntTeam(plr) != LocalPlayer::getLocalTeam() && Entity::isValid(plr))
	{
		Entity::glowEsp(gObj, gIdx, 168, 1, 244, 150);
	}
	else if (Entity::GetEntTeam(plr) == LocalPlayer::getLocalTeam()) {


		Entity::glowEsp(gObj, gIdx, 60, 100, 60, 150);
	}
}

void Cheat::LoopGlowESP() 
{
	for (int i = 0; i <= 32; i++) 
	{
		Cheat::GlowESP(i);
	}
}
