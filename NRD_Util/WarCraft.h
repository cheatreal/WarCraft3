﻿#pragma once
#pragma comment(lib,"version.lib")
#pragma warning(disable:4996)

#include <Windows.h>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <process.h>

#include "nrd.h"
#include "HotKey.h"
#include "hook.h"
#include "Normal.h"


using namespace std;



const DWORD DllBase = (DWORD)GetModuleHandleA("Game.dll");
const HWND  hWnd = FindWindowA("Warcraft III", NULL);


DWORD WarCraftVersion();
//what...
inline BOOL GameCheck()
{
	return *(DWORD *)(DllBase + 0xAB5738) == 4;
}
inline VOID WarCraftPrintText(CHAR *Text)
{
	DWORD Class = DllBase + 0xAB4F80;
	DWORD Screen = DllBase + 0x2F8E40;
	DWORD dwColor = 0xFFFFFFFF;

	__asm
	{
		push dwColor;
		push 0x40000000;
		push Text;
		push 0x0;
		push 0x0;
		mov ecx, [Class];
		mov ecx, [ecx];
		CALL Screen;
	}
}