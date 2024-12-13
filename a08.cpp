/******************************************************************************
# Author:           Kate Stingle
# Assignment:       A08 Assignment (CS161A)
# Date:             November 24th, 2024
# Description:      This program will calculate a student’s final grade(0.0-4.0 scale) and letter grade based 
					on their input for scores on: numAssigns number of assignments, the midterm, and
					the final exam. The program will prompt the user to enter their
					number of assignments, ask for the scores of each individual assignment, 
					and calculate the avg assignment Grade. It will then determine and output the final numeric
					grade and the final letter grade.
# Input:            - numAssigns as integer (the number of assignments the user would like to enter, read from the user using(using readInt()). 
						Determines how many times they will be prompted for an assignment score within  assignAverage(int numAssigns);  )
					- assignAvg as double (to read the score for assignments from the user. Validated within readScore())
# Output:           - finalScore as double (the calculated final score from the previously calculated assignment score average, midterm score and exam score
					- assignNum as int (the current nth assignment to be inputted, incremented each time the user enters a score
					- letterGrade as char (calculated letter grade that the student will get based on input
# Rescources:		Assignment 8 specifications
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constants
const double ASSIGN_WEIGHT = 0.6;
const double MIDTERM_WEIGHT = 0.2;
const double EXAM_WEIGHT = 0.2;
const string EXIT_MSG = "Thank you for using my Grade Calculator!";
const string NUM_ASSIGN_PROMPT = "Enter the number of assignments(0 to 10): ";
const string ASSIGN_SCORE_PROMPT = "Enter score ";
const string MIDTERM_SCORE_PROMPT = "Enter your midterm exam score: ";
const string FINAL_EXAM_SCORE_PROMPT = "Enter your final exam score: ";
const string NUM_ASSIGN_ERR = "Illegal Value! Please try again!!";
const string SCORE_ERR = "Illegal Score! Please try again!";
const string FINAL_SCORE_MSG = "Your Final Numeric score is ";
const string FINAL_LETTERGRADE_MSG = "Your Final Grade is ";

// Function declarations
void welcome();
int readInt(string prompt);
double readScore(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double final);
char calcLetterGrade(double finalScore);
void printSummary(double score, char letterGrade);

// MAIN
int main() {
    welcome();
    int numAssigns = readInt(NUM_ASSIGN_PROMPT);
    double assignAvg = assignAverage(numAssigns);
    double midtermScore = readScore(MIDTERM_SCORE_PROMPT);
    double examScore = readScore(FINAL_EXAM_SCORE_PROMPT);
    double finalScore = calcFinalScore(assignAvg, midtermScore, examScore);
    char letterGrade = calcLetterGrade(finalScore);
    printSummary(finalScore, letterGrade);
    cout << EXIT_MSG << endl;
    return 0;
}

// Function definitions
void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl << endl;
}

int readInt(string prompt) {
    int numAssigns;
    bool valid = false; // Flag to track input validity

    cout << prompt;
    while (!valid) {
        cin >> numAssigns;
        if (!cin.fail() && numAssigns >= 0 && numAssigns <= 10) {
            valid = true; // Input is valid
        }
        else {
            cout << NUM_ASSIGN_ERR << endl;
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << prompt;
        }
    }
    cin.ignore(1000, '\n'); // Discard any extra input
    return numAssigns;
}

double readScore(string prompt) {
    double score;
    bool valid = false;

    cout << prompt;
    cin >> score;

    while (!valid) {
        if (cin.fail() || score < 0.0 || score > 4.0) {
            cout << SCORE_ERR << endl;
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << prompt;
            cin >> score;
        }
        else {
            valid = true;
            cin.ignore(1000, '\n'); // Discard extra input
        }
    }
    return score;
}

double assignAverage(int numAssigns) {
    if (numAssigns == 0) {
        return -1;
    }

    double assignAvg = 0.0;
    string prompt;
    for (int assignNum = 1; assignNum <= numAssigns; ++assignNum) {
        prompt = ASSIGN_SCORE_PROMPT + to_string(assignNum) + ": ";
        assignAvg += readScore(prompt);
    }
    cout << endl; //formatting
    return assignAvg / numAssigns;
}

double calcFinalScore(double assignAvg, double midterm, double final) {
    if (assignAvg == -1) {
        return (midterm * MIDTERM_WEIGHT + final * EXAM_WEIGHT) / (MIDTERM_WEIGHT + EXAM_WEIGHT);
    }
    else {
        return (midterm * MIDTERM_WEIGHT + final * EXAM_WEIGHT + ASSIGN_WEIGHT * assignAvg) /
            (MIDTERM_WEIGHT + EXAM_WEIGHT + ASSIGN_WEIGHT);
    }
}

char calcLetterGrade(double finalScore) {
    if (finalScore >= 3.3) {
        return 'A';
    }
    else if (finalScore >= 2.8) {
        return 'B';
    }
    else if (finalScore >= 2.0) {
        return 'C';
    }
    else if (finalScore >= 1.2) {
        return 'D';
    }
    else {
        return 'F';
    }
}

void printSummary(double score, char letterGrade) {
    cout << fixed << setprecision(1) << endl; //formatting
    cout << FINAL_SCORE_MSG << score << endl;
    cout << FINAL_LETTERGRADE_MSG << letterGrade << endl << endl;
}