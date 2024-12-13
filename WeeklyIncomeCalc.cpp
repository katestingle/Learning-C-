/******************************************************************************
# Author:           Kate Stingle
# Assignment:       A02 (CS161A)
# Date:             October 6, 2024
# Description:      This program will read the employee ID number, number of 
hours worked in a week, hourly rate,
					and federal withholding rate from the user. It will then 
					calculate & output Total Groos Pay, FICA
					Deduction, Federl withholding, total deductions and net 
					pay for the user for that week.
# Input:            employeeID as int - Employee ID number read from the user
					hrsWorked as int - amount hours owkred in one week read 
					from the user
					hrlyRate as float - Hourly Rate in $/hr read from the user
					fedWithRate as float - Federal withholding rate as a 
					percent(eg 15%) read form the user
# Output:           grossPay as float- total gross pay, that is hrlyRate * hrsWorked
					ficaDed as float - the maoutn in $ of FICA(social and medicare)deductions
					fedWith as float - amount in $ of federal withholding
					total Deductions as float - the total deduction in $ for that week
					net Pay as float - the net pay in $ for that week
# Sources:          C++'s library <iostream> and <iomanip>
#******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//main function
int main() {
	//constant FICADEDUCT for FICA Deduction Rate as a %
	const float FICADEDUCT = 7.65;

	//instantiate ALL variables used
		//DECLARE variables hrlyRate, fedWithRate, ficaDed, fedWith, grossPay as float
	float hrlyRate;
	float fedWithRate;
	float ficaDed;
	float fedWith;
	float grossPay;
		//DECLARE variables employeeID, hrsWorked as integers
	int employeeId;
	int hrsWorked;

	//DISPLAY Welcome Message, newline
	cout << "Welcome to my Weekly Payroll program!!" << endl;

	//user input prompts & read to variables
	cout << "Enter your employee ID number (numbers only): ";
	cin >> employeeId;
	cout << "Enter number of hours worked (whole numbers): ";
	cin >> hrsWorked;
	cout << "Enter the hourly rate: ";
	cin >> hrlyRate;
	cout << "Enter the federal withholding rate : ";
	cin >> fedWithRate; 

	//Calculations: gross pay, federal withholding tac, and fica deductions
	grossPay = hrsWorked * hrlyRate;
	fedWith = grossPay * (fedWithRate / 100);
	ficaDed = grossPay * (FICADEDUCT / 100);

	//set output precision to 2 decimal points and 2 precision
	cout << fixed << showpoint << setprecision(2);
		/* fixed: all ouputs are to the following standard for cout commands
		 * showpoint: preceding setprecision(n) displays numbers at n amount of
		   decimal points even if not needed. */
	
	//Output: PAYROLL SUMMARY containing gross pay, fica deductions, federal tax withholding, total deductions and net pay
	cout << endl << "Your Payroll Summary:" << endl;
	cout << "Total Gross Pay: $" << grossPay << endl;
	cout << "FICA deductions: $" << ficaDed << endl;
	cout << "Federal Tax Withholding: $" << fedWith << endl;
	cout << "Total deductions: $" << (fedWith + ficaDed) << endl;
	cout << "Net Pay: $" << ((grossPay - fedWith) - ficaDed) << endl << endl;

	//display exit message
	cout << "Thank you for using my Weekly Payroll program!!";

	//end program
	return 0;
}