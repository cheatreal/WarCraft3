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

		if (GetAsyncKeyState(VK_F1))
		{
			system("cls");
			while (GetAsyncKeyState(VK_F1))
				Sleep(100);

		}

		if (GetAsyncKeyState(VIEW))
		{
			setUnique();
			//keyNormal();
			Sleep(200);
			unitMapView();
			while (GetAsyncKeyState(VIEW))
				Sleep(100);

		}
	}

}

