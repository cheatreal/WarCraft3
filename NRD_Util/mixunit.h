#include <map>
#include <Windows.h>

using namespace std;

class mixunit
{
private:
	map<DWORD64, DWORD> mixmap;
	DWORD64 *unit_table;
	DWORD cost = 0;
	DWORD count;
	// normal = 1
	// magic  = 2
public:
	
	mixunit(DWORD count, ...);
	void view();
	DWORD getCost();
};

