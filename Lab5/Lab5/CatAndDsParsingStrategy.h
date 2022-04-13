// declare CatandDsParsingStrategy interface here. Used to add additional funcitonality to the MacroCommand class.

#pragma once
#include "../../SharedCode/AbstractParsingStrategy.h"
#include <vector>
#include <string>

class CatAndDsParsingStrategy : public AbstractParsingStrategy {
public:
	vector<string> parse(string s); 
};