
const int FOO = 5;
const float BAR = 7;

const char *string1 = "shibe";
const char * const CONSTANT_STRING = "wow";

void mutate(int *val);
void use(int val);
void read(const int *val);

int main()
{
	// hiba:
	FOO = 3;
	// hiba:
	BAR = 3;
	
	int a = 11;
	
	// OK:
	mutate(&a);
	// hiba:
	mutate(&FOO);
	
	// OK:
	use(a);
	// OK, mert ekkor masolja:
	use(FOO);
	
	// OK:
	read(&a);
	// OK:
	read(&FOO);
	
	// OK:
	string1 = "such";
	// hiba:
	CONSTANT_STRING = "many";
	
	// hiba:
	string1[0] = 0;
	// hiba:
	CONSTANT_STRING[0] = 0;
	
	return 0;
}
