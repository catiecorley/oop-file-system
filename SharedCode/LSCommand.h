// declare LSCommand class here which will output to the terminal the names of all files currently in the file system

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public: 
	LSCommand(AbstractFileSystem* afs);
	int execute(string s);
	void displayInfo();
};