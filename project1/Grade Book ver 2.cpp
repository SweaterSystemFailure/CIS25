#include <iostream>
#include <string>
#include "mainMenu.h"
#include "teacherInfo.h"
#include "gradeLevel.h"
#include "globalVariables.h"
//To do: individual function calls should be grouped into a namespace.

using namespace std;


int main(){
	teacherInfo();
	mainMenu();
	cout << "Goodbye!";
	return 0;
}