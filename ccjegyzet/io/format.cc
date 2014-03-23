#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const float pi = M_PI;

int main()
{
	const int num = 123456;
	cout << "1. " << hex << num << endl;
	cout << "2. " << dec << num << endl;
	cout << "3. " << oct << num << endl;
	
	cout << "4. |" << pi << "|" << endl;
	cout << "5. |" << setprecision(3) << pi << "| |" << pi << "|" << endl;
	cout << "6. |" << setw(8) << setprecision(3) << pi*10.0f << "| |" << pi << "|" << endl;
	cout << "." << endl;
	// lehet a setw es a setprecision manipulatort hasznalni, ezek ekvivalensek
	// az alabbi hivasokkal:
	cout.precision(5);
	cout.width(12);
	// a width mindenre vonatkozik, nem csak a szamokra
	// de csak egy hivas erejeig
	cout << "." << "|" << endl;
	cout << "7. |" << pi << "|" << endl;
	cout << "8. |" << setw(8) << showpos << pi << "|" << endl;
	cout << "9. |" << setw(8) << noshowpos << pi << "|" << endl;
	
	cout << showbase;
	cout << "10. " << hex << num << endl;
	cout << "11. " << dec << num << endl;
	cout << "12. " << oct << num << endl;
	
	// termeszetesen ugyanilyen neven van manipulator is
	cout << noshowbase;
	
	cout << "13. " << 1.0e15 << endl;
	cout << "14. " << hex << 0xcafe12 << endl;
	
	cout << uppercase;
	
	cout << "15. " << 1.0e15 << endl;
	cout << "16. " << hex << 0xcafe12 << endl;
	
	cout << nouppercase;
	
	cout << "17. " << true << endl;
	
	cout << boolalpha;
	
	cout << "18. " << true << endl;
	
	cout << noboolalpha;
	
	cout << "19. |" << left << setw(8) << pi << "|" << endl;
	cout << "20. |" << setw(8) << pi << "|" << endl;
	cout << "21. |" << internal << showpos << setw(8) << pi << "|" << endl;
	
	return 0;
}
