// declare RemoveCommand class here which will remove the file with the provided name from the file system
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	RemoveCommand(AbstractFileSystem* afs);
	int execute(string s);
	void displayInfo();
};