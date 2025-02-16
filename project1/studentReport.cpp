#include <iostream>
#include <iomanip>
#include <string>
#include "studentReport.h"
#include "globalVariables.h"
#include "scorer.h"
#include "mainMenu.h"

using namespace std;

void studentReport() {
	//if statement locks out if information isn't entered in menu options 1-3. Prevents dividing by zero and printing unintialized arrays
	if (studentInfo[0] == "Undefined" || assignmentNames[0] == "Undefined" || assignmentPointsPossible[0] == 0) {
		cout << "Please be sure to populate student information and assignment information before generating a student report." << endl;
		mainMenu();
	}
	else {
		//prints user populated date for final report
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << endl;
		cout << setw(40) << left << "Student: " << studentInfo[0] << endl;
		cout << setw(40) << left << "Grade: " << gradeLev << endl;
		cout << setw(40) << left << "Age: " << studentInfo[3] << endl;
		cout << setw(40) << left << "Student ID: " << studentInfo[1] << endl;
		cout << setw(40) << left << "Seat: " << studentInfo[2] << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << setw(40) << left << "Overall Score: " << setprecision(2) << scorer() << endl;			//calls scorer to calculate grades
		cout << setw(40) << left << "Overall Grade: " << letterGrade << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << endl;

		//loop prints assignment score recap with all data
		for (int i = 0; i < assignmentTotalSize; i++) {
			cout << fixed << "Assignment " << i + 1 << ", " << assignmentNames[i] << ": " << setprecision(2)<<  assignmentPointsScored[i] << "out of " << setprecision(2) 
			<< assignmentPointsPossible[i] << "." << endl;
		}

		cout << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << endl;
	}
	mainMenu();
}