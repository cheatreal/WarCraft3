#include "WarCraft.h"

void keyNormal()
{

	keybd_event(VK_RETURN, 0, 0, 0);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_SUBTRACT, 0, 0, 0);
	keybd_event(VK_SUBTRACT, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(0x53, 0, 0, 0);
	keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(0x48, 0, 0, 0);
	keybd_event(0x48, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(0x41, 0, 0, 0);
	keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(0x4b, 0, 0, 0);
	keybd_event(0x4b, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(0x46, 0, 0, 0);
	keybd_event(0x46, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_RETURN, 0, 0, 0);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

}