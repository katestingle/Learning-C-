/******************************************************************************
# Author:           Kate Stingle
# Assignment:       A09 Assignment (CS161A)
# Date:             December 1st, 2024
# Description:      This program will calculate a students final grade(0.0-4.0 scale) and letter grade based
                    on their input for scores on: numAssigns number of assignments, the midterm, and
                    the final exam. The program will prompt the user to enter their
                    number of assignments, ask for the scores of each individual assignment,
                    and calculate the avg assignment Grade. It will then determine and output the final numeric
                    grade and the final letter grade.
# Input:            - numAssigns as integer (the number of assignments the user would like to enter, read from the user using(using readInt()).
                        Determines how many times they will be prompted for an assignment score within  assignAverage(int numAssigns);  )
                    - add as double (to read the score for assignments from the user to be added to assignAvg. Validated within readScore())
# Output:           - finalScore as double (the calculated final score from the previously calculated assignment score average, midterm score and exam score
                    - assignNum as int (the current nth assignment to be inputted, incremented each time the user enters a score
                    - letterGrade as char (calculated letter grade that the student will get based on input. passed by reference)
# Rescources:		Assignment 9 specifications
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
double readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double& midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double final);
void calcLetterGrade(double finalScore, char &letter);
void printSummary(double score, char letterGrade);

// MAIN
int main() {
    welcome();
    int numAssigns = readInt(NUM_ASSIGN_PROMPT);
    double assignAvg = assignAverage(numAssigns);
    double midtermScore, examScore;
    getInput(midtermScore, examScore);
    double finalScore = calcFinalScore(assignAvg, midtermScore, examScore);
    char letterGrade;
    calcLetterGrade(finalScore, letterGrade);
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

double readScore(string prompt, double &num) {
    bool valid = false;

    cout << prompt;
    cin >> num;

    while (!valid) {
        if (cin.fail() || num < 0.0 || num > 4.0) {
            cout << SCORE_ERR << endl;
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << prompt;
            cin >> num;
        }
        else {
            valid = true;
            cin.ignore(1000, '\n'); // Discard extra input
        }
    }
}

double assignAverage(int numAssigns) {
    if (numAssigns == 0) {
        return -1;
    }

    double assignAvg = 0.0;
    string prompt;
    double add = 0; // added to the avg each iteration
    for (int assignNum = 1; assignNum <= numAssigns; ++assignNum) {
        prompt = ASSIGN_SCORE_PROMPT + to_string(assignNum) + ": ";
        readScore(prompt, add);
        assignAvg += add;
    }
    cout << endl; //formatting
    return assignAvg / numAssigns;
}

void getInput(double &midtermScore, double &finalExamScore) {
    readScore(MIDTERM_SCORE_PROMPT, midtermScore);
    readScore(FINAL_EXAM_SCORE_PROMPT, finalExamScore);
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

void calcLetterGrade(double finalScore, char &letter) {
    if (finalScore >= 3.3) {
        letter = 'A';
    }
    else if (finalScore >= 2.8) {
        letter = 'B';
    }
    else if (finalScore >= 2.0) {
        letter = 'C';
    }
    else if (finalScore >= 1.2) {
        letter = 'D';
    }
    else {
        letter = 'F';
    }
}

void printSummary(double score, char letterGrade) {
    cout << fixed << setprecision(1) << endl; //formatting
    cout << FINAL_SCORE_MSG << score << endl;
    cout << FINAL_LETTERGRADE_MSG << letterGrade << endl << endl;
}