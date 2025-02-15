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

using namespace std;

const short studentInfoSize = 6;
string studentInfo[studentInfoSize];
const short assignmentTotalSize = 10;
string assignmentNames[assignmentTotalSize];
int assignmentPointsPossible[assignmentTotalSize];
float assignmentPointsScored[assignmentTotalSize];
float assignmentScore[assignmentTotalSize];
char letterGrade;

int main(){
	string teacherFull;
	int grade;
	
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