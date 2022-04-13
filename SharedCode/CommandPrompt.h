// declare CommandPrompt class here. This class handles user input/output in the command line.

#pragma once
#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
using namespace std;


class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(string s, AbstractCommand* a);
	int run();
protected:
	void listCommands();
	string prompt();
private:
	map<string, AbstractCommand*> m;
	AbstractFileSystem* absFileSystem;
	AbstractFileFactory* absFileFactory;
};