#include "WarCraft.h"

VOID PatchDll(DWORD addr, LPCVOID opcode, DWORD bytes)
{
	DWORD dwOldProtection = NULL;

	VirtualProtect((LPVOID)addr, bytes, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	CopyMemory((LPVOID)addr, opcode, bytes);
	VirtualProtect((LPVOID)addr, bytes, dwOldProtection, NULL);
}