#include "WarCraft.h"

mixunit::mixunit(char* unitName, DWORD count, ...)
	: unitName(unitName), count(count)
{
	unit_table = new DWORD64[count];
	va_list list;
	va_start(list, count);
	for (DWORD i = 0; i < count; i++)
	{
		DWORD64 name = va_arg(list, DWORD64);
		DWORD   num = va_arg(list, INT);
		unit_table[i] = name;
		mixunit::mixmap[name] = num;
	}
	va_end(list);
}

void mixunit::view()
{
	for (DWORD i = 0; i < count; i++)
	{
		printf("%d \n", mixunit::mixmap[unit_table[i]]);
	}
}

char * mixunit::getUnitName()
{
	return unitName;
}

DWORD mixunit::getCost()
{
	DWORD cost = 0;
	for (DWORD i = 0; i < count; i++)
	{
		int subResult = 0;
		
		switch (checkUnitType(unit_table[i]))
		{
		case 1: // Normal

			subResult = (mixmap[unit_table[i]] - getNormalValue(unit_table[i]));
			if (subResult > 0)
			{
				cost += (1 * subResult);
			}
			break;
		case 2: // Magic
			subResult = (mixmap[unit_table[i]] - getMagicValue(unit_table[i]));
			if (subResult > 0)
			{
				cost += (2 * subResult);
			}
			break;
		default:
			break;
		}
		
	}
	return cost;
}
