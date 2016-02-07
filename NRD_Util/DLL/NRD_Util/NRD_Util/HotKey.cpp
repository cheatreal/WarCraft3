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

	BOOL count = TRUE;
	char * nrdMapCheck = 0;

	while (true)
	{
		if (GameCheck() && count)
		{
			unitMapDel();
			Sleep(1000); 
			setUnique();
			unitHook();
			nrdMapCheck = strstr(getMapName(), "15-12-20-nrd3.8f-fix3");
			WarCraftPrintText(u8"|CFFFAFF21Status : |R   |CFFFF0000ON|R");
			WarCraftPrintText(u8"|CFFFAFF21blog.naver.com/cheatreal|R");
			unitMapSet();
			count = FALSE;
		}
		else if (!GameCheck() && !count)
		{
			nrdMapCheck = 0;
			count = TRUE;
		}

		if (nrdMapCheck && GetAsyncKeyState(VIEW))
		{
			//keyNormal();
			createUnique();
			while (GetAsyncKeyState(VIEW))
				Sleep(100);

		}

		Sleep(100);
	}

}

