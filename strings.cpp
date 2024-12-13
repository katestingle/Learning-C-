#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	bool w = 5; //true... why?
	bool x = 2 - 2; // false = 0
	bool y = false || (true && true); //true
	bool z = !(!true || true); //false
	// RAM: random access memory: data readily available at this moment to quickly grab
	string literalString = "this is a string literal";


	string myString = "Hello"; // array of characters as text
	string myString2 = "Hello";
	cout << myString << endl;
	cout << myString.at(0) << endl; // only gets character at 0;

	// same thing as
	char h = 'H';
	char e = 'e';
	char l1 = 'l';
	char l2 = 'l';
	char o = 'o';
	cout << h << e << l1 << l2 << o << endl;

	//indexing
	if (myString == myString2) {
		cout << myString << " is the same as " << myString2 << endl;
	}
	if (myString[0] == myString2.at(0)) { // .at(n) can access a char and CHANGE a char
		cout << "The first char of myString and myString2 are both " << myString[0] << endl;
	}


	//change strings w/ .at(n)
	// myString[0] = "b"; 不好 code
	myString.at(0) = 'B'; //gets address of variable in ra,
	//converts the value at the adress to  the variable

	//size of string!
	int myStringSize = myString.size(); //OR .length()
	cout << myString << " has " << myStringSize << " characters." << endl;

	//add to end of string
	myString.append(" World! ");
	cout << myString << endl;

	//concatenation = combine 2 things together
	myString += myString;
	cout << myString << endl;
	cout << myString + myString2 << endl;

	string inputVar;
	cout << "type anything you want: ";
	getline(cin, inputVar);
	cout << inputVar << endl;

	string first;
	string last;
	cout << "What is your full name (with spaces)? ";
	cin >> first >> last;
	cout << first << "." << last << "@pcc.edu" << endl;

	if (isalpha(myString.at(0))){ //returns boolean, true if a letter a-z or A-Z, fale is otherwise
		cout << isdigit(myString.at(0));
	} //returns boolean, true if a number, false if otherwise

	// find and substring
	// find = get index of the first occurence of some char
	string myString3 = "hello world";
	int indexOfFirst_l = myString3.find('l');
	cout << "The index of the first 'l' in " + myString3 + " is " << myString3.find('l'); // returns -1 if not in string
	// cout << myString3 + myString3.find('l'); // bad code because "+" is only for string concatination, not int
	cout << myString3 + static_cast<char>(myString3.find('l')) << endl; // bad too.... why??

	string email = "kate.stingle@pcc.edu";
	int exc = email.find('!'); //can use for characters
	if (exc == string::npos) { //look inside of std string library for variable called "npos", what we compare to find "did fail or not", tells reader "why fail" "why -1"
		cout << "find() failed to find that string";
	}
	exc = email.find("@pcc.edu"); //can also use for substrings
	if (exc != string::npos) {
		cout << "find() found @pcc.edu in that string" << endl;
	}


	return 0;
}