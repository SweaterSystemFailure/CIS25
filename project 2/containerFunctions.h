#pragma once
#include <string>

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
		string fullName = firstName + " " + lastName;
		string pronouns;
		unsigned age;
		unsigned id;
		string seat;
		char overallGrade;
		float gradePercent;
		string notes;
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

}