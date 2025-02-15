#pragma once
#include <string>
using namespace std;

// This is a bad way to store and share this information between fucntions. The next version of this project will replace this solution with a more robust class/objects system.
// credit to StackOverflow for teaching me about extern. 
// Mostly sure I'm doing this right. Unclear whether the definitions here work on their own, so I've also defined them the .cpp file with the same name


extern const short studentInfoSize = 6;
extern string studentInfo[studentInfoSize];									//stores student biographical info. 6 items tied to index location.
extern const short assignmentTotalSize = 10;								//this is a dummy value for the total number of assignments. In the next version, this should be dynamic.
extern string assignmentNames[assignmentTotalSize] = { "undefined" };		//this array holds the assignment names.
extern unsigned assignmentPointsPossible[assignmentTotalSize];				//this array holds the assignment values.
extern float assignmentPointsScored[assignmentTotalSize];					//this array holds the student scores.
extern char letterGrade;													//this char is for the student's overall letter grade. In the next version this will be an object within the student class.
extern string teacherFullName;												//this string is teacher's last name and title. 
extern unsigned gradeLev;