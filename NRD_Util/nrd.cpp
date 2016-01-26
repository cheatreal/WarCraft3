#include "WarCraft.h"

//map<DWORD64, tuple<DWORD, DWORD >> normal;

map<DWORD64, tuple<DWORD, DWORD>> normal;
map<DWORD64, tuple<DWORD, DWORD>> magic;

DWORD64 normal_table[9] = { NARUTO, YAMATO, SAKURA, KABUTO, SASORI, SASUKE, KARIN,AMBU, SAI };
char normal_name[9][9] = { "naruto", "yamto", "sakura", "kabuto", "sasori", "sasuke", "karin", "ambu", "sai" };
DWORD64 normal_offset_table[2] = { 0xd, 0xa };

DWORD64 magic_table[8] = { JIRAIYA, TSUNADE, OROCHIMARU, JUUGO, TEMARI, ZETSU,SASUKE1, CHOUJI };
char magic_name[8][14] = { "JIRAIYA", "TSUNADE", "OROCHIMARU", "JUUGO", "TEMARI", "ZETSU","SASUKE1", "CHOUJI" };
DWORD64 magic_offset_table[8] = { JIRAIYA_COUNT, TSUNADE_COUNT, OROCHIMARU_COUNT, JUUGO_COUNT, TEMARI_COUNT, ZETSU_COUNT,SASUKE1_COUNT, CHOUJI_COUNT };

DWORD getNormalValue(DWORD64 normal_check)
{
	return get<0>(normal[normal_check]);
}

DWORD getMagicValue(DWORD64 magic_check)
{
	return get<0>(magic[magic_check]);
}

void unitMapView()
{/*
	printf("[  MAP  ]\n");
	for (int i = 0; i < 9; i++)
	{

		printf("%s : %d\n", normal_name[i], get<0>(normal[normal_table[i]]));
	}
	for (int i = 0; i <8; i++)
	{
		printf("%s : %d\n", magic_name[i], get<0>(magic[magic_table[i]]));
	}*/
}

void unitMapDel()
{
	normal.clear();
	magic.clear();
}

void unitMapSet()
{
	for (int i = 0; i < 9; i++)
	{
		if (i < 6)
		{
			normal[normal_table[i]] = make_tuple(0, normal_offset_table[0]);

		}
		else
		{
			normal[normal_table[i]] = make_tuple(0, normal_offset_table[1]);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		magic[magic_table[i]] = make_tuple(0, magic_offset_table[i]);
	}
}

DWORD checkUnitType(DWORD64 checkUnit)
{
	for (int i = 0; i < 9; i++)
	{

		if (checkUnit == normal_table[i])
		{
			return 1;
		}
	}
	for (int i = 0; i < 8; i++)
	{

		if (checkUnit== magic_table[i])
		{
			return 2;
		}
	}
	return -1;
}

DWORD unitCheckGroup(DWORD64 *check)
{
	for (int i = 0; i < 9; i++)
	{

		if (*check == normal_table[i])
		{
			return 1;
		}
	}
	for (int i = 0; i < 8; i++)
	{

		if (*(DWORD64 *)((DWORD)check + 0xa) == magic_table[i])
		{
			return 2;
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
	case 1:
		normal[*check] = make_tuple(atoi((const char*)(*point + get<1>(normal[*check]))), get<1>(normal[*check]));
		break;
	case 2:
		check = (DWORD64 *)((DWORD)check + 0xa);
		magic[*check] = make_tuple(atoi((const char*)(*point + (get<1>(magic[*check])))), get<1>(magic[*check]));
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