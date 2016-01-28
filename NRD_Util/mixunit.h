#include <map>
#include <Windows.h>

using namespace std;

class mixunit
{
private:
	// NARUTO , 3
	map<DWORD64, DWORD> mixmap;
	char * unitName;
	DWORD64 *unit_table;
	DWORD *unit_cost;
	DWORD count;

public:
	
	mixunit(char * unitName, DWORD count, ...);
	void view();
	void viewMaterial();
	char *getUnitName();
	DWORD getCost();
};

