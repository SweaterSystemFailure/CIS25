#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include "containers.h"
#include "utilities.h"
#include "containerFunctions.h"
#include "menuFunctions.h"


using namespace std;
using namespace gradebook;

void welcome(globalStorage& storage) {
	cout << "Welcome to your grade book!" << endl;
	cout << "Would you like to: " << endl;
	cout << "1. Create a new classroom." << endl;
	cout << "2. Load an existing classroom?" << endl;

	switch (unsignedValidator("Please enter the number of the option that you would like to select: [1-2]", 1, 2)) {
	case 1:
		storage.currentClass = classroom::createClassroom();
		break;
	case 2:
		// import file function
		break;
	default:
		cout << "It looks like something went wrong. Let's try again." << endl;
		welcome(storage);
	}
}

void mainMenu(globalStorage& storage) {
	//menu options
	cout << "Welcome to the main menu." << endl;
	cout << "From here you can enter student information and grades." << endl;
	cout << "Would you like to: " << endl;
	cout << endl;
	cout << "1. Enter new student information." << endl;
	cout << "2. View all students." << endl;
	cout << "3. Generate an individual student report." << endl;
	cout << "4. Create new assignments." << endl;
	cout << "5. View all assignements." << endl;
	cout << "6. Enter grades for an existing assignments." << endl;
	cout << "7. Export a report for your whole class to a .csv file" << endl;
	cout << "8. Save your work." << endl;
	cout << "9. Exit program." << endl;
	cout << endl;

	//selector for menu options
	switch (unsignedValidator("Please enter the number of the option that you would like to select: [1-9] ", 1, 9)) {
	case 1:
		addStudent(storage);
		break;
	case 2:
		printAllStudents(storage);
		break;
	case 3:
		printStudent(storage);
		break;
	case 4:
		addAssignment(storage);
		break;
	case 5:
		printAssignments(storage.assignments);
		break;
	case 6:
		enterGrades(storage);
		break;
	case 7:
		printCSV(storage);
		break;
	case 8:
		save(storage);
		break;
	case 9:
		return;
	default:
		cout << "Please select a valid option and try again." << endl;
		return mainMenu(storage);
		break;
	}
}