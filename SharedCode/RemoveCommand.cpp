/* RemoveCommand.cpp
Author: Catie Corley and Sam Lu
Purpose: defines the RemoveCommand class
*/
#include "RemoveCommand.h"
#include <iostream>
#include <map>
#include "MetadataDisplayVisitor.h"

// constructor 
RemoveCommand::RemoveCommand(AbstractFileSystem* a) {
	afs = a;
}

// calls deleteFile on the designated file, returns 0 if successful, other return value indicating failure if not 
int RemoveCommand::execute(string s) {
	if (afs->deleteFile(s) == 0) {
		return (int)outputs::SUCCESS;
	}
	return (int)outputs::NOT_DELETED;
	
}

// displays how to use the remove command
void RemoveCommand::displayInfo() {
	cout << "Type rm <filename> to remove the file from the file system." << endl;
}
