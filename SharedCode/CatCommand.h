// declare CatCommand class here. This class acts as a utility that is useful for concatenating files

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CatCommand : public AbstractCommand {
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
public:
	CatCommand(AbstractFileSystem* afs);
	int execute(string s);
	void displayInfo();
};


