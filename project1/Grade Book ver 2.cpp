#include <iostream>
#include <string>
#include "mainMenu.h"
#include "teacherInfo.h"
#include "gradeLevel.h"
#include "globalVariables.h"
//To do: individual function calls should be grouped into a namespace.

using namespace std;


int main(){
	cout << "Welcome to your grade book!" << endl;
	cout << "Let's get started by entering some basic information." << endl;
	cout << endl;
	teacherInfo();
	gradeLevel();
	mainMenu();
	cout << "Goodbye!";
	return 0;
}