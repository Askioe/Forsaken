#include "includes.h"

extern DWORD baseAddress;
extern DWORD engineAddress;
extern DWORD clientState;
 extern HANDLE hModuleSnap;


 extern HANDLE hProc;

template<typename T> T RPM(SIZE_T address) 
{
	T buffer;
	ReadProcessMemory(hProc, (LPCVOID)address, &buffer, sizeof(T), NULL);
	return buffer;
}

template<typename T> void WPM(SIZE_T address, T buffer) 
{
	WriteProcessMemory(hProc, (LPVOID)address, &buffer, sizeof(buffer), NULL);
}

//Attaches to process and gives ALL_ACCESS so you can rpm/wpm for your hack
extern bool attatchProc(char* procName);

//Gets the base address of a desired module within the process you've attached to, so you can offsetset from it
extern DWORD getModule(LPSTR moduleName);


extern void init();
