#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace gradebook {

	unsigned unsignedValidator(const string& prompt, unsigned min, unsigned max);
	string stringValidator(const string& prompt);
	bool userCheck();

}
