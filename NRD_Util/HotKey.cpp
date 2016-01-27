#include "WarCraft.h"

void HotKeyRoutine()
{
	BOOL count = TRUE;
	while (true)
	{
		if (GameCheck() && count)
		{
			unitMapDel();
			Sleep(1000); 
			setUnique();
			unitHook();
			printf("Game\n");
			WarCraftPrintText(u8"|CFFFAFF21Status : |R   |CFFFF0000ON|R");
			WarCraftPrintText(u8"|CFFFAFF21blog.naver.com/cheatreal|R");
			unitMapSet();
			count = FALSE;
		}
		else if (!GameCheck() && !count)
		{
			count = TRUE;
		}

		if (!GameCheck() && GetAsyncKeyState(VIEW))
		{
			//keyNormal();
		    createUnique();
			while (GetAsyncKeyState(VIEW))
				Sleep(100);

		}
	}

}

