
void foo(int x);
extern const char *bar;

int main()
{
	for(int i=0; i<16; ++i)
		foo(i);
	
	return 0;
}
