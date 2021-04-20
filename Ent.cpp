#include "includes.h"
#include "Ent.h"


DWORD Entity::GetEntBase(int index)
{
	return RPM<DWORD>(baseAddress + offsets::dwEntityList + (index * 0x10));
}

DWORD Entity::getEntBase(int index)
{
	return RPM<DWORD>(baseAddress + offsets::dwEntityList + (index * 0x10));
}

int	Entity::getEntHp(DWORD playerBase)
{
	return RPM<int>(playerBase + offsets::m_iHealth);
}

bool Entity::isAlive(DWORD playerBase)
{
	if (getEntHp(playerBase) > 0 && getEntHp(playerBase) <= 100)
		return true;
	return false;
}

int	Entity::getEntTeam(DWORD playerBase)
{
	return RPM<int>(playerBase + offsets::m_iTeamNum);
}

int Entity::getGlowIndex(DWORD playerBase)
{
	return RPM<int>(playerBase + offsets::m_iGlowIndex);
}

DWORD Entity::getGlowObj()
{
	return RPM<DWORD>(baseAddress + offsets::dwGlowObjectManager);
}

bool Entity::isValid(DWORD playerBase)
{
	auto dormant = RPM<bool>(playerBase + offsets::m_bDormant);
	if ((Entity::isAlive(playerBase) && Entity::getEntTeam(playerBase) != 0) && !dormant)
		return true;
	return false;
}

int Entity::GetEntTeam(DWORD playerlist)
{
	return RPM<int>(playerlist + offsets::m_iTeamNum);
}

void Entity::glowEsp(DWORD glowObj, int glowInd, float r, float g, float b, float a)
{
	WPM<float>((glowObj + ((glowInd * 0x38) + 0x4)), r / 255);
	WPM<float>((glowObj + ((glowInd * 0x38) + 0x8)), g / 255);
	WPM<float>((glowObj + ((glowInd * 0x38) + 0xC)), b / 255);
	WPM<float>((glowObj + ((glowInd * 0x38) + 0x10)), a / 255);
	WPM<bool>((glowObj + ((glowInd * 0x38) + 0x24)), true);
	WPM<bool>((glowObj + ((glowInd * 0x38) + 0x25)), false);
}

bool Entity::getSpotted(DWORD playerBase)
{
	return RPM<bool>(playerBase + offsets::m_bSpotted);
}

void Entity::setSpotted(DWORD playerBase, bool val)
{
	WPM<bool>(playerBase + offsets::m_bSpotted, val);
}

D3DXVECTOR3	Entity::getEntPos(DWORD playerBase)
{
	return RPM<D3DXVECTOR3>(playerBase + offsets::m_vecOrigin);
}

char* Entity::getEntName(DWORD playerBase)
{
	return RPM<char*>(playerBase + offsets::m_szCustomName);
}

DWORD Entity::getEntBoneMatrix(DWORD playerBase)
{
	return RPM<DWORD>(playerBase + offsets::m_dwBoneMatrix);
}


bool Entity::getEntDefusing(DWORD playerBase)
{
	return RPM<bool>(playerBase + offsets::m_bIsDefusing);
}

bool Entity::getEntReloading(DWORD playerBase)
{
	return RPM<bool>(playerBase + offsets::m_bInReload);
}

bool Entity::getEntHelmet(DWORD playerBase)
{
	return RPM<bool>(playerBase + offsets::m_bHasHelmet);
}

bool Entity::getEntDefuser(DWORD playerBase)
{
	return RPM<bool>(playerBase + offsets::m_bHasDefuser);
}

bool Entity::getEntImmunity(DWORD playerBase)
{
	return RPM<bool>(playerBase + offsets::m_bGunGameImmunity);
}
