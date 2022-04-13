/* LSCommand.cpp
Author: Catie Corley and Sam Lu
Purpose: Defines the LSCommand class which outputs the names of all files currently in the file system.
*/
#include "LSCommand.h"
#include <iostream>
#include <map>
#include "MetadataDisplayVisitor.h"

// constructor
LSCommand::LSCommand(AbstractFileSystem* a) {
	afs = a;
}

// displays how to use the ls command 
void LSCommand::displayInfo() {
	cout << "Type ls to list all the names of the files currently in the file system. Type ls -m to list metadata of files. " << endl;
}

// checks for -m, dispalys names of all files if not, displays names with metadata if so, 
// returns 0 if successful, other return value if not 
int LSCommand::execute(string s) {
	if (s == "") {
		set<string> names = afs->getFileNames();
		
		set<string>::iterator it = names.begin();
		
		int counter = 0;
		string spaces = "                    ";
		while (it != names.end()) {
			counter++;
			int namesize = (*it).length();

			string modifiedSpaces = spaces.substr(namesize + 1);
			cout << *it << modifiedSpaces;
			if (counter % 2 == 0) {
				cout << endl;
			}
			it++;
		}
		return (int)outputs::SUCCESS;
	}
	else if (s == "-m") {
		set<string> names = afs->getFileNames();
		set<string>::iterator it = names.begin();
		while (it != names.end()) {
			AbstractFile* file = afs->openFile(*it); 
			MetadataDisplayVisitor* mdv = new MetadataDisplayVisitor(); 
			file->accept(mdv); 
			afs->closeFile(file); 
			it++; 
		}
		return (int)outputs::SUCCESS; 
	}
	return (int)outputs::FAILED_LS;

}