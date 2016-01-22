#include "WarCraft.h"

//map<DWORD64, tuple<DWORD, DWORD >> normal;
map<DWORD64, DWORD> normal;

DWORD64 normal_table[9] = { NARUTO, YAMATO, SAKURA, KABUTO, SASORI, SASUKE, KARIN,AMBU, SAI };
char normal_name[9][9] = {"naruto", "yamto", "sakura", "kabuto", "sasori", "sasuke", "karin", "ambu", "sai"};

inline const char * N0(DWORD* point)
{
	return (const char*)(*point + 0xd);
}

inline const char * N1(DWORD* point)
{
	return (const char*)(*point + 0xa);
}

void unitMapView()
{
	printf("[  MAP  ]\n");
	for (int i = 0; i < 9; i++)
	{
		printf("%s : %d\n", normal_name[i], normal[normal_table[i]]);
	}
}

void unitMapDel()
{
	normal.clear();
}

void unitMapSet()
{
	for (int i = 0; i < 9; i++)
	{
			normal[normal_table[i]] = 0;
	}

}

DWORD unitCheckGroup(DWORD64 *check)
{
	for (int i = 0; i < 9; i++)
	{

		if (*check == normal_table[i])
		{
			if (i < 6)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
	return -1;
}

void unitNormalMagic(DWORD *point)
{
	DWORD64 *check;

	point = (DWORD*)((DWORD)point + 0x8);
	point = (DWORD*)((*point) + 0x1c);
	check = (DWORD64 *)*point;

	switch (unitCheckGroup(check))
	{
		case 0:
			normal[*check] = atoi(N0(point));
			break;
		case 1:
			normal[*check] = atoi(N1(point));
			break;
		default:
			return;
	}

	return;
}

__declspec(naked) void unitHookFunc()
{
	
	DWORD *point;
	__asm
	{
		mov eax, [esp + 0x24]
		mov point, eax
		pushad
	}

	unitNormalMagic(point);

	__asm
	{
		popad
		mov eax, point
		push eax
		mov eax, DllBase
		add eax, 0x3cb915
		jmp eax
	}
}

void unitHook()
{
	Hook hc;
	hc.AddrHook(DllBase + 0x3cb910, (PROC)unitHookFunc);
}