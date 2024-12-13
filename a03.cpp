/******************************************************************************
# Author:           Kate Stingle
# Assignment:       A03 (CS161A)
# Date:             October 13th, 2024
# Description:      This program is a serving and calorie calculator for the 
					consumption of oreo cookies. It prompts the user for the 
					number of cookies they have eaten. It then calculates and 
					displays the number of servings and total calories using 
					fixed point notation to 1 decimal point. These calculations 
					are also dependent on the constant that there are 5 cookies
					and 160 calories in 1 serving of oreos. It also uses data 
					type casting to divide integers as doubles for accurate 
					decimal values. 
# Input:            numOreos, as integer, holds the whole # amount of oreos 
					that the user has eaten to perform calculations on
# Output:           numServings, double, holds the number of servings in the 
					numOreos that the user has eaten
					caloriesEaten, double, holds the number of calories from 
					the numServings of oreos that the user has eaten
# Sources:          Assignment 3 specifications
#******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//declare constants
	const int OREOSPERSERVING = 5;
	const int CALSPERSERVING = 160;

	//declare variables, do not assign.
	int numOreos; //assigned by input
	double numServings; //assigned in calculations
	double caloriesEaten; //assigned in calculations

	//welcome message
	cout << "Welcome to the Oreo Calculator!" << endl << endl;

	//prompt user & input
	cout << "Enter the number of Oreos eaten(whole cookies only): ";
	cin >> numOreos;

	//input verification using cin functions
	while (cin.fail()) { // while cin's "fail" flag is up, meaning input errors
		cout << "Invalid input. Please enter a valid integer: ";
		cin.clear(); // lower the previously raised error flag
		cin.ignore(); // ignore all extra characters in input stream
		cin >> numOreos; //try user input again for new value
	}

	//perform calculations
		//using casting as double to produce double output val into numServings
	numServings = static_cast<double>(numOreos) / OREOSPERSERVING;
		//numServings is double, so caloriesEaten will obtain a double val
	caloriesEaten = numServings * CALSPERSERVING; //no casting needed for this calculation
		

	//using fixed & showpoint w/ setprecision(n) from <iomanip>
	cout << fixed << showpoint << setprecision(1);
	//fixed: sets following cout statements to the stated standard(s)
	//showpoint: w/ setprecision(n), shows up no n # decimal points if of type double, no matter the value
	//setprecision(1): set output value precision to 1 decimal values

	//output calculation summary
	cout << endl;
	cout << numOreos << " Oreos equals " << numServings << " servings!" << endl;
	cout << "You consumed " << caloriesEaten << " calories." << endl;
	cout << endl;

	//exit message
	cout << "Thank you for using the Oreo Calculator!";

	return 0;
}