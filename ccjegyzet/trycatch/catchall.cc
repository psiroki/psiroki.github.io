#include <iostream>

using namespace std;

class A
{
	const char * const message;
public:
	A(const char *message);
	
	const char* getMessage() const;
};

A::A(const char *message): message(message)
{
}

const char* A::getMessage() const
{
	return message;
}

typedef void (*SimpleCall)();

void f1()
{
	throw "Hello World!";
}

void f2()
{
	throw 42;
}

void f3()
{
	throw A("foobar");
}

void t(SimpleCall f)
{
	try
	{
		f();
	}
	catch(const char *s)
	{
		cout << "t caught string: " << s << endl;
		throw s;
	}
	catch(int errorCode)
	{
		cout << "t caught error code: " << errorCode << endl;
	}
	catch(...)
	{
		cout << "t caught something else..." << endl;
		// barmi is volt, dobjuk tovabb
		// igy, ertek nelkul csak catch(...) blokkban szerepelhet
		throw;
	}
}

int main()
{
	SimpleCall calls[] = { f1, f2, f3 };
	int numCalls = sizeof(calls)/sizeof(*calls);
	for(int i=0; i<numCalls; ++i)
	{
		SimpleCall f = calls[i];
		try
		{
			t(f);
		}
		catch(const char *s)
		{
			cout << "main caught string: " << s << endl;
		}
		catch(int errorCode)
		{
			cout << "main caught error code: " << errorCode << endl;
		}
		catch(const A &a)
		{
			cout << "main caught A: " << a.getMessage() << endl;
		}
	}
}
