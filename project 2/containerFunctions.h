#pragma once
#include <string>
#include <vector>

namespace gradebook {

	struct classroom {
		std::string title;
		std::string firstName;
		std::string lastName;
		unsigned gradeLevel;

		static classroom createClassroom();
	};

	struct student {
		std::string firstName;
		std::string lastName;
		std::string pronouns;
		unsigned age;
		unsigned id;
		std::string seat;
		char overallGrade;
		float gradePercent;
		std::string notes;
	};

	struct studentScore {
		float pointsEarned;
		float numericalScore;
		char letterGrade;
	};

	struct assignment {
		std::string name;
		float pointsPossible;
		studentScore studentScore;
	};

	struct assignmentCategory {
		std::string name;
		unsigned numberOfAssignments;
		float weightMultiplier;
		assignment assignment;
	};

	struct globalStorage {
		std::vector<gradebook::student> students;
		classroom currentClass;
	};

	void addStudent(globalStorage& storage);
	void printStudent(student& newStudent);
}
