#include "WarCraft.h"

BOOL GameCheck()
{
	// ( 0 : 로딩 , 1 : 결과창 ,  2 : 대기실 ,  4 : 게임중 )
	return *(DWORD *)(DllBase + 0xAB5738) == 4;
}

DWORD WarCraftVersion()
{
	char* buffer = NULL;
	DWORD infoSize = GetFileVersionInfoSizeA("game.dll", 0);

	buffer = new char[infoSize];

	if (buffer)
	{
		if (GetFileVersionInfoA("game.dll", 0, infoSize, buffer) != 0)
		{
			VS_FIXEDFILEINFO* pFileInfo = NULL;
			UINT bufLen = 0;

			if (VerQueryValueA(buffer, "\\", (LPVOID *)&pFileInfo, &bufLen) != 0)
			{
				WORD majorVer, minorVer, revisionNum;
				majorVer = HIWORD(pFileInfo->dwFileVersionMS);
				minorVer = LOWORD(pFileInfo->dwFileVersionMS);
				revisionNum = LOWORD(pFileInfo->dwFileVersionLS);

				return ((majorVer * 1000) + (minorVer * 100) + (revisionNum)); // 10001
			}

		}
	}

}

VOID PrintText(CHAR *Text)
{
	DWORD Class = DllBase + 0xAB4F80;
	DWORD Screen = DllBase + 0x2F8E40;
	DWORD dwColor = 0xFFFFFFFF;

	__asm
	{
		push dwColor;
		push 0x40000000;
		push Text;
		push 0x0;
		push 0x0;
		mov ecx, [Class];
		mov ecx, [ecx];
		CALL Screen;
	}
}
