#include <iostream>

// A using direktivakat es deklaraciokat mindig
// irjuk elore a felreertesek elkerulese vegett.
// Az illusztracio kedveert itt kicsit szet lesznek
// szorva.

using std::cout;
// Innentol a cout kvalifikalatlan nevvel is elerheto
// (vagyis siman cout neven)

void helloWorld()
{
	// endl-hez meg kell a nevtermegjeloles
	cout << "Hello World!" << std::endl;
}

using namespace std;
// std valamennyi tagja elerheto kvalifikalatlanul

void helloNamespaces()
{
	cout << "Hello Namespaces!" << endl;
}

int main()
{
	helloWorld();
	helloNamespaces();
}
