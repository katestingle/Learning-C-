/******************************************************************************
# Author:           Kate Stingle
# Assignment:       A06 Assignment (CS161A)
# Date:             November 9th, 2024
# Description:      This program will read numb of the numbers rounded to 2 decimal places.
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 6 specifications
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //constants
    const double SALES_TAX = 0.07; // 7% sales tax
    const double DELIVERY_FEE = 0.2; //0.2% delivery tax on the pizzas fee + sales tax fee
    const int SLICES_IN_PIZZA = 8; //num slices in any 1 pizza
    //INPUT VARIABLES
    char userContinue; //contains 'y' or 'n' after asking user to continue inputting
    int people; // num ppl in a party
    double avgSlices, singlePizzaCost; //avg slices per person in party, cost of 1 pizza for that party
    //OUTPUT VARIABLES
    //Per party :
    int numEntries = 0;
    int totalPizzas = 0;

    int pizzas;
    double pizzasCost, taxCost, deliveryCost, totalCost;
     //summative :
    double maxTotalCost = 0.0;
    int maxPeople = INT_MIN;

    //welcome message
    cout << "Welcome to my Pizza Party Statistics program!" << endl;
    //input loop begins 
    do {
        //Party user Input
        cout << endl << "Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: ";
        cin >> people >> avgSlices >> singlePizzaCost;
        //Make calulations for party
        pizzas = ceil((avgSlices * people) / SLICES_IN_PIZZA); //rounds up to a whole int(whole pizza)
        pizzasCost = pizzas * singlePizzaCost;
        taxCost = SALES_TAX * pizzasCost;
        deliveryCost = DELIVERY_FEE * (pizzasCost + taxCost);
        totalCost = pizzasCost + taxCost + deliveryCost;
        //Output individual pizza party stats
        cout << endl << "Number of pizzas: " << pizzas << endl;
        cout << fixed << setprecision(2); //set right w/ $
        cout << left << setw(17) << "Cost of pizzas:"<< "$" << pizzasCost << endl;
        cout << left << setw(17) << "Tax:" << "$" << taxCost << endl;
        cout << left << setw(17) << "Delivery:" << "$" << deliveryCost << endl;
        cout << left << setw(17) << "Total Cost:" << "$" << totalCost << endl;
        cout << fixed << setprecision(0); //set back to no dec points
        //Modify summative variables
        numEntries++;
        totalPizzas += pizzas;
        if (people >= maxPeople) {
            maxPeople = people;
        }
        if (totalCost >= maxTotalCost) {
            maxTotalCost = totalCost;
        }
         //Prompt user to/not to continue input
         cout << "Do you want to enter more (y/n): ";
         cin >> userContinue;
    } while (userContinue == 'y'); //CHECK if user wants to continue

    //accumulated parties stats summary
    cout << endl << "Number of entries: " << numEntries << endl;
    cout << "Total number of pizzas: " << totalPizzas << endl;
    cout << "Average number of pizzas: " << setprecision(1) << static_cast<double>(totalPizzas) / numEntries << endl;
    cout << "Maximum number of people: " << maxPeople << endl;
    cout << "Maximum cost of pizzas: $" << setprecision(2) << maxTotalCost << endl << endl;
    //exit message
    cout << "Thank you for using my program!";
	return 0;
}