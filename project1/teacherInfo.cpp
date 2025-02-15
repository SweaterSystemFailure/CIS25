#include <iostream>
#include <string>
#include <cstring>
#include "teacherInfo.h"

using namespace std;

string teacherInfo() {
	string honorific, teacherLast, teacherFull;
	char choice;
	while (true) {
		cout << "What honorific do your students address you by? [Ms., Mrs., Mr., Dr., etc] ";
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
		cout << "Does this look right to you? " << endl;
		cin >> choice;
		choice = tolower(choice);

		if (choice == 'y') {
			break;
		}
		else if (choice == 'n') {
			cout << "That's okay. Let's try again." << endl;
			teacherInfo();
		}
		else {
			cout << "Invalid input. Please enter y or n." << endl;
		}
	}

	return teacherFull;
}