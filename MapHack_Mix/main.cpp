#include "WarCraft.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved)
{

	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hModule);
			if (WarCraftVersion() == 10001)
			{
				system("explorer http://blog.naver.com/cheatreal");
				HANDLE hInjectionThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HotKeyRoutine, NULL, 0, NULL);
				CloseHandle(hInjectionThread);
			}
	}
	return TRUE;
}
