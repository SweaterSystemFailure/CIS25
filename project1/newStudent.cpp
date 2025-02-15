#include <iostream>
#include <iomanip>
#include <string>
#include "newStudent.h"
#include "mainMenu.h"
#include "inputCheck.h"
#include "globalVariables.h"

using namespace std;

void newStudent() {
	string firstName, lastName, fullName, seat;
	unsigned age, studentID;
	char choice;

	cout << "Let's start by collecting some information about this student." << endl;
	
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
	
	fullName = firstName + " " + lastName;

	while (true) {
		cout << "How old is this student?[4-18] " << endl;
		cin >> age;
		if (cin.fail() || age < 4 || age > 18) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid age." << endl;
		}
		else {
			break;
		}
	}

	//I went back and forth about defining seating position as an unsigned, but I know some teachers who used alphanumeric identifiers for their seating chart so a less percise string is warranted here.
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

	while (true) {
		cout << "Finally, what is this student's ID number? " << endl;
		cin >> age;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid ID number." << endl;
		}
		else {
			break;
		}
	}

	cout << endl;
	cout << endl;

	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill(' ') << setw(50) << " " << endl;
	cout << setw(40) << left << "Student: " << fullName << endl;
	cout << setw(40) << left << "Grade: " << grade << endl;
	cout << setw(40) << left << "Age: " << age << endl;
	cout << setw(40) << left << "Student ID: " << studentID << endl;
	cout << setw(40) << left << "Seat: " << seat << endl;
	cout << setfill(' ') << setw(50) << " " << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << endl;

	while (true) {
		cout << "Does this look right to you?[Y/N] " << endl;
		cin >> choice;
		choice = tolower(choice);

		if (choice == 'y') {
			cout << "Great. Let's go back to the main menu." << endl;
			studentInfo[0] = fullName;
			studentInfo[1] = studentID;
			studentInfo[2] = seat;
			studentInfo[3] = age;
			studentInfo[4] = firstName;
			studentInfo[5] = lastName;
			break;
		}
		else if (choice == 'n') {
			cout << "That's okay. Let's try again." << endl;
			newStudent();
		}
		else {
			cout << "Invalid input. Please enter Y or N." << endl;
		}
		
		mainMenu();
}