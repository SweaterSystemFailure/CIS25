#pragma once
#include <string>
using namespace std;

// This is a bad way to store and share this information between fucntions. The next version of this project will replace this solution with a more robust class/objects system.
// credit to StackOverflow for teaching me about extern. 
// Mostly sure I'm doing this right. Unclear whether the definitions here work on their own, so I've also defined them the .cpp file with the same name


extern const short studentInfoSize= 6;
extern string studentInfo[studentInfoSize];
extern const short assignmentTotalSize = 10;
extern string assignmentNames[assignmentTotalSize];
extern int assignmentPointsPossible[assignmentTotalSize];
extern float assignmentPointsScored[assignmentTotalSize];
extern float assignmentScore[assignmentTotalSize];
extern char letterGrade;
extern string teacherFull;
extern int grade;