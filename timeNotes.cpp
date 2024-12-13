#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
	//time in seconds since jan 1st, 1970
	int currTime = time(0);//take input 1 number: is the number of seconds into the future , returns that future time
	cout << currTime <<endl; //time since 170 jan 1st in seconds

	/*                            VALIDATING INPUT NOTES								  	*/					
	
	int a;
	cout << "enter a number: ";  
	cin >> a;
	cout << "Your number was: " << a << endl;

	// short short: 000 if integer overflow: number goes back to 0
	// if 3 bits, 8 is stored as 000


	/*                            CIN's FAIL PROPERTIES !!!!!!!!!!!!!                       */
	int x;
	int y;
	string theRestOfInputBuffer;
	cout << "type 2 nums seperated by a space: ";
	cin >> x >> y; 	//if inputted data type doesnt not match data type that cin is assigning to, cin raises an internal flag
	
		
	//// cin.fail();//asks if flag was raised, evals to bool
	//cin >> theRestOfInputBuffer; // stores the flagged cin input in theRestOfInputBuffer
	//cout << "The incorrect input: " << theRestOfInputBuffer << endl;
	while (cin.fail()) {
		//cin >> theRestOfInputBuffer; // stores the flagged cin input in theRestOfInputBuffer
		//cout << "The incorrect input: " << theRestOfInputBuffer << endl;

		cout << "you did not type an int. Try again: " << endl;
		cin.clear(); // clears memory in cin containing the raised error, or resetting the fail() flag
		cin.ignore(10 - 0000, '\n'); //resetting terminal so they can try again? w/o it cuases an infinite loop
		cin >> x >> y;

		/* USER	vALIDATION FUNCTS to STUDY: !!!!!
		getline()
		cin.get()
		cin.peek()
		cin.fail()
		cin.ignore()
		cin.clear()
		*/

	}
	cout << x << " " << y << endl;

	

	

	return 0;

}