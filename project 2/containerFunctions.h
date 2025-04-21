#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include "containers.h"

using namespace std;

namespace gradebook {
	void addStudent(globalStorage& storage);
	void printStudent(student& newStudent);
	void addAssignment (globalStorage& storage);
	void enterGrades(globalStorage& storage);
	void printAllStudents(const globalStorage& storage);
	void printAssignments(const vector<assignment>& assignments);
	classroom createClassroom();

}
