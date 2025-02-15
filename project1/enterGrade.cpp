#include <iostream>
#include <string>
#include "enterGrade.h"
#include "globalVariables.h"
#include "mainMenu.h"

using namespace std;

void enterGrade() {
	unsigned pointsEarned;
	char choice;

	if (assignmentNames[0] == "undefined") {												//In version 2, this check needs to be more refined. Ideally, it should test whether the storage array or object exists at all.
		cout << "Please create new assignments before grading them." << endl;
		mainMenu();
	}

	else {
		for (int i = 0; i < assignmentTotalSize; i++) {
			pointsEarned = 0;
			while (true) {
				cout << "Enter a positive integer: " << endl;
				cin >> pointsEarned;

				if (cin.fail() || pointsEarned <= 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a positive integer." << endl;
				}
				else if (pointsEarned > assignmentPointsPossible[i]) {								//Maybe version 2 should include a way to assign extra credit on the assignment level?
					cout << "Invalid input. Points earned cannot exceed points possible." << endl;
				}
				else {
					assignmentPointsScored[i] = pointsEarned;
					break;
				}
			}
		}
	}

	while (true) {
		for (int j = 0; j < assignmentTotalSize; j++) {
			cout << "Student "<< studentInfo[0]<<  " scored " << assignmentPointsScored[j] << "out of " << assignmentPointsPossible[j] << " on assignment " << j + 1 << ", " << assignmentNames[j] << "." << endl;
		}

		cout << "Does this look right to you?[Y/N] " << endl;
		cin >> choice;
		choice = tolower(choice);

		if (choice == 'y') {
			cout << "Great. Let's go back to the main menu." << endl;
			break;
		}
		else if (choice == 'n') {
			cout << "That's okay. Let's try again." << endl;
			enterGrade();
		}
		else {
			cout << "Invalid input. Please enter Y or N." << endl;
		}
	}
	mainMenu();
}
