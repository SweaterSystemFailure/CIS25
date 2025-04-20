#pragma once
#include <string>
#include <vector>
#include <map>

namespace gradebook {
	void addStudent(globalStorage& storage);
	void printStudent(student& newStudent);
	void addAssignment(globalStorage& assignment);
	void enterGrades(globalStorage& storage);
	void printAllStudents(const globalStorage& storage);
	void printAssignments(const vector<assignment>& assignments);

}
