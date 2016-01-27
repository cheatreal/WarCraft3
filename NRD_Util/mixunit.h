#include <map>
#include <Windows.h>

using namespace std;

class mixunit
{
private:
	map<DWORD64, DWORD> mixmap;
	char * unitName;
	DWORD64 *unit_table;
	DWORD count;

public:
	
	mixunit(char * unitName, DWORD count, ...);
	void view();
	char *getUnitName();
	DWORD getCost();
};

