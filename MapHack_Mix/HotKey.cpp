#include "WarCraft.h"



void HotKeyRoutine()
{
	BOOL count = TRUE;
	while (true)
	{
		if (GameCheck() && count)
		{
			Sleep(1000);
		    PrintText("|CFF21C2FFF2|R           |CFFFFCD21HACK ON|R");
			if (!GetStatus())
			{
				PrintText("|CFFFAFF21HackStatus|R   |CFFFF0000On|R");
			}
			else
			{
				PrintText("|CFFFAFF21HackStatus|R   |CFFFF0000OFF|R");
			}
			count = FALSE;
		}
		else if (!GameCheck() && !count)
		{
			count = TRUE;
		}

		if (GetAsyncKeyState(MAP_HACK))
		{
			MapHack();
			while (GetAsyncKeyState(MAP_HACK))
				Sleep(100);

		}
	}
	
}

