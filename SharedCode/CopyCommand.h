// declare CopyCommand class here which will will copy a file that exists in the file systemand add the 
//copy to the file system with a different name.

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	CopyCommand(AbstractFileSystem* afs);
	int execute(string s);
	void displayInfo();
};
