#include <iomanip>
#include <cstring>
#include "inputCheck.h"

using namespace std;

bool inputCheck() {
	char inputCheck;
	string result;
	bool isInputValid;

	cout << "Does this look right to you?[Y/N] " << endl;
	cin >> inputCheck;
	cout << endl;

	isInputValid =
		(inputCheck == 'Y' || inputCheck == 'y') ? true :
		(inputCheck == 'N' || inputCheck == 'n') ? false :
		false;

	result =
		(inputCheck == 'Y' || inputCheck == 'y') ? "Great. Let's continue." :
		(inputCheck == 'N' || inputCheck == 'n') ? "That's okay. Let's try again." :
		"That isn't a valid choice. Let's try again.";

	cout << result << endl;
	cout << endl;

	return isInputValid;
}