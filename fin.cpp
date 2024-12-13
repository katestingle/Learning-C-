/******************************************************************************
# Author:           Kate Stingle
# Assignment:       Final Exam (CS 161A)
# Date:             December 11th, 2024
# Description:      - This program tracks the miles you rode in the week and compares 
                      it to your inputted goal miles. 
                    - Prompts the user for the miles they rode for each day, and calculates 
                      totalMiles for the week
                    - The program uses user validation, and always prints an input/output message. 
                    - If the user inputs an invalid goal, the program will not track miles and will quit
                    - I implemented an extra void function setCurrDay to simplify the code (:
# Input:            - int goalMiles (inputted mile goal from the user)
                    - int milesToday (the inputted number of miels for each day. Used in the for loop)
# Output:           - int totalMiles (calculated sum of each day's miles)
                    - undefined string outputs: 
                        + if user set invalid goal, outputs "no miles tracked" msg
                        + meets, exceeds or not not meet goal at end of program
                        + If exceeds or meets, outputs the difference between goalMiles and totalMiles with msg
                        + if invalid input for milesToday, outputs error msg and output reprompt
# Sources:          Final Exam Specifications
#******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//Declare constants :
string const NO_MILES_TRACKED = "No miles were tracked this week.";
string const WELCOME_MSG = "Welcome to my Miles Tracker program.";
string const EXIT_MSG = "Keep Riding!";
string const GOOD_JOB_MEET = "Good Job! You met your goal!";
string const MILES_ERR_MSG = "Miles must be 0 or greater!";
string const SUN = "Sunday";
string const MON = "Monday";
string const TUE = "Tuesday";
string const WED = "Wednesday";
string const THU = "Thursday";
string const FRI = "Friday";
string const SAT = "Saturday";

// declare function headers:
void getInput(int& goal);
int calcTotal();
void setCurrDay(int i, string& currDay);

int main(){
    int goalMiles;
    int totalMiles;
    cout << WELCOME_MSG << endl << endl; // print no matter what
    getInput(goalMiles);
    if (goalMiles <= 0) { // no goal, no miles tracked
        cout << NO_MILES_TRACKED << endl;
    }
    else{ // user inputted a valid goal value
        totalMiles = calcTotal();
        cout << endl << "You rode " << totalMiles << " miles this week." << endl;
        if (goalMiles < totalMiles) { //exceeded 
            totalMiles -= goalMiles; // how much the user exceeded the goal by
            cout << "Great job! You exceeded your goal by " << totalMiles << " miles!" << endl;
        }
        else if (totalMiles < goalMiles) { // did not meet
            goalMiles -= totalMiles; // the difference to meet the goal
            cout << "Uh oh! You missed your goal by " << goalMiles << " miles!" << endl;
        }
        else {
            cout << GOOD_JOB_MEET << endl; // the user met the goal: totalMiles == goalMiles
        }
    }
    cout << endl << EXIT_MSG; // print no matter what
}

//DEFINE functions

//getInput for getting the goalMiles
void getInput(int& goal){
    cout << "How many miles do you want to ride this week? ";
    cin >> goal;
    cout << endl; //formatting
    }

// prompts the user for miles for each day of the week
// to calculate the totalMiles to return
int calcTotal() {
    int totalMiles = 0;
    int milesToday;
    string currDay;
    for (int i = 1; i <= 7; i++) { // currDay changes for each iteration of the for loop
        setCurrDay(i, currDay);//set the ith day to it's given string name
        cout << "How many miles did you ride on " << currDay << "? ";
        cin >> milesToday; // miles for the day
        while (milesToday < 0) { //error message and reprompting if invalid (<0) input
            cout << MILES_ERR_MSG << endl;
            cout << "How many miles did you ride on " << currDay << "? ";
            cin >> milesToday;
        }
        totalMiles += milesToday; // for each day, add the miles to total
    }
        return totalMiles;
}

//used to edit the string currDay within calcTotal for each day
//currDay depended on ith day
void setCurrDay(int i, string& currDay) {
    if (i == 1) {
        currDay = SUN;
    }
    else if (i == 2) {
        currDay = MON;
    }
    else if (i == 3) {
        currDay = TUE;
    }
    else if (i == 4) {
        currDay = WED;
    }
    else if (i == 5) {
        currDay = THU;
    }
    else if (i == 6) {
        currDay = FRI;
    }
    else {
        currDay = SAT;
    }
}