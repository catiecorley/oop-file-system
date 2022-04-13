/* RenameParsingStrategy.cpp
Author: Catie Corley and Sam Lu
Purpose: defines the interface provided by AbstractParsingStrategy
*/
#include "RenameParsingStrategy.h"

// sets parsing strategy as the entire string, followed by the filename part of the string 
vector<string> RenameParsingStrategy::parse(string s) {
	vector<string> parsedString;
	parsedString.push_back(s);
	int space = s.find(' ');
	parsedString.push_back(s.substr(0, space));
	return parsedString;
}