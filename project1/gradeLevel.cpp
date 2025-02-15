#include <iostream>
#include "gradeLevel.h"
#include "globalVariables.h"
using namespace std;

int gradeLevel() {
	unsigned grade;
	
	cin >> grade;
	while (true) {
		cout << "Which grade do you teach? [1-12] " << endl;					//Needs solutions for K & pre-K.
		cin >> grade;
		if (cin.fail() || grade <= 1 || grade >= 12) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a grade between 1 & 12." << endl;
		}
		else {
			break;
		}
	}
		return gradeLevel();
	}
}