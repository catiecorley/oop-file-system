// declare the ConcreteCommand class TouchCommand here which will allow user to create files
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {
	AbstractFileSystem* afs;
	AbstractFileFactory* aff; 
public:
	TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff); 
	int execute(string s);
	void displayInfo();
};
