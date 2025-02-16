#include <iostream>
#include <string>
#include "teacherInfo.h"
#include "globalVariables.h"

using namespace std;

void teacherInfo() {
	string honorific, teacherLast, teacherFull;
	char choice;
	
	//collects honorific
	while (true) {
		cout << "Which honorific do your students address you by? [Ms., Mrs., Mr., Dr., etc] ";
		getline(cin, honorific);
		if (honorific.empty()) {
			cout << "Invalid input. Can't be empty. Try again: " << endl;
		}
		else {
			break;
		}
	}

	//collects last name
	while (true) {
		cout << "What is your last name? ";
		getline(cin, teacherLast);
		if (teacherLast.empty()) {
			cout << "Invalid input. Can't be empty. Try again: " << endl;
		}
		else {
			break;
		}
	}

	//output for user validation
	teacherFull = honorific + " " + teacherLast;
	cout << "Hi " << teacherFull << "!" << endl;
	
	//user validation check
	while (true) {
		cout << "Does this look right to you?[Y/N] " << endl;
		cin >> choice;
		choice = tolower(choice);
		cin.ignore();

		if (choice == 'y') {
			teacherFullName = teacherFull;							//user agreement stores to global variable
			cout << "Great. Let's continue." << endl;
			cout << endl;
			break;
		}
		else if (choice == 'n') {									//user disagreement allows them to try again
			cout << "That's okay. Let's try again." << endl;
			cout << endl;
			return teacherInfo();
			break;
		}
		else {														//invalid input statement
			cout << "Invalid input. Please enter y or n." << endl;
			cout << endl;
		}
	}
	return;
}