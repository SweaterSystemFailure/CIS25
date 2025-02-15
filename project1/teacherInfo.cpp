#include <iostream>
#include <cstring>
#include "teacherInfo.h"

using namespace std;

string teacherInfo() {
	string honorific, teacherLast, teacherFull, result;

	cout << "What honorific do your students address you by? [Ms., Mrs., Mr., Dr., etc] ";
	cin >> honorific;
	cout << "What is your last name? ";
	cin >> teacherLast;
	teacherFull = honorific + " " + teacherLast;
	cout << "Hi " << teacherFull << "!" << endl;

	return teacherFull;
}