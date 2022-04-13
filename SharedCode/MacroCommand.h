// declare MacroCommand class here which allows commands to be constructed out of other commands
#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <vector>


class MacroCommand : public AbstractCommand {
	vector<AbstractCommand*> commands;
	AbstractParsingStrategy* aps;
	AbstractFileSystem* afs;
public:
	MacroCommand(AbstractFileSystem* a); 
	int execute(string s);
	void displayInfo();
	int addCommand(AbstractCommand* a); //int return type?
	int setParseStrategy(AbstractParsingStrategy* a);
};




