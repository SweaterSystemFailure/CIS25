#include <iostream>
#include <string>
#include "gradeLevel.h"
#include "globalVariables.h"
using namespace std;

void gradeLevel() {
	unsigned grade;
	char choice;
	
	cin >> grade;
	while (true) {
		cout << "Which grade do you teach? [1-12] " << endl;					//Needs solutions for K & pre-K.
		cin >> grade;
		if (cin.fail() || grade <= 1 || grade >= 12) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a grade between 1 & 12." << endl;
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "Does this look right to you? " << endl;
		cin >> choice;
		choice = tolower(choice);

		if (choice == 'y') {
			gradeLev = grade;
		}
		else if (choice == 'n') {
			cout << "That's okay. Let's try again." << endl;
			gradeLevel();
		}
		else {
			cout << "Invalid input. Please enter y or n." << endl;
		}
	}
}