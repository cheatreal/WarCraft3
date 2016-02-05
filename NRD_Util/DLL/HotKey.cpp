#include "WarCraft.h"

void HotKeyRoutine()
{
	BOOL count = TRUE;
	char * nrdMapCheck = 0;
	while (true)
	{
		printf("%d\n", *(DWORD *)(DllBase + 0xAB5738));
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
			count = TRUE;
		}

		if ((GameCheck()  || inGameCheck()) && nrdMapCheck && GetAsyncKeyState(VIEW))
		{
			//keyNormal();
			createUnique();
			while (GetAsyncKeyState(VIEW))
				Sleep(100);

		}
	}

}

