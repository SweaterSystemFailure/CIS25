#include <iostream>
#include <string>
#include "teacherInfo.h"
#include "globalVariables.h"

using namespace std;

void teacherInfo() {
	string honorific, teacherLast, teacherFull;
	char choice;
	
	cout << "Welcome to your grade book!" << endl;
	cout << "Let's get started by entering some basic information." << endl;
	cout << endl;
	
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

	teacherFull = honorific + " " + teacherLast;
	cout << "Hi " << teacherFull << "!" << endl;
	
	while (true) {
		cout << "Does this look right to you?[Y/N] " << endl;
		cin >> choice;
		choice = tolower(choice);

		if (choice == 'y') {
			teacherFullName = teacherFull;
			cout << "Great. Let's continue." << endl;
			break;
		}
		else if (choice == 'n') {
			cout << "That's okay. Let's try again." << endl;
			teacherInfo();
			break;
		}
		else {
			cout << "Invalid input. Please enter y or n." << endl;
		}
	}
}