namespace Entity {
	extern DWORD EntityList;
	extern DWORD GetEntBase(int index);
	extern DWORD getEntBase(int index);
	extern int getEntHp(DWORD playerBase);
	extern bool isAlive(DWORD playerBase);
	extern int getEntTeam(DWORD playerBase);
	extern int getGlowIndex(DWORD playerBase);
	extern DWORD getGlowObj();
	extern bool isValid(DWORD playerBase);
	extern int GetEntTeam(DWORD playerlist);
	extern void glowEsp(DWORD glowObj, int glowInd, float r, float g, float b, float a);
	extern bool getSpotted(DWORD playerBase);
	extern void setSpotted(DWORD playerBase, bool val);
	extern D3DXVECTOR3 getEntPos(DWORD playerBase);
	extern char* getEntName(DWORD playerBase);
	extern DWORD getEntBoneMatrix(DWORD playerBase);
	extern bool getEntDefusing(DWORD playerBase);
	extern bool getEntReloading(DWORD playerBase);
	extern bool getEntHelmet(DWORD playerBase);
	extern bool getEntDefuser(DWORD playerBase);
	extern bool getEntImmunity(DWORD playerBase);
}


