#include "WarCraft.h"



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


