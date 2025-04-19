#include <iostream>
#include <string>
#include <vector>
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

void addStudent(globalStorage& storage) {
	student newStudent;

	do {
		newStudent.firstName = stringValidator("Please enter the student's first name: ");
		newStudent.lastName = stringValidator("Please enter the student's last name: ");
		newStudent.pronouns = stringValidator("Please enter the student's pronouns: ");
		newStudent.age = unsignedValidator("Please enter the student's age: ", 4, 19);
		newStudent.id = unsignedValidator("Please enter the student's ID number: ", 1, 9999);
		newStudent.seat = stringValidator("Please enter the student's seat location: ");
		newStudent.overallGrade = charValidator("Please enter the student's overall grade (A, B, C, D, or F): ", { 'A', 'B', 'C', 'D', 'F' });
		newStudent.gradePercent = floatValidator("Enter the student's grade percentage: ", 0.0f, 100.0f);
		newStudent.notes = stringValidator("Enter any additional notes for this student: ");
		printStudent(newStudent)
	} while (!userCheck());

	storage.students.push_back(newStudent);
	cout << "Student " << newStudent.firstName << " " << newStudent.lastName << " added successfully!" << endl;
}

void printStudent(student& newStudent) {
	cout << "New Student" << endl;
	cout << "First name: " << newStudent.firstName << endl;
	cout << "Last name: " << newStudent.lastName << endl;
	cout << "Student pronouns: " << newStudent.pronouns << endl;
	cout << "Student age: " << newStudent.age << endl;
	cout << "Student ID: " << newStudent.id << endl;
	cout << "Student seat: " << newStudent.seat << endl;
	cout << "Letter grade: " << newStudent.overallGrade << endl;
	cout << "Percentage grade: " << newStudent.gradePercent << endl;
	cout << "Notes: " << newStudent.notes << endl;
}