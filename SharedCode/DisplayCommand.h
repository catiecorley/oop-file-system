// declare DisplayCommand class here which will open a file and displays its contents (can be formatted or not)

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
	AbstractFileSystem* afs; 
public: 
	DisplayCommand(AbstractFileSystem* afs);
	int execute(string s);
	void displayInfo();
};
