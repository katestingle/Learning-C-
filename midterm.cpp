/******************************************************************************
# Author:           Kate Stingle
# Assignment:       Midterm
# Date:             October 30th, 2024
# Description:      This program determines the winner(s) 
    of a rock collecting game, considering there are 3 participants.
    The input for each participant is an integer for the number of rocks that 
    they collected, and a string for their name. The program will then output 
    WHO (could be one to three winners) won the game - that is, whoever collected the 
    most rocks. Invalid inputs, such as negative numbers, will automatically assign 
    to 0 rocks. Also, the program will print out the average number 
    of rocks collected(still considering invalid numbers as 0). 
    The program will always print a welcome and exit statement.
# Input:            Strings person1, person2, and person3 : names of three 
                    participants. User input variable
                    Ints rocks1, rocks2, rocks3: the amount of rocks that each person 
                    collected. User input variable. Assigned value of 0 if inputted 
                    less than 0.
# Output:           One of three winner string output messages:
                    1. userMsg2 as string = [1st place person] is in first place!
                                            [2nd place person] is in second place.
                                            [3rd place person] is in third place.
                    2. userMsg3 as string = [ties first place person] and [other 
                                            tied 1st place person] are tied for first place.
                                            [2nd place person] is in second place!
                    3. userMsg4 as string = It is a three way tie!
                    avgRocks as double = Contains avg num of rocks collected for the NUM_PEOPLE
                    amnt of people. Always prints to the second dec point.
#******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    //declare program CONSTANTS
    int const NUM_PLAYERS = 3;
    string const WELCOMEMSG = "Welcome to the Rock Collector Championships!";
    string const EXITMSG = "Congratulations Rock Collectors!";
    string const ERRORMSG = "Invalid amount. 0 will be entered.";
    //declare input variable(s)
    string person1, person2, person3;
    int rocks1, rocks2, rocks3;
    //declare output/calculations variable(s)
    double avgRocks;
    
    //begin program output
    cout << WELCOMEMSG << endl;
    //BEGIN PROMPTING AND USER INPUT & VALIDATION
    //person 1 input
    cout << endl << "Enter player 1 name: ";
    getline(cin, person1);
    cout << "How many rocks did " << person1 << " collect? ";
    cin >> rocks1;
    if (rocks1 < 0) { // if invalid input, then
        cout << ERRORMSG << endl; //print error message, and
        rocks1 = 0; //set rocks to 0
    }
    cout << endl; //formatting
    //person 2 input
    cout << endl << "Enter player 2 name: ";
    cin.ignore();
    getline(cin, person2);
    cout << "How many rocks did " << person2 << " collect? ";
    cin >> rocks2;
    if (rocks2 < 0) {
        cout << ERRORMSG << endl;
        rocks2 = 0;
    }
    cout << endl;
    //person 3 input
    cout << endl << "Enter player 3 name: ";
    cin.ignore();
    getline(cin, person3);
    cout << "How many rocks did " << person3 << " collect? ";
    cin >> rocks3;
    if (rocks3 < 0) {
        cout << ERRORMSG << endl;
        rocks3 = 0;
    }
    cout << endl; //formatting

    //begin evaluating user input values
    if (rocks1 == rocks2 && rocks1 == rocks3) { // if all ppl collected the same amnt of rocks
        cout << "It is a three way tie!";
    }
    else if (rocks1 == rocks2) { // if 2-way tie, rocks1 and rocks2 are the same
        cout << person1 << " and " << person2 << " are tied for first place. " << person3 << " is in second place!";
    }
    else if (rocks1 == rocks3) { // if 2-way tie, rocks1 and rocks3 are the same
        cout << person1 << " and " << person3 << " are tied for first place. " << person2 << " is in second place!";
    }
    else if (rocks2 == rocks3) { // if 2-way tie, rocks2 and rocks3 are the same
        cout << person2 << " and " << person3 << " are tied for first place. " << person1 << " is in second place!";
    }
    else if (rocks1 > rocks2 && rocks1 > rocks3) { // if 1 winner: rocks1 is the greatest
        cout << person1 << " is in first place!" << endl;
        if (rocks2 > rocks3) { // rocks2 comes in second, rocks3 in third
            cout << person2 << " is in second place!" << endl;
            cout << person3 << " is in third place!" << endl;
        }
        else { //rocks3 comes in second, rocks2 in third
            cout << person3 << " is in second place!" << endl;
            cout << person2 << " is in third place!" << endl;
        }
    }
    else if (rocks2 > rocks3) { // if rocks2 is 1st
        cout << person2 << " is in first place!" << endl;
        if (rocks1 > rocks3) { // rocks1 comes in second, rocks3 in third
            cout << person1 << " is in second place!" << endl;
            cout << person3 << " is in thrid place!" << endl;
        }
        else { //rocks3 comes in second, rocks1 in third
            cout << person3 << " is in second place!" << endl;
            cout << person1 << " is in thrid place!" << endl;
        }
    }
    else { // if rocks3 is 1st
        cout << person3 << " is in first place!" << endl;
        if (rocks2 > rocks1) { // rocks2 comes in second, rocks1 in third
            cout << person2 << " is in second place!" << endl;
            cout << person1 << " is in third place!" << endl;
        }
        else { //rocks1 comes in second, rocks2 in third
            cout << person1 << " is in second place!" << endl;
            cout << person2 << " is in third place!" << endl;

        }
    }
    cout << endl; //formatting

    //calculate average number of rocks collected and outputs it to 2 dec points
    avgRocks = (rocks1 + rocks2 + rocks3) / static_cast<double>(NUM_PLAYERS);
    cout << fixed << showpoint << setprecision(2); // sets output number values to 2 dec points
    cout <<"The average number of rocks collected by the top three players is " << avgRocks << " rocks!" << endl;
    
    //exit message
    cout << EXITMSG;
	return 0;
}