#include <iostream>
#include <string>
#include "utilities.h"
#include "containerFunctions.h"
#include "menuFunctions.h"

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

bool userCheck() {
	char choice;
	bool check = true;
	while (!check) {
		cout << "Does this look right to you?[Y/N] " << endl;
		cin >> choice;
		choice = tolower(choice);
		cin.ignore();

		if (choice == 'y') {
			cout << "Great. Let's continue." << endl;
			cout << endl;
			return check;
		}
		else if (choice == 'n') {									//user disagreement allows them to try again
			cout << "That's okay. Let's try again." << endl;
			cout << endl;
			check = false;
			return check;
		}
		else {														//invalid input statement
			cout << "Invalid input. Please enter y or n." << endl;
			cout << endl;
			check = false;
			return check;
		}
	}
}
