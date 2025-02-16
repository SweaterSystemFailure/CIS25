#include <iostream>
#include <string>
#include <numeric>						//credit to StackOverflow for making me aware of this library. It is necessary to sum the array of floats on line 12.
#include "scorer.h"
#include "globalVariables.h"

using namespace std;

float scorer(){
	float score = 0;
	
	//creates decimal score of all assignments
	for (int j = 0; j < assignmentTotalSize; j++) {
		score += (assignmentPointsScored[j] / assignmentPointsPossible[j]);
	}

	//sets score to a number that is easy to interpret
	score * 100;

	//checks score for a grade
	if (score >= 90 && score <= 100) {
		letterGrade = 'A';
	}
	else if (score >= 80 && score < 90) {
		letterGrade = 'B';
	}
	else if (score >= 70 && score < 80) {
		letterGrade = 'C';
	}
	else if (score >= 60 && score < 70) {
		letterGrade = 'D';
	}
	else
		letterGrade = 'F';

	return score;
}