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

extern bool attachProc(char* procName);

extern DWORD getModule(LPSTR moduleName);


extern void init();
