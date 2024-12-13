#include <iostream>
using namespace std; //std = standard library, overarching library of c++

//like javascript, ALL USED FUNCTIONS MUST BE DEFINED FIRST BEFORE CALLED
//int nameLength(string name) {
//	return name.length();
//}

int main() {
	//cout << "hello world";
	//cout << nameLength("Kate")<< endl;

	//// implicit casting:
	//int a = 1.5; //assigning val that isn't of type int
	//cout << a << endl; //outputs 1
	//bool b = 1;
	//cout << b; //outputs 1
	//int c = 'C';//assign type char to int, using ascii
	//cout << c << endl; 

	//// explicit casting: 
	//int d = int(1.5); //explcit??, casting it as an int using int() contructer of int type
	//cout << d << endl;
	//int e = 102;
	//char f = static_cast<char>(e); //explicit
	////static_cast< dataTypeCovertTo >(data to convert);, can use to cast a parent class object as a child class object
	//cout << f << endl; //outputs ascii character for e = 102

	//string s = "cool";
	////int h = static_cast<char>(s); not valid bc can't convert string directly to an int
	//char g = s[0]; //gets 0th char in string s 
	//int h = static_cast<char>(g); // can convert type char to int, std knows int to char and char to int conversion using ascii or other conversion method
	//cout << h << endl; //outputs the int val for the 1st character in string s

	////TASK: calculate the average of 3 integers, display the result as its true double
	//int i = 9;
	//int j = 8;
	//int k = 10;
	//double average = (i + j + k) / 3; //IMPLICIT
	//cout << average << endl;

	////2nd TASK: convert a char of a number(0-9) to the int it represents

	//char charNum = '1';
	////cin >> charNum; // input from user as type char. if user inputs more than 1 char, only reads 1st char before the user presses enter
	//int num = static_cast<int>(charNum)-'0' or int num = static_cast<<int>(charNum) - 48; // counting in ascii starts at 48 w/ 0. static_cast for a character returns the ascii int 0-9, and then must -48 to convert to true val
	//cout << num;

	//everything is commented bc vs environmetn was being weird and am too lazy to uncomment all of them bc my uncommment keybnoard shortcut isn't workign for some reason



	return 0;
}
