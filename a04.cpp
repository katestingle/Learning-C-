#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
	//CONSTANTS
	const double ADULTPRICE = 14.95;
	const double SENIORPRICE = 7.40;
	const double YOUTHPRICE = 5.55;
	const double VEHICLEPRICE = 57.90;
	const double BIKEPRICE = 4.00;
	const double FREETICKETPRICE = 100.00;
	const int MAXGROUP = 20;
	const int NUMDECPOINTS = 2;

	//variables - input
	char ridingVehicle;
	int adults, seniors, youths, bikes;
	//variables - calculations & output
	double differenceForFreeTicket;
	double totalCost;
	

	cout << fixed << showpoint << setprecision(NUMDECPOINTS);

	//Welcome message
	cout << "Welcome to the Washington State Ferries Fare Calculator!" << endl << endl;
	
	//Fare Description output
	cout << "Fare Description                                Ticket $" << endl;
	cout << "--------------------------------------          --------" << endl;
	cout << "Vehicle Under 14' (less than 163\") & Driver      $" << VEHICLEPRICE << endl;
	cout << "Adult (age 19 - 64)                              $" << ADULTPRICE << endl;
	cout << "Senior (age 65 & over) / Disability              $" << SENIORPRICE << endl;
	cout << "Youth (age 6 - 18)                               $" << YOUTHPRICE << endl;
	cout << "Bicycle Surcharge (included with Vehicle)        $" << BIKEPRICE << endl << endl;

	//prompt user for if riding a vehicle
	cout << "Are you riding a vehicle on the Ferry (Y/N): ";
	cin.get(ridingVehicle); //gets just the 1st character into ridingVehicles
	cin.get(); //gets input from rest of line if inputted more than just 1 character. this is because we don't want this to be considered for the next input cin >>

	//test if char input valid, quit if invalid
	if (ridingVehicle != 'y' && ridingVehicle != 'Y' && ridingVehicle != 'n' && ridingVehicle != 'N') {
		cout << endl << "Error!!Invalid answer!!Please try again later!!!" << endl;
	}
	else {
		//prompt for # adults
		cout << "How many adults? ";
		cin >> adults;
		if (adults < 0) {
			cout << endl << "Error!!Invalid answer!!Please try again later!!!" << endl;
		}
		else {
			cout << "How many seniors? ";
			cin >> seniors;
			if (seniors < 0) {
				cout << endl << "Error!!Invalid answer!!Please try again later!!!" << endl;
			}
			else {
				cout << "How many youths? ";
				cin >> youths;
				if (youths < 0) {
					cout << endl << "Error!!Invalid answer!!Please try again later!!!" << endl;
				}
				else if (youths + adults + seniors > MAXGROUP) {
					cout << endl << "Uh oh!! Too many people in your group. Split into 2 groups and try again!" << endl;
				}
				else {
					totalCost = YOUTHPRICE * youths + SENIORPRICE * seniors + ADULTPRICE * adults;
					if (ridingVehicle == 'y' || ridingVehicle == 'Y') {
						totalCost += VEHICLEPRICE;
					}
					else {
						cout << "How many bikes? ";
						cin >> bikes;
						if (bikes < 0) {
							cout << endl << "Error!!Invalid answer!!Please try again later!!!" << endl;
						}
						else {
							totalCost += bikes * BIKEPRICE;
						}
					}
					cout << "You" << "'" << "re total charge is $" << totalCost << endl << endl;
					differenceForFreeTicket = FREETICKETPRICE - totalCost;
					if (differenceForFreeTicket <= 0) {
						cout << "You are eligible for a free adult ticket on your next trip!"<< endl;
					}
					else {
						cout << "If you spend $" << differenceForFreeTicket << " or more, you are eligible for a free adult ticket for the next trip." << endl << endl;						}
					
				}
			}
		}
	}
	cout << "Thank you for using Washington State Ferries Fare Calculator!";
	return 0;
}