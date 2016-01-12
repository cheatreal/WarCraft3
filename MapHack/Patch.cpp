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
	HANDLE hSnap = 0;
	MODULEENTRY32 xModule = { 0 };
	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	xModule.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnap, &xModule))
	{

		if (lstrcmpi(xModule.szModule, (LPCSTR)Patch::DllName) == 0)
		{
			CloseHandle(hSnap);
			return (DWORD)xModule.modBaseAddr;
		}

		while (Module32Next(hSnap, &xModule))
		{
			if (lstrcmpi(xModule.szModule, (LPCSTR)Patch::DllName) == 0)
			{
				CloseHandle(hSnap);

				return (DWORD)xModule.modBaseAddr;

			}
		}



		CloseHandle(hSnap);

		return 0;
	}
}

BOOL Patch::PatchCode(HANDLE hProc, DWORD Base, DWORD offset,LPCVOID opcode, DWORD bytes)
{
	SIZE_T * result = NULL;

	WriteProcessMemory(hProc, reinterpret_cast<LPVOID>(Base + offset),(LPCVOID)opcode, bytes, result);
	if (result == 0)
	{
		return true;
	}
	return false;
}
