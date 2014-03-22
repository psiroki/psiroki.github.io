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
	cout.precision(5);
	cout.width(12);
	cout << "." << endl;
	// a width mindenre vonatkozik, a "7. |" stringre is
	cout << "7. |" << pi << "|" << endl;
	
	return 0;
}
