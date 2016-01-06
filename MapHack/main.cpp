#include "Patch.h"
#include <conio.h>

#pragma warning(disable:4996)

DWORD main()
{
	HANDLE hProc;
	DWORD DllBase = 0;
	DWORD pid = 0;
	Patch wc3("war3.exe", "game.dll");
	
	pid = wc3.GetProcessId();
	if (pid == 0)
	{
		std::cout << "War3 못찾음 빼애애액" << std::endl;
		return 0;
	}

	DllBase = wc3.GetDllBase(pid);
	if (DllBase == 0)
	{
		std::cout << "Dll 빼애애애액" << std::endl;
		return 0;
	}

	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (hProc)
	{
		std::cout << "프로세스 빼애애액" << std::endl;
	}
	/*
		Game.dll+3a159b
		Game.dll+3a14bc
	*/
	if (wc3.PatchCode(hProc, DllBase, 0x3a159b, "\x90", 2) &&
		wc3.PatchCode(hProc, DllBase, 0x3a14bc, "\x90", 2))
	{
		std::cout << "패치 성공" << std::endl;
	}
	getch();
}