#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "utilities.h"
#include "containerFunctions.h"
#include "menuFunctions.h"
#include "containers.h"


using namespace std;
using namespace gradebook;

unsigned unsignedValidator(const string& prompt, unsigned min, unsigned max) {
	unsigned number;
	while (true) {
		cout << prompt << endl;
		cin >> number;
		if (cin.fail()) {
			cout << "Enter a valid number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (number < min || number > max) {
			cout << "Number must be between " << min << " and " << max << "." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	return number;
}

string stringValidator(const string& prompt) {
	string userInput;
	while (true) {
		cout << prompt;
		getline(cin, userInput);
		if (userInput.empty()) {
			cout << "Invalid input. This field can't be empty. Try again: " << endl;
		}
		else {
			return userInput;
		}
	}
}

bool userCheck(const string& prompt, const string& yesPrompt, const string& noPrompt) {
	char choice;
	bool check = true;
	while (!check) {
		cout << prompt << endl;
		cin >> choice;
		choice = tolower(choice);
		cin.ignore();

		if (choice == 'y') {										//user agreement sets bool to false for external logic check
			cout << yesPrompt << endl;
			cout << endl;
			return check;
		}
		else if (choice == 'n') {									//user disagreement sets bool to false for external logic check
			cout << noPrompt<< endl;
			cout << endl;
			check = false;
			return check;
		}
		else {														//invalid input statement runs the loop again
			cout << "Invalid input. Please enter y or n." << endl;
			cout << endl;
		}
	}
}

char charValidator(const string& prompt, const vector<char>& validOptions) {
	char input;
	while (true) {
		cout << prompt << endl;
		cin >> input;
		input = tolower(input);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (char option : validOptions) {
			if (tolower(option) == input) {
				return input;
			}
		}

		cout << "Invalid input. Please enter one of the following: ";
		for (char option : validOptions) {
			cout << option << " ";
		}
		cout << endl;
	}
}

float floatValidator(const string& prompt, float min, float max) {
	float number;
	while (true) {
		cout << prompt << endl;
		cin >> number;

		if (cin.fail()) {
			cout << "Please enter a valid number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (number < min || number > max) {
			cout << "Number must be between " << min << " and " << max << "." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number;
		}
	}
}

void scorer(globalStorage& storage, const vector<assignment>& assignments) {
	for (auto& s : storage.students) {
		float totalPointsPossible = 0.0f;
		float totalPointsScored = 0.0f;

		//Points possible and scored calculators
		for (const auto& assign : assignments) {
			totalPointsPossible += assign.pointsPossible;
			totalPointsScored += assign.pointsPossible; 
		}

		//Percentage calculator
		if (totalPointsPossible > 0) {
			s.gradePercent = (totalPointsScored / totalPointsPossible) * 100.0f;
		}

		//Letter grade calculator
		if (s.gradePercent >= 90.0f) {
			s.overallGrade = 'A';
		}
		else if (s.gradePercent >= 80.0f) {
			s.overallGrade = 'B';
		}
		else if (s.gradePercent >= 70.0f) {
			s.overallGrade = 'C';
		}
		else if (s.gradePercent >= 60.0f) {
			s.overallGrade = 'D';
		}
		else {
			s.overallGrade = 'F';
		}
	}
}