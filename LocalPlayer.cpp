#include "includes.h"
#pragma optimize("", off)


DWORD LocalPlayer::LocalBaseaddress = 0;


DWORD LocalPlayer::getLocalPlayer()
{
    return LocalPlayer::LocalBaseaddress;
}

void LocalPlayer::setLocalPlayer()
{
    LocalPlayer::LocalBaseaddress = RPM<DWORD>(baseAddress + offsets::dwLocalPlayer);
}

int LocalPlayer::getLocalFlags()
{
    return RPM<int>(LocalPlayer::getLocalPlayer() + offsets::m_fFlags);
}

int LocalPlayer::getLocalHealth()
{
    return RPM<int>(LocalPlayer::getLocalPlayer() + offsets::m_iHealth);
}

int LocalPlayer::getLocalTeam()
{
    return RPM<int>(LocalPlayer::getLocalPlayer() + offsets::m_iTeamNum);
}

void LocalPlayer::forceJump(int waitTime)
{
    WPM<int>(baseAddress + offsets::dwForceJump, 6);
    Sleep(waitTime);
    WPM<int>(baseAddress + offsets::dwForceJump, 4);
}

void LocalPlayer::forceattack()
{
    WPM<int>(baseAddress + offsets::dwForceAttack, 6);
}


void LocalPlayer::WriteFlashDuration() {
    WPM<int>(LocalPlayer::getLocalPlayer() + offsets::m_flFlashDuration, 0.0f);
}


int LocalPlayer::getLocalCrossID()
{
    auto temp = RPM<int>(LocalPlayer::getLocalPlayer() + offsets::m_iCrosshairId);
    if (temp <= 0 || temp > 32)
        return -1;
    return temp;
}

D3DXVECTOR3 LocalPlayer::getLocalPos()
{
    return RPM<D3DXVECTOR3>(LocalPlayer::getLocalPlayer() + offsets::m_vecOrigin);
}





D3DXMATRIX LocalPlayer::getLocalViewMatrix()
{
    return RPM<D3DXMATRIX>(baseAddress + offsets::dwViewMatrix);
}

D3DXVECTOR3 LocalPlayer::getLocalViewAngles()
{
    return RPM<D3DXVECTOR3>((engineAddress + offsets::dwClientState) + offsets::dwClientState_ViewAngles);
}

void LocalPlayer::setLocalViewAngles(D3DXVECTOR3 angles)
{
    WPM<D3DXVECTOR3>(RPM<DWORD>(engineAddress + offsets::dwClientState) + offsets::dwClientState_ViewAngles, angles);
}

D3DXVECTOR3 LocalPlayer::getLocalPunchAngles()
{
    return RPM<D3DXVECTOR3>(LocalPlayer::getLocalPlayer() + offsets::m_aimPunchAngle);
}


