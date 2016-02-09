#include "WarCraft.h"

mixunit::mixunit(char* unitName, DWORD count, ...)
	: unitName(unitName), count(count)
{
	unit_table = new DWORD64[count];
	unit_cost = new DWORD[count];
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

void mixunit::viewMaterial()
{
	DWORD check = 0;
	for (DWORD i = 0; i < count; i++)
	{
		if (unit_cost[i] != 0)
		{
			check++;
			switch (checkUnitType(unit_table[i]))
			{
			case 1:
				WarCraftPrintTextEx(u8"%s : %d마리가 부족합니다.", getNormalName(unit_table[i]), unit_cost[i]);
				break;
			case 2:
				WarCraftPrintTextEx(u8"%s : %d마리가 부족합니다.", getMagicName(unit_table[i]), unit_cost[i]);
				break;
			default:
				break;
			}
		}
	}

	if(check == 0)
	{
		WarCraftPrintTextEx(u8"만들 수 있습니다.");
	}
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
		printf("%d\n", count);
		switch (checkUnitType(unit_table[i]))
		{
		case 1: // Normal

			subResult = (mixmap[unit_table[i]] - getNormalValue(unit_table[i]));
			if (subResult > 0)
			{
				unit_cost[i] = subResult;
				cost += (1 * subResult);
			}
			else
			{
				unit_cost[i] = 0;
			}
			break;
		case 2: // Magic
			subResult = (mixmap[unit_table[i]] - getMagicValue(unit_table[i]));
			if (subResult > 0)
			{
				unit_cost[i] = subResult;
				cost += (2 * subResult);
			}
			else
			{
				unit_cost[i] = 0;
			}
			break;
		default:
			break;
		}
		
	}
	return cost;
}

