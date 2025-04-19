#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace gradebook {

	unsigned unsignedValidator(const string& prompt, unsigned min, unsigned max);
	std::string stringValidator(const string& prompt);
	bool userCheck();
	char charValidator(const string& prompt, const vector<char>& validOptions);
	float floatValidator(const string& prompt, float min, float max)

}
