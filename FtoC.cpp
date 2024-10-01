#include <iostream>
using namespace std;

int main() {
	double temp;
	//prompt user to type a temp in F
	cout << "Temp in F: ";
	cin >> temp;
	//output in c
	cout << "Temp in C: " << (temp-32)*5/9;
	return 0;
}