#include <iostream>
#include <string>
#include "newAssignment.h"
#include "globalVariables.h"
#include "mainMenu.h"

using namespace std;

//I don't love how this function works in practice. 
//In the next version, each input should be directed from a menu so that the user doesn't have to redo all work if they make a mistake.
void newAssignment() {
	char choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');						//this function gets weird if we don't dump prior cin data first

	for (int i = 0; i < assignmentTotalSize; i++) {								//outer loop dictates number of assignments
		string assignmentName;
		float pointsPossible;

		while (true) {															//first inner loop names assignments
			cout << "What is assignment " << i + 1 << " called? " << endl;
			getline(cin, assignmentName);
			if (assignmentName.empty()) {
				cout << "Invalid input. Can't be empty." << endl;
			}
			else {
				assignmentNames[i] = assignmentName;							//stores input to array
				break;
			}
		}
			
		while (true) {															//second inner loop assigns point value to assignment
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
			for (int j = 0; j < assignmentTotalSize; j++) {					//prints user input
				cout << "Assignment " << j + 1 << ", " << assignmentNames[j] << ", is worth " << assignmentPointsPossible[j] << "." << endl;
			}

			cout << "Does this look right to you?[Y/N] " << endl;			//validation check
			cin >> choice;
			choice = tolower(choice);
			cin.ignore();

			if (choice == 'y') {											//data is already stored so returns to main if user agrees
				cout << "Great. Let's go back to the main menu." << endl;
				break;
			}
			else if (choice == 'n') {										//user disagreement allows a retry
				cout << "That's okay. Let's try again." << endl;
				newAssignment();
			}
			else {															//default invalid state
				cout << "Invalid input. Please enter Y or N." << endl;
			}
		}
		mainMenu();
	}
		
