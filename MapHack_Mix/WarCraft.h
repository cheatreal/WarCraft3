#pragma once
#pragma comment(lib,"version.lib")

#include <Windows.h>
#include <stdio.h>
// ���ӽ���?
// ����Ȯ��
// ȭ�����
#include "MapHack.h"
#include "HotKey.h"
#include "PatchDll.h"

const DWORD DllBase = (DWORD)GetModuleHandleA("Game.dll");
const HWND  hWnd = FindWindowA("Warcraft III", NULL);

BOOL GameCheck();
DWORD WarCraftVersion();
VOID PrintText(CHAR * text);