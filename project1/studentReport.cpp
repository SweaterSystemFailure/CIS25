#include <iostream>
#include <iomanip>
#include "studentReport.h"
#include "globalVariables.h"

using namespace std;

void studentReport() {
	float score;
	for (int j = 0; j < assignmentTotalSize; j++) {
		score += assignmentPointsScored[j] / assignmentPointsPossible[j];
	}
	score / assignmentTotalSize;
	
	if (score >= 90 && score <= 100) {
		letterGrade = 'A';
	}
	else if (score >= 80 && score < 90) {
		letterGrade = 'B';
	}
	else if (score >= 70 && score < 80) {
		letterGrade = 'C';
	}
	else if (score >= 60 && score < 70) {
		letterGrade = 'D';
	}
	else
		letterGrade = 'F';

	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << endl;
	cout << setw(40) << left << "Student: " << studentInfo[0] << endl;
	cout << setw(40) << left << "Grade: " << gradeLev << endl;
	cout << setw(40) << left << "Age: " << studentInfo[3] << endl;
	cout << setw(40) << left << "Student ID: " << studentInfo[1] << endl;
	cout << setw(40) << left << "Seat: " << studentInfo[2] << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setw(40) << left << "Overall Grade: " << letterGrade<< endl;
	cout << setw(40) << left << "Overall Score: " << setprecision(2) << score << endl;
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