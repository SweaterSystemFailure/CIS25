#include <iostream>
#include <cstring>
#include <iomanip>
#include "mainMenu.h"
#include "newStudent.h"
#include "inputCheck.h"
#include "teacherInfo.h"
#include "gradeLevel.h"
#include "newAssignment.h"
#include "enterGrade.h"
#include "globalVariables.h"
//Unsure if each header file needs to be referenced in the main file or only in the function that references it. Will clean up in next version, if necessary.
//To do: individual function calls should be grouped into a namespace.

using namespace std;


int main(){
	cout << "Welcome to your grade book!" << endl;
	cout << "Let's get started by entering some basic information." << endl;
	cout << endl;
	teacherFull = teacherInfo();
	grade = gradeLevel();
	cout << "This is now " << teacherFull << "'s Grade " << grade << " Book" << endl;
	cout << endl;
	mainMenu();
	return 0;
}