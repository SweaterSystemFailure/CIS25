#include <iostream>
#include <string>
#include "gradeLevel.h"
#include "globalVariables.h"
using namespace std;

void gradeLevel() {
	unsigned grade;
	char choice;
	
	//collects class grade level
	while (true) {
		cout << "Which grade do you teach? [1-12] " << endl;					//Needs solutions for K & pre-K.
		cin >> grade;
		if (cin.fail() || grade < 1 || grade > 12) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a grade between 1 & 12." << endl;
		}
		else {
			break;
		}
	}

	//outout for user validation
	cout << endl;
	cout << "You teach grade " << grade << "." << endl;
	cout << endl;

	//user validation
	while (true) {
		cout << "Does this look right to you?[Y/N] " << endl;
		cin >> choice;
		choice = tolower(choice);
		cin.ignore();

		if (choice == 'y') {
			gradeLev = grade;										//user agreement stores grade level to global variable
			cout << endl;
			cout << "This is now " << teacherFullName << "'s Grade " << gradeLev << " Book" << endl;
			cout << endl;
			break;
		}
		else if (choice == 'n') {									//user disagreement allows them to try again
			cout << "That's okay. Let's try again." << endl;	
			return gradeLevel();
		}
		else {														// default invalid state
			cout << "Invalid input. Please enter y or n." << endl;
		}
	}
	return;
}