#include "hook.h"
#pragma warning(disable:4996)

DWORD base;

DWORD64 normal_table[6] = { 0x86EDA8A3EB9882EB,0x86ED88A7EBBC95EC, 0x9DEBA0BFECAC82EC, 0x86ED80B6EBB4B9EC, 0xA6EB8C86ECAC82EC, 0xBCECA48AECAC82EC };
DWORD64 normal_table2[3] = {0x3A20B0A6EBB4B9EC,0x3A2080B6EB9495EC, 0x3A20B49DECAC82EC };

unsigned char normal_name[6][7] = { "Naruto", "Yamato", "Sakura", "Kabuto", "Sasori", "Sasuke" };
unsigned char normal_name2[3][7] = { "Karin", "Ambu", "Sai" };

void normal(DWORD *point)
{
	DWORD64 *check;

	point = (DWORD*)((DWORD)point + 0x8);
	point = (DWORD*)((*point) + 0x1c);
	check = (DWORD64 *)*point;

	for (int i = 0; i < 6; i++)
	{
		if (normal_table[i] == *check)
		{
			point = (DWORD *)((*point + 0xd));
			printf("%s : %s \n", normal_name[i], point);
			return;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (normal_table2[i] == *check)
		{
			point = (DWORD *)((*point + 0xa));
			printf("%s : %s \n", normal_name2[i], point);
			return;
		}
	}



}
__declspec(naked)  void nrdhook()
{

	DWORD *point;
	__asm
	{	
		mov eax, [esp+0x24]
		mov point, eax
		pushad
	}

	normal(point);

	__asm
	{
		popad
		mov eax, point
		push eax
		mov eax, base
		add eax, 0x3cb915
		jmp eax
	}

}

void Injection()
{
	Hook hc;

	base = (DWORD)GetModuleHandleA("Game.dll");
	printf("DLL Base : %x \n", base);
	hc.AddrHook(base + 0x3cb910 ,(PROC)nrdhook);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		freopen("CONOUT$", "wt", stdout);
		HANDLE hInjectionThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Injection, NULL, 0, NULL);
	}
	return TRUE;
}

