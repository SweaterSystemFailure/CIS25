#include <iostream>
#include "enterGrade.h"
#include "globalVariables.h"
#include "mainMenu.h"

using namespace std;

void enterGrade() {
	string assignmentName;
	unsigned pointsPossible;
	
	if (assignmentNames[0] == "undefined") {
		cout << "Please create new assignments before grading them." << endl;
		mainMenu();
	}
	else {
		for (int i = 0; i < assignmentTotalSize; i++) {
			assignmentName = "undefined";
			pointsPossible = 0;
			while (true) {
				cout << "How many points were earned on " << assignmentNames[i] << "?" << endl;
				getline(cin, assignmentName);
				if (assignmentName.empty()) {
					cout << "Invalid input. Can't be empty." << endl;
				}
				else {
					assignmentNames[i] = assignmentName;
					break;
				}
				bool check = false;
			}
		}
	}
