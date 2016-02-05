#include "WarCraft.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		freopen("CONOUT$", "wt", stdout);
		HANDLE hInjectionThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HotKeyRoutine, NULL, 0, NULL);
	}
	return TRUE;
}

