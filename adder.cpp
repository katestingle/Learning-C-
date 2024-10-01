#include <iostream>
using namespace std;

int main() {
	//TASK: get 2 num from user
	//disp sum of nums
	int n1;
	int n2;
	int n3;
	cout << "1st Number: ";
	cin >> n1;
	cout << "2nd Number: ";
	cin >> n2;
	cout << "sum = " << n1 + n2 <<endl;
	//extra cred: get a 3rd number and output the avg
	cout << "3rd Number: ";
	cin >> n3;
	cout << "avg = " << (n1 + n2 + n3)/3;
	return 0;
}