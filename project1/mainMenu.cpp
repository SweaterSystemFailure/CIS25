#include <iostream>
#include <iomanip>
#include <string>
#include "mainMenu.h"
#include "newStudent.h"
#include "newAssignment.h"
#include "enterGrade.h"
#include "studentReport.h"
using namespace std;

void mainMenu() {
	int menuOption;													

	//menu options
	cout << "Welcome to the main menu." << endl;
	cout << "From here you can enter student information and grades." << endl;
	cout << "Would you like to: " << endl;
	cout << endl;
	cout << "1. Enter new student information." << endl;
	cout << "2. Create new assignments." << endl;
	cout << "3. Enter grades for an existing assignments." << endl;
	cout << "4. Generate an individual student report." << endl;
	cout << "5. Exit program." << endl;
	cout << endl;	
	
	while (true) {
		cout << "Please enter the number of the option that you would like to select: ";
		//validates user input. first that an int was entered, then whether the int was between 1 & 5.
		if (!(cin >> menuOption)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please select a valid option between 1 and 5, and try again." << endl;
			continue;
		}

		if (menuOption >= 1 && menuOption <= 5) {
			break; 
		}
		else {
			cout << "Please select a valid option between 1 and 5, and try again." << endl;
		}
	}

	//selector for menu options
	switch (menuOption) {
	case 1:
		newStudent();
		break;
	case 2:
		newAssignment();
		break;
	case 3:
		enterGrade();
		break;
	case 4:
		studentReport();
		break;
	case 5:
		return;
	default:
		cout << "Please select a valid option and try again." << endl;
		return mainMenu();
		break;
	}
}

