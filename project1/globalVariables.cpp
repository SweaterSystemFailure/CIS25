#include "globalVariables.h"
#include <string>
using namespace std;

	unsigned int studentInfoSize = 6;					//This is a dummy variable for student variable array size
	unsigned int assignmentTotalSize = 10;				//This is a dummy variable for the assignment variable array size
	unsigned int gradeLev = 0;							//null intialization
	char letterGrade = 'F';								//default initialization
	string teacherFullName = "Undefined";				//default initialization
	string studentInfo[] = { "Undefined" };				//first position initalized as an error check for studentReport
	string assignmentNames[] = { "Undefined" };			//first position initalized as an error check for studentReport
	float assignmentPointsPossible[] = { 0 };			//first position initalized as an error check for studentReport
	float assignmentPointsScored[] = { 0 };				//first position initalized as an error check for studentReport