#include <iostream>
#include <cstring>
#include <string>
#include "stringInputValidation.h"

using namespace std;

string stringInputValidation(string test) {
	while (true) {
		getline(cin, test);
		if (test.empty()) {
			cout << "Invalid input. Can't be empty. Try again: " << endl;
		}
		else {
			break;
		}
	}
	return test;
}
