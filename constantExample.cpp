#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	const float pi = 3.141592654;
	//impossible to hcange variable by defining at constant during instantiation.
	//isntantiation must also declare the variable value for it to be a constant

	//given height and radius, find volume of cylander
	//volume of a cylinder = pi * r^2 * h
	double r;
	double h;
	cout << "radius of cylinder: ";
	cin >> r;
	cout << "height of cylinder: ";
	cin >> h;
	cout << "volume of cylinder: " << fixed << setprecision(4) << pi * pow(r, 2)* h; //exponent in C++, cna use pow(base, exponent)
	return 0;
	
}