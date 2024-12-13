#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	//lundhs algorithm (with strings!)
	string CRN = "4539319503436467";
	cout << "input a 16-dig CRN with no spaces: ";
	getline(cin, CRN);
	int currNum;
	string currPin;
	int sum = 0;

	for (int i = 0; i < CRN.size(); i ++) {
		currNum = CRN.at(i) - '0';  //char num to actual num int
		if (i % 2 == 0) { // if 1st, 3rd, 5th dig etc
			currNum *= 2;
			if (currNum > 9) {
				currNum -= 9;
			}
		}
		sum += currNum;
	}
	if (sum % 10 == 0) {
		cout << "valid" << endl;
	}
	else {
		cout << "not valid"<< endl;
	}

	// away from tangent...
	string email = "katestingle@gmail.com";
	 // can work on both strings and characters, returns -1 if cannot find
	if (email.find("@") != string::npos) { //string::npos is a variable in std lib made for this nonreal pos reason, bc there can be multiple and comparing it is v weird
		cout << "find() succeeded in finding that string" << endl;
	}
	
	//taks: replace 1st instance of 'o' with 'u'
	string greeting = "hello world";
	greeting.at(greeting.find('o')) = 'u';
	cout << greeting << endl;

	//replace(start index, how many characters after, subStr)
	greeting.replace(greeting.find('u'), greeting.find('u') + 1, "o");
	cout << greeting << endl;

	//task: prompt user for email addres
	cin >> email;
	//check if valid email, if has @ sign
	if (email.find('@') != string::npos) {
		//veryify that domain = pcc.edu
		if (email.substr(email.find('@')+1, email.length()-email.find('@')) == "pcc.edu") {
			cout << "Sending email...";
		}
		else {
			cout << "valid but not a pcc email";
		}
	}
	else {
		cout << "not valid, email does not contain @ symbol";
	}
	cout << endl;

	//extremely simple adblocker

	return 0;
}