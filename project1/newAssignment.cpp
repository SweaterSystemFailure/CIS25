#include <iostream>
#include <string>
#include "newAssignment.h"
#include "globalVariables.h"
#include "mainMenu.h"

using namespace std;

void newAssignment() {
	char choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < assignmentTotalSize; i++) {
		string assignmentName;
		float pointsPossible;

		while (true) {
			cout << "What is assignment " << i + 1 << " called? " << endl;
			getline(cin, assignmentName);
			if (assignmentName.empty()) {
				cout << "Invalid input. Can't be empty." << endl;
			}
			else {
				assignmentNames[i] = assignmentName;
				break;
			}
		}
		while (true) {
			cout << "How many points are possible on " << assignmentName << "?[1 - 1000] " << endl;
			if (!(cin >> pointsPossible)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a valid number of points." << endl;
			}
			else if (pointsPossible < 1 || pointsPossible > 1000) {
				cout << "Invalid input. Please enter a valid number of points." << endl;
			}
			else {
				assignmentPointsPossible[i] = pointsPossible;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
	}

		//ideally, there should be a similar check after each input.
		while (true) {
			for (int j = 0; j < assignmentTotalSize; j++) {
				cout << "Assignment " << j + 1 << ", " << assignmentNames[j] << " is worth " << assignmentPointsPossible[j] << "." << endl;
			}

			cout << "Does this look right to you?[Y/N] " << endl;
			cin >> choice;
			choice = tolower(choice);
			cin.ignore();

			if (choice == 'y') {
				cout << "Great. Let's go back to the main menu." << endl;
				break;
			}
			else if (choice == 'n') {
				cout << "That's okay. Let's try again." << endl;
				newAssignment();
			}
			else {
				cout << "Invalid input. Please enter Y or N." << endl;
			}
		}
		mainMenu();
	}
		
