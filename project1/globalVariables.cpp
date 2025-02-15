#include <string>
#include "globalVariables.h"
using namespace std;

const short studentInfoSize = 6;								
string studentInfo[studentInfoSize];							//stores student biographical info. 6 items tied to index location.
const short assignmentTotalSize = 10;							//this is a dummy value for the total number of assignments. In the next version, this should be dynamic.
string assignmentNames[assignmentTotalSize];					//this array holds the assignment names.
unsigned assignmentPointsPossible[assignmentTotalSize];			//this array holds the assignment values.
float assignmentPointsScored[assignmentTotalSize];				//this array holds the student scores.
char letterGrade;												//this char is for the student's overall letter grade. In the next version this will be an object within the student class.
string teacherFull;												//this string is teacher's full name and title. 
unsigned grade;													//this variable holds the class's numerical grade (eg: 6th grade).