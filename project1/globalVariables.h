#pragma once
#include <string>
using namespace std;

// This is a bad way to store and share this information between fucntions. The next version of this project will replace this solution with a more robust class/objects system.
// credit to StackOverflow for teaching me about extern. 

extern unsigned studentInfoSize;
extern string studentInfo[6];								//stores student biographical info. 6 items tied to index location.
extern unsigned assignmentTotalSize;						//this is a dummy value for the total number of assignments. In the next version, this should be dynamic.
extern string assignmentNames[10];							//this array holds the assignment names.
extern float assignmentPointsPossible[10];					//this array holds the assignment values.
extern float assignmentPointsScored[10];					//this array holds the student individual assignment scores.
extern char letterGrade;									//this char is for the student's overall letter grade. In the next version this will be an object within the student class.
extern string teacherFullName;								//this string is teacher's last name and title. 
extern unsigned gradeLev;									//this variable stores the class's grade level.