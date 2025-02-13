#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int mainMenu(string[], const short);
int gradeLevel();
bool inputCheck();
string teacherInfo();
int newStudent(string[], const short);
void newAssignment();
void enterGrade();
void studentReport();

int main()
{	int numberOfStudents;
	short grade;
	const short size = 6;
	string teacherFull;
	string studentInfo[size];
	
	cout << "Welcome to your grade book!" << endl;
	cout << "Let's get started by entering some basic information." << endl;
	cout << endl;
	teacherFull = teacherInfo();
	grade = gradeLevel();
	cout << "This is now " << teacherFull << "'s Grade " << grade << " Book" << endl;
	cout << endl;
	mainMenu(studentInfo[], size);
	return 0;
}

int mainMenu(string studentInfo[], const short size) {
	char menuOption;
	string stundent[6];
	for (short i = 6; i > 0; i--) {
		stundent[i] = studentInfo[i];
	}
	

	cout << "Welcome to the main menu." << endl;
	cout << "From here you can enter student information and grades." << endl;
	cout << "Would you like to: " << endl;
	cout << endl;
	cout << "1. Enter new student information." << endl;
	cout << "2. Create a new assignment." << endl;
	cout << "3. Enter a grade for an existing assingment." << endl;
	cout << "4. Generate an individual student report." << endl;
	cout << "5. Exit program." << endl;
	cout << endl;
	cout << "Please enter the number of the option that you would like to select: ";
	cin >> menuOption;
	cout << endl;

	switch (menuOption) {
	case '1':
		newStudent(stundent[], size);
		break;
	case '2':
		newAssignment();
		break;
	case '3':
		enterGrade();
		break;
	case '4':
		studentReport();
		break;
	case '5':
		return 0;
		break;
	default:
		cout << "Please select a valid option and try again." << endl;
		mainMenu(stundent[], size);
		break;
	}
}

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

string teacherInfo() {
	string honorific, teacherLast, teacherFull, result;

	cout << "What honorific do your students address you by? [Ms., Mrs., Mr., Dr., etc] ";
	cin >> honorific;
	cout << "What is your last name? ";
	cin >> teacherLast;
	teacherFull = honorific + " " + teacherLast;
	cout << "Hi " << teacherFull << "!" << endl;

	if (inputCheck()) {
		return teacherFull;
	}
	else {
		return teacherInfo();
	}
}

int gradeLevel() {
	int grade;
	bool isInputValid;

	cout << "Which grade do you teach? [1-12] ";					//Needs a solution for kindergarten.
	cin >> grade;

	isInputValid =
		(grade <= 1 || grade >= 12) ? false :
		true;

	if (isInputValid) {
		return grade;
	}
	else {
		cout << "Please enter a valid grade." << endl;
		cout << endl;
		return gradeLevel();
	}
}

int newStudent(string studentInfo[], const short size) {
	string firstName, lastName, fullName, seat,age, studentID;
	const int size1 = size;


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
		mainMenu(studentInfo, size);
	}
	else {
		newStudent(studentInfo[], size1);
	}

}
void newAssignment() {

}
void enterGrade() {

}
void studentReport() {

}