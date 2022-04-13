/* MacroCommand.cpp
Author: Catie Corley and Sam Lu
Purpose: defines the MacroCommand class which inherits form AbstractCommand interface. 
Executes each of the commands it is composed of in order.
*/

#include "MacroCommand.h"
#include <iostream>
#include <map>
#include <sstream>

// constructor 
MacroCommand::MacroCommand(AbstractFileSystem* a) {
	afs = a;
}

// displays info about macro commands 
void MacroCommand::displayInfo() {
	cout << "Macro commands are made up of many smaller commands and named as one command"  << endl; 
}

int MacroCommand::execute(string s) {
	// ask parsingstretegy to parse input (s) 
	// call execute on each individual command with corresponding input 
	// if any return an error, return an error 

	vector<string> strings = aps->parse(s);
	for (int i = 0; i < commands.size(); i++) {
		if (commands[i]->execute(strings[i]) != (int)outputs::SUCCESS) {
			return (int)outputs::UNSUCCESSFUL_EXECUTION;
		}
	}

	return (int)outputs::SUCCESS;
}

// adds new command to vector of Abstract Commands 
int MacroCommand::addCommand(AbstractCommand* a) {
	commands.push_back(a); 
	return (int)outputs::SUCCESS;
}

// setter for the parsing strategy used in execution 
int MacroCommand::setParseStrategy(AbstractParsingStrategy* a) {
	aps = a; 
	return (int)outputs::SUCCESS;
	
}
