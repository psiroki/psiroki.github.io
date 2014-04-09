#include <iostream>
// bad_exception:
#include <exception>

using namespace std;

int g()
{
	throw "foo";
}

int f() throw (int, bad_exception)
{
	return g();
}

void unexpectedHandler()
{
	cout << "unexpected" << endl;
	// igy lesz belole bad_exception
	throw;
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
	catch(bad_exception e)
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "Other" << endl;
	}
	
	return 0;
}
