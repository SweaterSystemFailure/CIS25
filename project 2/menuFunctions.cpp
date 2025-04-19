#include <iostream>
#include <string>
#include "menuFunctions.h"
#include "containerFunctions.h"
#include "utilities.h"

using namespace std;
using namespace gradebook;

void welcome() {
	cout << "Welcome to your grade book!" << endl;
	cout << "Would you like to: " << endl;
	cout << "1. Create a new classroom." << endl;
	cout << "2. Load an existing classroom?" << endl;

	switch (unsignedValidator("Please enter the number of the option that you would like to select: [1-2]", 1, 2)) {
	case 1: 
		classroom myNewClass = classroom::createClassroom();
		break;
	case 2:
		//import file function
		break;
	default:
		cout << "It looks like something went wrong. Let's try again." << endl;
		welcome();
	}
}

void mainMenu() {
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

	//selector for menu options
	switch (unsignedValidator("Please enter the number of the option that you would like to select: [1-5] ", 1, 5)) {
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