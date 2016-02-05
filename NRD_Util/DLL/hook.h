#pragma once


class Hook
{
private:

public:
	bool cHook(LPCTSTR DllName, LPCSTR FuncName, PROC pFn, PBYTE pBytes);
	bool UncHook(LPCTSTR DllName, LPCSTR FuncName, PBYTE pBytes);
	bool AddrHook(DWORD Addr, PROC pFn);
};