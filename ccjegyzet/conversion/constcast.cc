#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char backing[256];
	
	const char *cs = backing;
	char *s = const_cast<char*>(cs);
	
	strcpy(s, "Hello World!");
	
	cout << cs << endl;
	
	return 0;
}
