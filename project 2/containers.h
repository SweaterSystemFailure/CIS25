#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

using namespace std;

namespace gradebook {
	struct classroom {
		std::string title;
		std::string firstName;
		std::string lastName;
		unsigned gradeLevel;
	};

	struct student {
		//biographical
		std::string firstName;
		std::string lastName;
		std::string pronouns;
		unsigned age;
		unsigned id;
		std::string seat;
		std::string notes;

		//grades
		char overallGrade;
		float gradePercent;
		std::map<std::string, float> assignmentScores;	//keyed to assignment name. value is the score
	};

	struct assignment {
		std::string name;
		float pointsPossible;
	};

	struct globalStorage {
		std::vector<gradebook::student> students; //stores students
		std::vector<gradebook::assignment> assignments; //stores assignments
		classroom currentClass; //stores teacher & class info
	};
}
