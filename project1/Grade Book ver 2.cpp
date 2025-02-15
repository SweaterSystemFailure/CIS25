#include <iostream>
#include <string>
#include "mainMenu.h"
#include "teacherInfo.h"
#include "gradeLevel.h"
#include "globalVariables.h"
//To do: individual function calls should be grouped into a namespace.

using namespace std;


int main(){
	studentInfoSize = 6;
	assignmentTotalSize = 10;
	gradeLev = 0;
	letterGrade = 'F';
	teacherFullName = "Undefined";

	for (int i = 0; i < studentInfoSize; i++) {
		studentInfo[i] = "Undefined";
	}

	for (int j = 0; j < assignmentTotalSize; j++) {
		assignmentNames[j] = "Undefined";
		assignmentPointsPossible[j] = 0;
		assignmentPointsScored[j] = 0;
	}


	cout << "Welcome to your grade book!" << endl;
	cout << "Let's get started by entering some basic information." << endl;
	cout << endl;
	teacherInfo();
	gradeLevel();
	cout << "This is now " << teacherFullName << "'s Grade " << gradeLev << " Book" << endl;
	cout << endl;
	mainMenu();
	cout << "Goodbye!";
	return 0;
}