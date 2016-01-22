#include "WarCraft.h"

void HotKeyRoutine()
{
	BOOL count = TRUE;
	while (true)
	{
		if (GameCheck() && count)
		{
			
			Sleep(1000); 
			WarCraftPrintText("|CFFFAFF21blog.naver.com/cheatreal|R");
			unitMapSet();
			count = FALSE;
		}
		else if (!GameCheck() && !count)
		{
			count = TRUE;
		}

		if (GetAsyncKeyState(ON))
		{
			unitHook();
			WarCraftPrintText("|CFFFAFF21Status : |R   |CFFFF0000ON|R");
			while (GetAsyncKeyState(ON))
				Sleep(100);

		}

		if (GetAsyncKeyState(VIEW))
		{
			unitMapView();
			while (GetAsyncKeyState(VIEW))
				Sleep(100);

		}
	}

}

