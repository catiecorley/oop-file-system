// declare AbstractParsingStragegy interface here. As all methods are virtual and will not be defined, no .cpp file is necessary

#pragma once

#include <vector>
#include <string>

using namespace std; 

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string s) = 0;
};