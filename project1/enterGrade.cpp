#include <iostream>
#include <string>
#include "enterGrade.h"
#include "globalVariables.h"
#include "mainMenu.h"

using namespace std;

//I don't love this for the same reason as the newAssignment function. 
//Should be more menu driven and allow users to input in a nonlinear way.
void enterGrade() {
	float pointsEarned;
	char choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (assignmentNames[0] == "Undefined") {												//In version 2, this check needs to be more refined. Ideally, it should test whether the storage array or object exists at all.
		cout << "Please create new assignments before grading them." << endl;
		cout << endl;
		mainMenu();
		return;
	}

	else {
		for (int i = 0; i < assignmentTotalSize; i++) {										//outer loop set to number of assigments
			pointsEarned = 0;																//resets entry variable on each loop
			while (true) {																	//recaps assignment number, name, and points possible, then collects points earned.
				cout << "Assignment " << i+1 << ": " << assignmentNames[i] << "." << endl;
				cout << assignmentPointsPossible[i] << " points are possible on this assignment." << endl;
				cout << "How many points did this student earn? " << endl;
				cin >> pointsEarned;
				cout << endl;

				if (cin.fail() || pointsEarned <= 0) {												//input validation
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid score." << endl;
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
		for (int j = 0; j < assignmentTotalSize; j++) {												//prints user input for validation
			cout << "Student "<< studentInfo[0]<<  " scored " << assignmentPointsScored[j] << " out of " << assignmentPointsPossible[j] << " on assignment " << j + 1 << ", " << assignmentNames[j] << "." << endl;
		}

		cout << "Does this look right to you?[Y/N] " << endl;										//validation check
		cin >> choice;
		cin.ignore();
		choice = tolower(choice);

		if (choice == 'y') {																		//information is already stored so agreement returns.
			cout << "Great. Let's go back to the main menu." << endl;
			break;
		}
		else if (choice == 'n') {																	//disagreement allows redo
			cout << "That's okay. Let's try again." << endl;
			return enterGrade();
		}
		else {																						//default invalid state
			cout << "Invalid input. Please enter Y or N." << endl;
		}
	}
	mainMenu();
}
