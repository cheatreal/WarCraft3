#include "Patch.h"
#include <conio.h>

#pragma warning(disable:4996)

DWORD main()
{
	HANDLE hProc = 0;
	DWORD DllBase = 0;
	DWORD pid = 0;
	float Input = 0;
	Patch wc3("war3.exe", "game.dll");
	
	pid = wc3.GetProcessId();
	if (pid == 0)
	{
		std::cout << "Error GetProcessId" << std::endl;
		return 0;
	}
	std::cout << "PID : " << pid << std::endl;

	DllBase = wc3.GetDllBase(pid);
	if (DllBase == 0)
	{
		std::cout << "Error GetDllBase" << std::endl;
		return 0;
	}
	std::cout << "DLL Base Addr : " << DllBase << std::endl;

	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (!hProc)
	{
		std::cout << "Error OpenProcess" << std::endl;
	}

	
	if ((
		// MainMap
		wc3.PatchCode(hProc, DllBase, 0x3a159b, "\x90\x90", 2)
		&&
		// MiniMap
		wc3.PatchCode(hProc, DllBase, 0x36143C, "\x00", 1)
		&&
		// Illusion
		wc3.PatchCode(hProc, DllBase, 0x282A5C, "\x40\xc3", 2)

	))
		 
	{
		std::cout << "Success Patch" << std::endl;
	}

	getch();
} 
