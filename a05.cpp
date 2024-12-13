/******************************************************************************
# Author:           Kate Stingle
# Assignment:       A05 (CS161A)
# Date:             October 27th, 2024
# Description:      This program will read two string phrases from the user, 
					compare them and output to the user whether or not they 
					contian eachother, and what part of one phrase contains 
					the other phrase.
# Input:            phrase1 as a string, including spaces
					phrase2 as a string, including spaces
# Output:           One of four reponses:
						1. Both entered prhases match
						2. phrase1 is found within phrase2
						   [beginning of phrase1 in phrase2 until end of phrase2]
						3. phrase2 is found within phrase1
						   [beginning of phrase2 in phrase1 until end of phrase1]
						4. There are no matches
#******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main() {
	//declare welcome and exit message constants
	string const WELCOMEMSG = "Welcome to the Phrases and Subphrases program!";
	string const EXITMSG = "Thank you for using my program!";
	//declare input variables
	string phrase1, phrase2;
	//welcome, prompting and inputting into phrase1 and phrase2
	cout << WELCOMEMSG << endl;
	cout << "Enter Phrase 1: ";
	getline(cin, phrase1);
	cout << "You entered: " << phrase1 << endl;
	cout << "Enter Phrase 2: ";
	getline(cin, phrase2);
	cout << "You entered: " << phrase2 << endl << endl;

	//compare phrase1 and prhase2 and otuput depending on if they contain eachother
	if (phrase1 == phrase2) { //if phrase1 is phrase2, aka phrases match
		cout << "Both entered phrases match" << endl;
	}
	else if (phrase2.find(phrase1) != string::npos) { // if phrase1 is in phrase2
		cout << phrase1 << " is found within " << phrase2 << endl;
		cout << phrase2.substr(phrase2.find(phrase1), phrase2.size()) << endl;
	}
	else if ((phrase1.find(phrase2) != string::npos)) { // if phrase2 is in phrase1
		cout << phrase2 << " is found within " << phrase1 << endl;
		cout << phrase1.substr(phrase1.find(phrase2), phrase1.size()) << endl;
	}
	else { // if no phrases match!
		cout << "There are no matches." << endl;
	}
	//exit message
	cout << endl << EXITMSG;
	return 0;
}