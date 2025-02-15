#include <iostream>
#include "newAssignment.h"
#include "globalVariables.h"

using namespace std;

void newAssignment() {
	char choice;

	for (int i = 0; i < 10; i++) {
		string assignmentName;
		unsigned pointsPossible;
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
			cout << "How many points are possible on " << assignmentName << "?" << endl;
			cin >> pointsPossible;
			if (cin.fail() || pointsPossible < 0 || pointsPossible > 1000) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a valid number of points." << endl;
			}
			else {
				assignmentPointsPossible[i] = pointsPossible;
				break;
			}
		}
	}
	//ideally, this check should occur after each time the top for loop executes and then break both loops if the user selects the 'no' option.
		while (true) {
			for (int j = 0; j < 10; j++) {
				cout << "Assignment " << j + 1 << ", " << assignmentNames[j] << " is worth " << assignmentPointsPossible[j] << "." << endl;
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
				newAssignment();
			}
			else {
				cout << "Invalid input. Please enter Y or N." << endl;
			}	
	}
}
