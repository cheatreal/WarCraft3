#pragma once
char * getNormalName(DWORD64 normal_check);
char * getMagicName(DWORD64 magic_check);
DWORD getMagicValue(DWORD64 normal_check);
DWORD getNormalValue(DWORD64 normal_check);
DWORD checkUnitType(DWORD64 checkUnit);
DWORD unitCheckGroup(DWORD64 *check);
void unitNormalMagic(DWORD * point);
void unitHook();
void unitMapView();
void unitMapDel();
void unitMapSet();

