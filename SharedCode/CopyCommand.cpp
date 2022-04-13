/* CopyCommand.cpp
Author: Catie Corley and Sam Lu
Purpose: Defines the CopyCommand class which copies a file that exists in the file system and adds 
the copy to the file system with a different name
*/

#include "CopyCommand.h"
#include <iostream>
#include "BasicDisplayVisitor.h"

using namespace std;

// constructor 
CopyCommand::CopyCommand(AbstractFileSystem* a) {
	afs = a;
}

// displays how to use copy command
void CopyCommand::displayInfo() {
	cout << "Type cp <file_to_copy> <new_name_with_no_extension> to copy the contents of the original file into a file with a new name." << endl;
}

// takes in a string, will create a new file with contents from first file name and name it with second file name, using clone method 
// returns 0 if successful, other return values based on where it fails 
int CopyCommand:: execute(string s) {
	int space = s.find(' ');
	string originalName = s.substr(0, space);
	string newName = s.substr(space + 1);

	AbstractFile* originalFile = afs->openFile(originalName);
	if (originalFile == nullptr) {
		return (int)outputs::NULL_POINTER;
	}

	AbstractFile* newFile = originalFile->clone(newName); //clone in AbstractFile, ImageFile, TextFile
	afs->closeFile(originalFile);


	if (afs->addFile(newFile->getName(), newFile) != (int)outputs::SUCCESS) {
		return (int)outputs::NOT_ADDED;
	}
	return (int)outputs::SUCCESS;
}
