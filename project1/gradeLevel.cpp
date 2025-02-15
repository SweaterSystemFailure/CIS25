#include <iostream>
#include "gradeLevel.h"
using namespace std;

int gradeLevel() {
	int grade;
	bool isInputValid;

	cout << "Which grade do you teach? [1-12] ";					//Needs a solution for kindergarten.
	cin >> grade;

	isInputValid =
		(grade <= 1 || grade >= 12) ? false :
		true;

	if (isInputValid) {
		return grade;
	}
	else {
		cout << "Please enter a valid grade." << endl;
		cout << endl;
		return gradeLevel();
	}
}