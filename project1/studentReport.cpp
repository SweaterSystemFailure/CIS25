#include <iostream>
#include <iomanip>
#include "studentReport.h"
#include "globalVariables.h"
#include "scorer.h"
#include "mainMenu.h"

using namespace std;

void studentReport() {
	if (studentInfo[0] == "undefined" || assignmentNames[0] == "undefined" || assignmentPointsPossible[0] == 0) {
		cout << "Please be sure to populate student information and assignment information before generating a student report." << endl;
		mainMenu();
	}
	else {
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << endl;
		cout << setw(40) << left << "Student: " << studentInfo[0] << endl;
		cout << setw(40) << left << "Grade: " << gradeLev << endl;
		cout << setw(40) << left << "Age: " << studentInfo[3] << endl;
		cout << setw(40) << left << "Student ID: " << studentInfo[1] << endl;
		cout << setw(40) << left << "Seat: " << studentInfo[2] << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << setw(40) << left << "Overall Score: " << setprecision(2) << scorer() << endl;
		cout << setw(40) << left << "Overall Grade: " << letterGrade << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << endl;

		for (int i = 0; i < assignmentTotalSize; i++) {
			cout << "Assignment " << i + 1 << ", " << assignmentNames[i] << ": " << assignmentPointsScored[i] << "out of " << assignmentPointsPossible[i] << "." << endl;
		}

		cout << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << endl;
	}
	mainMenu();
}