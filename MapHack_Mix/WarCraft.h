#pragma once
#pragma comment(lib,"version.lib")

#include <Windows.h>
#include <stdio.h>
// 게임시작?
// 버전확인
// 화면출력
#include "MapHack.h"
#include "HotKey.h"
#include "PatchDll.h"

const DWORD DllBase = (DWORD)GetModuleHandleA("Game.dll");
const HWND  hWnd = FindWindowA("Warcraft III", NULL);

BOOL GameCheck();
DWORD WarCraftVersion();
VOID PrintText(CHAR * text);