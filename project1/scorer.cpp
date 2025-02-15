#include <iostream>
#include "scorer.h"
#include "globalVariables.h">

using namespace std;

int scorer(){
	float score;
	for (int j = 0; j < assignmentTotalSize; j++) {
		score += assignmentPointsScored[j] / assignmentPointsPossible[j];
	}
	score / assignmentTotalSize;

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