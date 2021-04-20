#include <d3d9.h>
#include <d3dx9.h>
#pragma optimize("", off)



namespace LocalPlayer {
	extern DWORD			getLocalPlayer();												//Get the local player base address
	extern int				getLocalFlags();												//Get the local player flags
	extern int				getLocalHealth();												//Get the local player health
	extern int				getLocalCrossID();												//Get the local player crosshair ID
	extern int				getLocalTeam();													//Get the local player team ID
	extern D3DXVECTOR3		getLocalPos();													//Get the local player pos
	extern void				WriteFlashDuration();
	extern D3DXMATRIX		getLocalViewMatrix();											//Get the view matrix
	extern D3DXVECTOR3		getLocalViewAngles();											//Get the local player view angles
	extern D3DXVECTOR3		getLocalPunchAngles();											//Get the local player punch angles (recoil)

																							//Void functions 
	extern void				forceJump(int waitTime = 35);									//Force the local player to jump
	extern void				forceattack();
	extern void				setLocalPlayer();												//Set the local player base address
	extern void				setLocalViewAngles(D3DXVECTOR3 angles);							//Set the local player view angles

	extern DWORD			LocalBaseaddress;

	// Literally just junk below this lmao

	extern void				JunkCJKI998DKNX900898();
	extern void				JUNKFDSFISFSIFNSKv();
	extern void				JUNKVJFHUSFALVDSADJSAV();
	extern void				JunkFDSIHFSDJKFNSJFNSJK();
	extern void				JUNKJKISDHFSFJSNJKVNJKJKDHUASDHJSAJKD();
	extern void				JUNKSADAUUHDJKFLDSHJVNUASHDUISADWA();
	extern void				JUNKFDSLITERALDFJSKJVLNMKLCDSL();
	extern void				JUNKFDSFDSFSFVXZCKJVLNMKLCDSL();
	extern void				JUNKFdsADSADASCVSDVDSVSDSL();
	extern void				JUNKFhfghgfhfghfSKJVLNMKLCDSL();
	extern void				JUNKFJKHJKBVJLMNVLNMKLCDSL();
	extern void				JUNKFDSLIDQHJKHJVKLHULSAKLSL();
};