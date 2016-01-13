#include "WarCraft.h"

BOOL OnCheck = TRUE;

VOID MapHack()
{
	if (!GameCheck())
	{
		return;
	}

	if (OnCheck)
	{
		OnCheck = FALSE;

		PatchDll(DllBase + 0x3a159b, "\x90\x90", 2);

		PatchDll(DllBase + 0x36143C, "\x00", 1);

		PatchDll(DllBase + 0x282A5C, "\x40\xC3", 2);

		PatchDll(DllBase + 0x399A98, "\xEB", 1);


		PrintText("|CFFFAFF21Cheat Real|R : |CFFFF0000Hack On|R");
	}
	else
	{
		OnCheck = TRUE;

		PatchDll(DllBase + 0x3a159b, "\x23\xCA", 2);

		PatchDll(DllBase + 0x36143C, "\x01", 1);

		PatchDll(DllBase + 0x282A5C, "\xC3\xCC", 2);

		PatchDll(DllBase + 0x399A98, "\x74", 1);

		PrintText("|CFFFAFF21Cheat Real|R : |CFFFF0000Hack OFF|R");
	}
}

BOOL GetStatus()
{
	return OnCheck;
}