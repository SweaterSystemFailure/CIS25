#include <iostream>
#include <iomanip>
#include <string>
#include "newStudent.h"
#include "mainMenu.h"
#include "globalVariables.h"

using namespace std;

void newStudent() {
	string firstName, lastName, fullName, seat, actualAge, actualSID;
	unsigned age, studentID;
	char choice;

	cout << "Let's start by collecting some information about this student." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//collects student first name
	while (true) {
		cout << "What is this student's first name? ";
		getline(cin, firstName);
		if (firstName.empty()) {
			cout << "Invalid input. Can't be empty. Try again: " << endl;
		}
		else {
			break;
		}
	}

	cout << endl;

	//collects student last name
	while (true) {
		cout << "What is this student's last name? ";
		getline(cin, lastName);
		if (lastName.empty()) {
			cout << "Invalid input. Can't be empty. Try again: " << endl;
		}
		else {
			break;
		}
	}

	//combines student name for storage later
	cout << endl;
	fullName = firstName + " " + lastName;

	//collects age
	while (true) {
		cout << "How old is this student?[4-18] " << endl;
		cin >> age;
		cin.ignore();
		if (cin.fail() || age < 4 || age > 18) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid age." << endl;
		}
		else {
			break;
		}
	}

	cout << endl;

	//collects seat info. alphanumeric for teacher who use a grid layout (eg: 14c)
	while (true) {
		cout << "What is this student's seating position? ";
		getline(cin, seat);
		if (seat.empty()) {
			cout << "Invalid input. Can't be empty. Try again: " << endl;
		}
		else {
			break;
		}
	}

	cout << endl;

	//collects ID number
	while (true) {
		cout << "Finally, what is this student's ID number? " << endl;
		cin >> studentID;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid ID number." << endl;
		}
		else {
			break;
		}
	}

	//prints student biographicals for user validation
	cout << endl;
	cout << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill(' ') << setw(50) << " " << endl;
	cout << setw(40) << left << "Student: " << fullName << endl;
	cout << setw(40) << left << "Grade: " << gradeLev << endl;
	cout << setw(40) << left << "Age: " << age << endl;
	cout << setw(40) << left << "Student ID: " << studentID << endl;
	cout << setw(40) << left << "Seat: " << seat << endl;
	cout << setfill(' ') << setw(50) << " " << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << endl;

	//user validation
	while (true) {
		cout << "Does this look right to you?[Y/N] " << endl;
		cin >> choice;
		choice = tolower(choice);

		if (choice == 'y') {											//user agreement stores biographicals to array
			actualAge = to_string(age);
			actualSID = to_string(studentID);
			studentInfo[0] = fullName;
			studentInfo[1] = actualSID;
			studentInfo[2] = seat;
			studentInfo[3] = actualAge;
			studentInfo[4] = firstName;
			studentInfo[5] = lastName;
			cout << "Great. Let's go back to the main menu." << endl;
			cout << endl;
			break;
		}
		else if (choice == 'n') {										//user disagreement allows a redo off all info. Ideally, this should be more precise.
			cout << "That's okay. Let's try again." << endl;
			cout << endl;
			return newStudent();
		}
		else {															//check for invalid input
			cout << "Invalid input. Please enter Y or N." << endl;
			cout << endl;
		}
	}
	mainMenu();															//routes back to main
}