#include "WarCraft.h"
void SetTls()
{
	DWORD Data = *(DWORD *)(DllBase + 0xACEB4C);
	DWORD TlsIndex = *(DWORD *)(DllBase + 0xAB7BF4);

	if (TlsIndex)
	{
		DWORD v5 = **(DWORD **)(*(DWORD *)(*(DWORD *)(DllBase + 0xACEB5C) + 4 * Data) + 44);
		TlsSetValue(TlsIndex, *(LPVOID *)(v5 + 520));
	}
}

void __stdcall HotKeyRoutine()
{
	SetTls();
	setUnique();
	setLegendary();
	setHidden();
	unitHook();			
	unitMapSet();
	BOOL count = TRUE;
	char * nrdMapCheck = 0;

	while (true)
	{
		if (GameCheck() && count)
		{
			Sleep(1000);
			nrdMapCheck = strstr(getMapName(), "15-12-20-nrd3.8f-fix3");
			WarCraftPrintText(u8"|CFFFAFF21Status : |R   |CFFFF0000ON|R");
			WarCraftPrintText(u8"|CFFFAFF21blog.naver.com/cheatreal|R");

			count = FALSE;
		}
		else if (!GameCheck() && !count)
		{
			count = TRUE;
		}

		if (nrdMapCheck && GetAsyncKeyState(VIEWUNIQUE))
		{
			createUnique();
			while (GetAsyncKeyState(VIEWUNIQUE))
				Sleep(100);

		}
		if (nrdMapCheck && GetAsyncKeyState(VIEWLEGENDARY))
		{
			createLegendary();
			while (GetAsyncKeyState(VIEWLEGENDARY))
				Sleep(100);

		}
		if (nrdMapCheck && GetAsyncKeyState(VIEWHIDDEN))
		{
			createHidden();
			while (GetAsyncKeyState(VIEWHIDDEN))
				Sleep(100);

		}
		Sleep(100);
	}

}

