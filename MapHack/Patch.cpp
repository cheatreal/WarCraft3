#include "Patch.h"

Patch::Patch(char *ProcName, char *DllName)
	:ProcName(ProcName), DllName(DllName)
{

}

DWORD Patch::GetProcessId()
{
	DWORD dwPID = 0;
	HANDLE hSnapShot = INVALID_HANDLE_VALUE;
	PROCESSENTRY32 pe;

	pe.dwSize = sizeof(PROCESSENTRY32);
	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);

	Process32First(hSnapShot, &pe);
	do
	{
		if (!strcmp(Patch::ProcName, (const char*)pe.szExeFile))
		{
			dwPID = pe.th32ProcessID;
			break;
		}
	} while (Process32Next(hSnapShot, &pe));

	CloseHandle(hSnapShot);

	return dwPID;
}

DWORD Patch::GetDllBase(DWORD pid)
{
	HANDLE hSnapshot = 0;
	MODULEENTRY32 me32;

	if (pid)
	{
		hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
		me32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &me32))
		{
			do
			{
				if (strcmp(DllName, me32.szModule) == 0)
				{
					CloseHandle(hSnapshot);
					return (DWORD)me32.modBaseAddr;
				}
			} while (Module32Next(hSnapshot, &me32));
		}
	}
	CloseHandle(hSnapshot);
	return 0;
}

BOOL Patch::PatchCode(HANDLE hProc, DWORD Base, DWORD offset,LPCVOID opcode, DWORD bytes)
{
	DWORD result;
	WriteProcessMemory(hProc, reinterpret_cast<LPVOID>(Base +  offset), opcode, bytes, &result);
	if (result == 0)
	{
		return false;
	}
	return true;
}
