// declare concrete class RenameParsingStrategy class here which will define the AbstractParsingStrategy interface

#pragma once
#include "AbstractParsingStrategy.h"
#include <vector>
#include <string>
using namespace std;

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	vector<string> parse(string s);
};