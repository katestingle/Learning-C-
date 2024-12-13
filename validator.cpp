#include <iostream>
using namespace std;

int main() {
	long long currentNum;
	long long cardNumber = 1234'1111'5678'9000;
	cardNumber = 1234567812345670;
//	1 3 1 1 5 7 9 0
//	2 + 6 + 2 + 2 + 
	int sum = 0;
	for (int i = 0; i < 16; i++) {
		currentNum = cardNumber / static_cast<long long>(pow(10, 15 - i));  //cuts of the end
		currentNum = currentNum % 10; 
		if (i%2 == 1){ // if 2nd, 4th, 6th dig etc. in n series
			sum += currentNum;
		}
		else { // if 1st, 3rd, 5th  dig in n series
			if (currentNum * 2 > 9) {//if doubled is more then 9, then
				sum += (currentNum * 2 - 9); //minus nine from its double and at it to the sum
			}
			else { //otherwise double is <= 9, so 
				sum += currentNum * 2; // simply add its double to the sum
			}
		}
	}

	if (sum % 10 == 0) {
		cout << "You entered a valid CCN Number";
	}
	else {
		cout << "You enetered an invlaid CCN Number";
	}
	return 0;
}