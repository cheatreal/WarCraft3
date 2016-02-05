#include "WarCraft.h"



bool Hook::cHook(LPCTSTR DllName, LPCSTR FuncName, PROC pFn, PBYTE pBytes)
{
	FARPROC pfnOrg;
	DWORD dwOldProtect, dwAddress;
	BYTE pBuf[5] = { 0xe9, 0, };
	PBYTE pByte;

	// ÈÄÅ· API 
	pfnOrg = (FARPROC)0x6F3CB9A3;
	pByte = (PBYTE)pfnOrg;

	// ÈÄÅ· »óÅÂ
	if (pByte[0] == 0xE9)
		return FALSE;


	// 5¹ÙÀÌÆ® ¼Ó¼º Ãß°¡
	VirtualProtect((LPVOID)pfnOrg, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// ¿øº» ÄÚµå ÀúÀå
	memcpy(pBytes, pfnOrg, 5);

	// JMP ÁÖ¼Ò °è»ê
	dwAddress = (DWORD)pFn - (DWORD)pfnOrg - 5;
	memcpy(&pBuf[1], &dwAddress, 4);

	// JMP ÁÖ¼Ò ÆÐÄ¡
	memcpy(pfnOrg, pBuf, 5);

	// ¸Þ¸ð¸® ¼Ó¼º º¹¿ø
	VirtualProtect((LPVOID)pfnOrg, 5, dwOldProtect, &dwOldProtect);

	return TRUE;
}

bool Hook::UncHook(LPCTSTR DllName, LPCSTR FuncName, PBYTE pBytes)
{
	FARPROC pFunc;
	DWORD dwOldProtect;

	// ¾ðÈÅ API
	pFunc = GetProcAddress(GetModuleHandle(DllName), FuncName);


	// 5¹ÙÀÌÆ® ¼Ó¼º Ãß°¡
	VirtualProtect((LPVOID)pFunc, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// ¿øº» ÄÚµå ÆÐÄ¡
	memcpy(pFunc, pBytes, 5);

	// ¸Þ¸ð¸® ¼Ó¼º º¹¿ø
	VirtualProtect((LPVOID)pFunc, 5, dwOldProtect, &dwOldProtect);

	return TRUE;
}

bool Hook::AddrHook(DWORD Addr, PROC pFn)
{
	FARPROC pfnOrg;
	DWORD dwOldProtect, dwAddress;
	BYTE pBuf[5] = { 0xe9, 0, };
	PBYTE pByte;
	// ÈÄÅ· API 
	pfnOrg = (FARPROC)Addr;
	pByte = (PBYTE)pfnOrg;

	// ÈÄÅ· »óÅÂ
	if (pByte[0] == 0xE9)
		return FALSE;

	// 5¹ÙÀÌÆ® ¼Ó¼º Ãß°¡
	VirtualProtect((LPVOID)pfnOrg, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// JMP ÁÖ¼Ò °è»ê
	dwAddress = (DWORD)pFn - (DWORD)pfnOrg - 5;
	memcpy(&pBuf[1], &dwAddress, 4);

	// JMP ÁÖ¼Ò ÆÐÄ¡
	memcpy(pfnOrg, pBuf, 5);

	// ¸Þ¸ð¸® ¼Ó¼º º¹¿ø
	VirtualProtect((LPVOID)pfnOrg, 5, dwOldProtect, &dwOldProtect);

	return TRUE;
}