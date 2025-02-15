#include <iostream>
#include <iomanip>
#include <cstring>
#include "mainMenu.h"
#include "newStudent.h"
#include "inputCheck.h"
using namespace std;

void mainMenu(string studentInfo[], const short size) {
	char menuOption;

	cout << "Welcome to the main menu." << endl;
	cout << "From here you can enter student information and grades." << endl;
	cout << "Would you like to: " << endl;
	cout << endl;
	cout << "1. Enter new student information." << endl;
	cout << "2. Create a new assignment." << endl;
	cout << "3. Enter a grade for an existing assingment." << endl;
	cout << "4. Generate an individual student report." << endl;
	cout << "5. Exit program." << endl;
	cout << endl;
	cout << "Please enter the number of the option that you would like to select: ";
	cin >> menuOption;
	cout << endl;

	switch (menuOption) {
	case '1':
		newStudent();
		break;
	case '2':
		newAssignment();
		break;
	case '3':
		enterGrade();
		break;
	case '4':
		studentReport();
		break;
	case '5':
		return 0;
		break;
	default:
		cout << "Please select a valid option and try again." << endl;
		mainMenu();
		break;
	}
}
