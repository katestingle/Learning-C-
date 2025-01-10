/******************************************************************************
# Author:           Kate Stingle
# Assignment:       Assignment 1 (CS 161B)
# Date:             January 9th, 2025
# Description:      - performs purchase calculations for a user at a food cart
					- prompt to place order or quit
					- prompt for item names and costs, prompt for tip
					- calc and ouputs total items cost, discount and final total
					- always outputs a welcome and exit message
					- uses input validation
# Input:            - int &num in readInt() - reads any integer to the reference variable num for
					  multipurpose use → userOption
					- double &num in readDouble() - reads any double to the reference variable num for
					  multipurpose use → tip, itemCost
					- String itemName in placeOrder() - reads the current itemName to itemName, but the
					  name never used/returned back to the user in output.
					- Char yesNo in placeOrder() - read the user response y/n for whether or not they would
					  like to continue adding items to their cart
# Output:           - Double netCost in main() (first the totalItemsCost, then itself + tip, then itself + tip -
					  discount)
					- Double discount in main() (referenced and determined in tipDiscount())
					- Double tip in main() (referenced and inputted in tipDiscount())
# Sources:          Assignment 1 Specifications
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// CONSTANTS
double const TEN_PERC_OFF_50 = 0.10;
double const FIVE_PERC_OFF_35 = 0.05;
string const EXITMSG = "Thank you for using my program!";
string const WELCOMEMSG = "Welcome to my Food Cart Program!";
string const ITEM_COST_MSG = "Enter the cost of your item $: ";
string const YN_PROMPT = "Do you want another item? (y/n): ";
string const TIP_PROMPT = "Enter the amount of tip you want to add $: ";
string const OPTION_ERR_MSG = "Invalid Option! Please choose 1-2!";// (for readOption())
string const INT_ERR_MSG = "Invalid Option! Please choose 1-2!";// for readInt()
string const DOUBLE_ERR_MSG = "Invalid input! Please enter a money value greater than or equal to zero!"; //(for readDouble())
string const YN_ERR_MSG = "Invalid Option! Please choose y/n!"; //(for y / n char input to yesNo in placeOrder())

// FUNCTION HEADERS
void welcome();
void displayMenu();
void readOption(int& option);
void readInt(string prompt, int& num);
void readDouble(string prompt, double& num);
void placeOrder(double& cost);
double tipDiscount(double& tip, double& discount, double cost);

// MAIN
int main() {
	int option;
	double netCost, tip, discount;
	welcome(); //welcome message no matter what
	do {
		displayMenu(); // another order or quit
		readOption(option); // choose another order or quit 
		if (option == 1) { // take order
			placeOrder(netCost); // this is the sum cost of all the items, prompts user for items
			cout << endl << "Your total is: $" << fixed << setprecision(2) << netCost << endl;
			netCost = tipDiscount(tip, discount, netCost); //this is the final cost
			cout << endl << "You get a " << static_cast<int>((discount / (netCost + discount)) * 100)<<"% off discount!" << endl;
			cout << "Your discount is:  $" << discount << endl;
			cout << "Your final total is: $" << netCost << endl;
		}
	} while (option != 2);
	cout << endl << EXITMSG; // exit msg no matter what
	return 0;
}

// DEFINE FUNCTIONS
void welcome() {
	cout << WELCOMEMSG << endl;
}

void displayMenu() {
	cout << "What would you like to do today?" << endl;
	cout << "Pick an option from below:" << endl;
	cout << "\t1. Place an order" << endl;
	cout << "\t2. Quit";
}

void readOption(int& option) {
	readInt("", option);
	while (option != 1 && option != 2) {
		readInt(OPTION_ERR_MSG, option);
	}
}

void readInt(string prompt, int& num) { // NEED TO TEST THIS !!
	cout << prompt << endl;
	cin >> num;
	while (cin.fail()||num<0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << INT_ERR_MSG << endl;
		cin >> num;
	}
}

// used for item costs, validates
void readDouble(string prompt, double& num) {
	cout << prompt ;
	cin >> num;
	while (cin.fail() || num < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << DOUBLE_ERR_MSG << endl;
		cin >> num;
	}
}

// prompt and input for items, sum costs, edits total item sum cost
void placeOrder(double& cost) {
	cost = 0;
	char yesNo = 'y';
	string itemName;
	double itemCost;
	while (yesNo == 'y') {
		cout << "Enter the name of your item: ";
		cin >> itemName;
		readDouble(ITEM_COST_MSG, itemCost);
		cost += itemCost;
		cout << YN_PROMPT;
		cin >> yesNo;
		while(cin.fail() || !isalpha(yesNo) || (tolower(yesNo) != 'y' && tolower(yesNo) != 'n')){ //while no valid character, or not y or n
			cin.clear();
			cin.ignore(1000, '\n');
			cout << YN_ERR_MSG << endl;
			cin >> yesNo;
		}
	}
}

//returns total cost, edits tip and discount, prompts for tip
double tipDiscount(double& tip, double& discount, double cost) {
	readDouble(TIP_PROMPT, tip);
	cost += tip;
	if (cost > 50) {
		discount = cost * TEN_PERC_OFF_50;
	}
	else if (cost > 35) {
		discount = cost * FIVE_PERC_OFF_35;
	}
	else {
		discount = 0;
	}
	return cost - discount;
}