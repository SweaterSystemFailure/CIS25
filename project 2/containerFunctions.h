#pragma once
#include <string>
#include <vector>

namespace gradebook {

	struct classroom {
		string title;
		string firstName;
		string lastName;
		unsigned gradeLevel;

		static classroom createClassroom();
	};

	struct student {
		string firstName;
		string lastName;
		string pronouns;
		unsigned age;
		unsigned id;
		string seat;
		char overallGrade;
		float gradePercent;
		string notes;

		static void addStudent(std::vector<student>& students);
		static void printStudent(student& newStudent);
	};

	struct assignment {
		string name;
		float pointsPossible;
	};

	struct assignmentCategory {
		string name;
		unsigned numberOfAssignments;
		float weightMultiplier;
		assignment assignment;
	};

	struct globalStorage {
		std::vector<gradebook::student> students;
		classroom currentClass;
	};
}