/******************************************************************************
# Author:           Kate Stingle
# Assignment:       A07  (CS161A)
# Date:             November 17th, 2024
# Description:      This program simulates that of a vending machine, prompting the user to first 
                    insert money, then stating their available balance, 
                    then asking the item that they would like to select, 
                    how many of that item, and then outputting the total cost of the items. 
                    If the user has enough balance, it will output their balance after purchase,
                    and if the user does not have enough balance to make the purchase,
                    it will prompt them to insert more money, and repeat the process. 
# Input:            coinIntake as integer , the money the user gives to the machine
                    itemOption as char , the item that the user would like to purchase
                    nItems as integer , the number of that item that the user would like to purchase
# Output:           availableBalance as double , the accumulated amount in dollars that the user has inputted into the machine
                    totalCost as double , the calculated total cost for the items(s) the user would like to purchase
# Sources:          Assignment 7 specifications
                    cppreference.com for standard library's tolower() definition
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
#include <cctype> //for tolower()

using namespace std;

//constants for string ouput messages and money calculations
//Declare constants :
double const ITEM_PRICE = 0.25;
double const CENTS_TO_USD = 0.01;
string const WELCOME_MSG = "Welcome to my Coffee/Tea Vending Machine! \n";
string const EXIT_MSG = "Thank you for using my Vending Machine Program!";
string const ERRORMSG1 = "Invalid Option! Please choose a valid option!";
string const ERRORMSG2 = "Invalid Option!";
string const UBROKEMSG = "Not enough change!! Please add more coins.";
string const MONEY_PROMPT = "Enter coins - 5, 10, or 25 only: ";
string const MENU_PROMPT = "    C / c: Coffee \n    T / t : Tea \n    Q / q : Quit";
string const N_ITEMS_PROMPT = "How many would you like?";

int main() {
    //welcome message
    cout << WELCOME_MSG << endl;

    //Declare variables :
    bool hasPurchased = false;
     //Input variables :
    int coinIntake = 0;
    int nItems = -1;
    char itemOption;
     //output variables :
    double availableBalance = 0;
    double totalCost = -1;
    

    //Set formatting for output
    cout << fixed << setprecision(2);

    //begin purchase prompt cycle
    while (!hasPurchased and totalCost != 0) {
        totalCost = 0;
        //Begin money prompting
        do {
            cin.clear();
            cin.ignore(10000, '\n');
            if (coinIntake == 5 || coinIntake == 10 || coinIntake == 25) {
                availableBalance += (CENTS_TO_USD * coinIntake);
            }
            cout << MONEY_PROMPT;
            cin >> coinIntake;
        } while (cin.fail() || coinIntake != 0);//input validation for $

        // Output availableBalance
        cout << endl << "Your balance is $" << availableBalance << endl << endl;

        //Menu prompt (itemOption) and number of items (nItems)
        cout << "Please pick an option($" << ITEM_PRICE << " each) : " << endl << MENU_PROMPT << endl;
        cin >> itemOption;
        while (tolower(itemOption) != 'q' && tolower(itemOption) != 'c' && tolower(itemOption) != 't') { // validate itemOption
            cout << ERRORMSG1 << endl;
            cout << "Please pick an option($" << ITEM_PRICE << " each) : " << endl << MENU_PROMPT << endl;
            cin >> itemOption;
        }
        if (itemOption == 'q') { // prepare to quit
            totalCost = 0;
        }
        else { // user has chosen coffee or tea, we can prompt for how many
            //input to nItems for the number of Items
            cout << endl << N_ITEMS_PROMPT << endl;
            cin >> nItems;
            totalCost = ITEM_PRICE * nItems;
            while (nItems < 0) { //verify nItems is a quantifiable number
                cout << ERRORMSG2 << endl << N_ITEMS_PROMPT << endl;
                cin >> nItems;
                totalCost = ITEM_PRICE * nItems;
            }
        }
        //Always display total cost and available balance
        cout << "Your total is $" << totalCost << endl;
        if (totalCost > availableBalance) {
            cout << "Your balance is $" << availableBalance << endl;
            cout << UBROKEMSG;
        }
        else if (totalCost == 0) {
            cout << "Your balance is $" << availableBalance;
            hasPurchased = true;
        }
        else {
            availableBalance -= totalCost;
            cout << "Your balance is $" << availableBalance;
            hasPurchased = true;
        }
        cout << endl;
    }
    //end program    
    cout << endl << EXIT_MSG;
	return 0;
}