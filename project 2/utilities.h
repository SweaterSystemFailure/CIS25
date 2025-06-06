#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include "containers.h"


using namespace std;
namespace gradebook {

	unsigned unsignedValidator(const std::string& prompt, unsigned min, unsigned max);
	std::string stringValidator(const std::string& prompt);
	bool userCheck(const string& prompt, const string& yesPrompt, const string& noPrompt);
	char charValidator(const std::string& prompt, const std::vector<char>& validOptions);
	float floatValidator(const std::string& prompt, float min, float max);
	void scorer(globalStorage& storage, const vector<assignment>& assignments);

}