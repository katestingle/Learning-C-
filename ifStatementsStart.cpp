#include <iostream>
#include <string>
using namespace std;

class className {
	int m_Integer = 56;

	int getGrade() {
		return m_Integer;
	}

	className() {
		this->getGrade(); //pointer
		(*this).getGrade(); //reference
	}

	
};

void printGrade(string letterGrade, int grade) {
	cout << "Your grade of " << grade << "%  is a " << letterGrade << endl;
}
int main() {
	//same as java syntax
	if (0 < 9) {
		cout << "0 < 9 is true, so we entered the if \n";
	}
	cout << (5 > 4) << endl; //prints 1, bc when boolean 5 > 4 is evaluated to boolean, it becomes true. When type bool is printed, evals to 1
	int grade;
	cin >> grade;

	if (grade >= 90) {
		printGrade("A", grade);
	} 
	else if (grade >= 80) {
		printGrade("B", grade);
	} 
	else if (grade >= 70) {
		printGrade("C", grade);
	} 
	else if (grade >= 60) {
		printGrade("D", grade);
	}
	else {
		printGrade("F", grade);
	}
	
	int moneyOwned;
	cout << "How much money do you have? Input as whole dollars: ";
	cin >> moneyOwned;
	bool hasPermission = false;
	bool isBusyWithHW = false;

	if (moneyOwned >= 10 && (hasPermission || !isBusyWithHW)) {
		cout << "Youse can go to the movies!!" << endl;
	}
	else {
		cout << "You cannot go to the movies mainly because ";
		if (moneyOwned < 10) {
			cout << "you are broke... ";
		}
		else {
			cout << "you either don't have permission from your parents or are too busy. " << endl;
		}
		cout << "sucks to suck";
	}
	
	int day = 2;

	switch (day) { // switch function includes cases for inputted paramater(s)
	case 1:
		std::cout << "Monday\n";
		break;
	case 2:
		std::cout << "Tuesday\n";
		break;
	case 3:
		std::cout << "Wednesday\n";
		break;
	default: //else
		std::cout << "Invalid day\n";
	}
	//(), then !, then && then ||, reads right to left  - ORDER FO EVALUATION


	
	
	return 0;
}