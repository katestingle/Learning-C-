#include <iostream>
#include <string>
using namespace std;

// functions!!!!!!!!!

//returning function returns obect of type [type], that the functions is DECLARED as
string toLowerCase(string userString) {
	string lower = "";
	for (char c : userString) {
		if (c >= 'A' && c <= 'Z') { //uper case characters
			c = c + 32;//to lowercase
		}
		lower += c;
	}
	return lower;
}

//void!
void say(string argument) { //function declaration and definition, with argument of type string called "argument"
	cout << argument << endl;
}

//delcaration fo a function, but no definition example
char findLast(string}

int main() {
	string userString;
	cout << "Enter a String: ";
	getline(cin, userString);
	//call a return object function
	//in this cas,e our function is declared and defined as type string, meaning that it will return an object of type string
	//the string LITERAL is of type string, is a string object, and contains all of the properties that a string contains
	cout << "\"" << userString << "\" in all lowercase is: " << toLowerCase(userString) << endl;
	//call a void function
	say("Hi!");
	cout << findLast(userString);
	return 0;
}

//define the function after main. can be referenced before in file as long as declared earlier
char findLast(string myString) {
	if (myString.length() > 0) {
		return myString.at(myString.length() - 1);
	}
	else {
		return ' ';
	}
}

