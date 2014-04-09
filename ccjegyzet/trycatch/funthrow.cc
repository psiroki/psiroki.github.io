#include <iostream>

using namespace std;

int f() throw (int)
{
	throw "foo";
}

void unexpectedHandler()
{
	cout << "unexpected" << endl;
}

int main()
{
	set_unexpected(unexpectedHandler);

	try
	{
		f();
	}
	catch(const char *s)
	{
		cout << s << endl;
	}
	catch(int i)
	{
		cout << i << endl;
	}
	catch(...)
	{
		cout << "Other" << endl;
	}
	
	return 0;
}
