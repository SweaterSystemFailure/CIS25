#include <iomanip>
#include <cstring>
#include "newStudent.h"
#include "mainMenu.h"
#include "inputCheck.h"

using namespace std;

void newStudent() {
	string firstName, lastName, fullName, seat, age, studentID;

	cout << "Let's start by collecting some information about this student." << endl;
	cout << "What is this student's first name? ";
	cin >> firstName;
	cout << "What is this student's last name? ";
	cin >> lastName;
	fullName = firstName + " " + lastName;
	cout << "Which seat does this student sit in your classroom? ";
	cin >> seat;
	cout << "What is this student's ID number? ";
	cin >> studentID;
	cout << "Finally, how old is this student? ";
	cin >> age;
	cout << endl;
	cout << endl;

	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill(' ') << setw(50) << " " << endl;
	cout << setw(40) << left << "Student: " << fullName << endl;
	cout << setw(40) << left << "Student ID: " << studentID << endl;
	cout << setw(40) << left << "Seat: " << seat << endl;
	cout << setw(40) << left << "Age: " << age << endl;
	cout << setfill(' ') << setw(50) << " " << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;

	if (inputCheck()) {
		studentInfo[0] = fullName;
		studentInfo[1] = studentID;
		studentInfo[2] = seat;
		studentInfo[3] = age;
		studentInfo[4] = firstName;
		studentInfo[5] = lastName;
		mainMenu();
	}
	else {
		newStudent();
	}

}