#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "containerFunctions.h"
#include "menuFunctions.h"
#include "containers.h"

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
	} while (!userCheck("Does this look right to you ? [Y / N] ", "Great! Let's continue", "That's okay. Let's try again."));

	return myClass;
}

void printStudent(student& newStudent) {
		cout << "New Student Profile\n";
		cout << "------------------------\n";
		cout << "First Name      : " << newStudent.firstName << endl;
		cout << "Last Name       : " << newStudent.lastName << endl;
		cout << "Pronouns        : " << newStudent.pronouns << endl;
		cout << "Age             : " << newStudent.age << endl;
		cout << "Student ID      : " << newStudent.id << endl;
		cout << "Seat Location   : " << newStudent.seat << endl;
		cout << "Notes           : " << newStudent.notes << endl;
		cout << "------------------------\n" << endl;
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
		newStudent.notes = stringValidator("Enter any additional notes for this student: ");
		printStudent(newStudent);
	} while (!userCheck("Does this look right to you ? [Y / N] ", "Great! Let's continue", "That's okay. Let's try again."));

	storage.students.push_back(newStudent);
	cout << "Student " << newStudent.firstName << " " << newStudent.lastName << " has been added successfully!" << endl;
	cout << endl;
	if (userCheck("Would you like to add another student? ",
		"Okay, let's add another",
		"Returning to main menu.")) {
		addStudent(storage);
	}
	else {
		mainMenu(storage);
	}
	
}

void enterGrades(globalStorage& storage) {
	//storage checks
	if (storage.students.empty()) {
		cout << "No students in the system. Please add students first." << endl;
		return;
	}
	if (storage.assignments.empty()) {
		cout << "No assignments available to grade. Please add assignments first." << endl;
		return;
	}

	//select student
	cout << "Select a student to enter grades for:" << endl;
	for (size_t i = 0; i < storage.students.size(); ++i) {
		cout << i + 1 << ". " << storage.students[i].firstName << " " << storage.students[i].lastName << endl;
	}
	unsigned studentChoice = unsignedValidator("Enter the number of the student: ", 1, storage.students.size());
	student& selectedStudent = storage.students[studentChoice - 1];

	//grading choice
	cout << "Would you like to:" << endl;
	cout << "1. Enter grades for all assignments" << endl;
	cout << "2. Enter grade for one specific assignment" << endl;
	unsigned choice = unsignedValidator("Choose an option [1-2]: ", 1, 2);

	switch (choice) {
	case 1: {
		// Grade all assignments
		for (const auto& assign : storage.assignments) {
			float score = floatValidator("Enter score for \"" + assign.name + "\" (" + to_string(assign.pointsPossible) + " pts): ", 0.0f, assign.pointsPossible);
			selectedStudent.assignmentScores[assign.name] = score;
		}
		cout << "All grades for " << selectedStudent.firstName << " " << selectedStudent.lastName << " have been recorded." << endl;
		break;
	}
	case 2: {
		// Grade a single assignment
		cout << "Select an assignment:" << endl;
		for (size_t i = 0; i < storage.assignments.size(); ++i) {
			cout << i + 1 << ". " << storage.assignments[i].name << " (" << storage.assignments[i].pointsPossible << " pts)" << endl;
		}
		unsigned assignmentChoice = unsignedValidator("Enter the number of the assignment: ", 1, storage.assignments.size());
		assignment& selectedAssignment = storage.assignments[assignmentChoice - 1];

		float score = floatValidator("Enter score for \" + selectedAssignment.name + "\" (" + to_string(selectedAssignment.pointsPossible) + " pts): ", 0.0f, selectedAssignment.pointsPossible);
		selectedStudent.assignmentScores[selectedAssignment.name] = score;

		cout << "Grade recorded for " << selectedAssignment.name << "!" << endl;
		break;
	}
	default:
		cout << "Invalid choice, please try again." << endl;
		break;
	}
	scorer(storage, storage.assignments);
}

void printAllStudents(const globalStorage& storage) {
	if (storage.students.empty()) {
		cout << "No students in the system." << endl;
		return;
	}

	//sortable vector
	vector<student> sortedStudents = storage.students;

	// Bubble sort for alpha by last name
	for (size_t i = 0; i < sortedStudents.size(); ++i) {
		for (size_t j = 0; j < sortedStudents.size() - 1 - i; ++j) {
			if (sortedStudents[j].lastName > sortedStudents[j + 1].lastName ||
				(sortedStudents[j].lastName == sortedStudents[j + 1].lastName && sortedStudents[j].firstName > sortedStudents[j + 1].firstName)) {
				student temp = sortedStudents[j];
				sortedStudents[j] = sortedStudents[j + 1];
				sortedStudents[j + 1] = temp;
			}
		}
	}

	//Prints list
	cout << "List of students:" << endl;
	for (const auto& s : sortedStudents) {
		cout << s.firstName << " " << s.lastName << endl;
	}
}

void printAssignments(const vector<assignment>& assignments) {
	cout << "Assignments List:" << endl;
	if (assignments.empty()) {
		cout << "No assignments available." << endl;
	}
	else {
		for (const auto& assign : assignments) {
			cout << "Assignment: " << assign.name << " | Points Possible: " << assign.pointsPossible << endl;
		}
	}
}

void studentReport(globalStorage& storage) {
	scorer(storage); // makes sure grades are up to date

	//failstate check
	if (storage.students.empty()) {
		cout << "No students available. Please add student data first." << endl;
		mainMenu(storage);
	}

	//prints student list
	cout << "Select a student for the report:" << endl;
	for (size_t i = 0; i < storage.students.size(); ++i) {
		cout << i + 1 << ". " << storage.students[i].firstName << " " << storage.students[i].lastName << endl;
	}


	int choice = unsignedValidator("Enter the number of the student: ", 1, storage.students.size());
	student& selected = storage.students[choice - 1];

	cout << setfill('*') << setw(50) << "*" << endl;
	cout << setfill('*') << setw(50) << "*" << endl;
	cout << endl;
	cout << setw(40) << left << "Student: " << selected.firstName << " " << selected.lastName << endl;
	cout << setw(40) << left << "Age: " << selected.age << endl;
	cout << setw(40) << left << "Pronouns: " << selected.pronouns << endl;
	cout << setw(40) << left << "Student ID: " << selected.id << endl;
	cout << setw(40) << left << "Seat: " << selected.seat << endl;
	cout << setw(40) << left << "Notes: " << selected.notes << endl;
	cout << endl;

	if (!storage.assignments.empty() && !selected.assignmentScores.empty()) {
		cout << "Assignment Scores:" << endl;
		for (const auto& assignment : storage.assignments) {
			if (selected.assignmentScores.count(assignment.name)) {
				float scored = selected.assignmentScores.at(assignment.name);
				cout << assignment.name << ": " << scored << " out of " << assignment.pointsPossible << endl;
			}
			else {
				cout << assignment.name << ": No score entered." << endl;
			}
		}

		cout << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
		cout << setw(40) << left << "Overall Score: " << fixed << setprecision(2) << selected.totalScore << "%" << endl;
		cout << setw(40) << left << "Letter Grade: " << selected.letterGrade << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
	}
	else {
		cout << "No assignment or score data available for this student." << endl;
		cout << setfill('*') << setw(50) << "*" << endl;
	}
	cout << setfill('*') << setw(50) << "*" << endl << endl;
	mainMenu(storage);
}
