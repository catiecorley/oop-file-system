/* CatAndDsParsingStrategy.cpp
Author: Catie Corley and Sam Lu
Purpose: Defines the additional MacroCommand which allows user to edit a file and then display it afterwards to see the edits.
*/

#include "CatAndDsParsingStrategy.h"

// parses input string for filename and correct formatting, along with add ons -a and -d, returns vector ofstring inputs, or invalid 
// inputs if invalid 
vector<string> CatAndDsParsingStrategy::parse(string s) {
	vector<string> parsedString; 
	vector<string> invalidInput; 
	invalidInput.push_back("invalid");
	invalidInput.push_back("invalid"); 
	int space = s.find(' '); 
	if (space == -1) {
		parsedString.push_back(s);
		parsedString.push_back(s); 
	}
	else {
		string filename = s.substr(0, space); 
		string secondpart = s.substr(space + 1); 
		int secondspace = secondpart.find(' '); 
		if (secondspace == -1) {
			if (secondpart == "-a") {
				parsedString.push_back(s);
				parsedString.push_back(filename); 
			}
			else if (secondpart == "-d") {
				parsedString.push_back(filename); 
				parsedString.push_back(s);
			}
			else {
				return invalidInput;
			}
		}
		else {
			string firstadd = secondpart.substr(0, secondspace); 
			string secondadd = secondpart.substr(secondspace + 1); 
			if (firstadd != "-a" || secondadd != "-d") { // only supports -a followed by -d, -d -a will not work
				return invalidInput; 
			}
			else {
				parsedString.push_back(filename + ' ' + firstadd);
				parsedString.push_back(filename + ' ' + secondadd);
			}
		}
	}
	return parsedString; 
}