#include <iostream>
#include <string>
#include "utilities.h"
#include "containerFunctions.h"
#include "menuFunctions.h"

using namespace std;
using namespace gradebook;

classroom classroom::createClassroom() {
	classroom myClass;
	cout << "Let's get started by entering some basic information." << endl;

	do {
		myClass.title = stringValidator("Which honorific do your students address you by? [Ms., Mrs., Mr., Dr., etc]");
		myClass.firstName = stringValidator("What is your first name?");
		myClass.lastName = stringValidator("What is your last name?");
		myClass.gradeLevel = unsignedValidator("Which grade do you teach? [1–12]", 1, 12);

		cout << "This is " << myClass.title << " " << myClass.firstName << " " << myClass.lastName
			<< "'s grade " << myClass.gradeLevel << " book." << endl;
	} while (!userCheck());

	return myClass;
}