
extern "C" int foo(const char *s);
void bar(int x);

int quux()
{
	return -1;
}

extern "C" int corge()
{
	return -1;
}

int main()
{
	foo("xyz");
	bar(-1);
	
	return 0;
}
