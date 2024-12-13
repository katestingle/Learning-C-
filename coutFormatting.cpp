#include <iostream>
#include <iomanip> //manipulation of iostream, can use scientific, fixed setprecision
#include <cstdlib> // library w LOTS of gadgets and gizmos
#include <ctime> //using time
using namespace std;

int main() {
	unsigned seedd = time(0); //gets current time, unsigned is a data type of int. unsigned only contains pos, saves one bit of space
	srand(seedd);// first numebr of binary is frist number, ie the 1st 11000000000000000000000000000000001

	cout << scientific << sqrt(2)<< endl; //fixed = normal for dec point numbers
	cout  << setprecision(2) << sqrt(2) <<endl;
	cout << scientific << setprecision(2) << sqrt(2)<<endl;
		//cout <<default does 6 dec pnt number
		// 
		//will need iomanip module in assignment 2, calculating interest, display just 2 dec points
		// cout << fixed << setprecision(2);
		//money functions exist and can be used for assignment 1 of iomanip lib
	int randInt = rand();//random int between 
	cout << rand()%11 << endl; //random int between 0,9 bc 0 <= a%n > n
	cout << rand() % 11 + 10; //10-20
	//formula for creating a random int number = rand()%range + minimum

	return 0;
}