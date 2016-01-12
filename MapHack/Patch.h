#include <Windows.h>
#include <iostream>
#include <Tlhelp32.h>

class Patch 
{
	private:
		char* DllName;
		char* ProcName;

	public:
		Patch(char* ProcName, char* DllName);
		DWORD GetProcessId();
		DWORD GetDllBase(DWORD pid);
		BOOL  PatchCode(HANDLE hProc, DWORD Base, DWORD offset, LPCVOID opcode, DWORD bytes);

}; 
