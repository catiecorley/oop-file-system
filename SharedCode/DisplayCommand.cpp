
/* DisplayCommand.cpp
Author: Catie Corley and Sam Lu
Purpose: Defines the DisplayCommand class which opens a file and displays its contents
*/
#include "DisplayCommand.h"
#include <iostream>
#include "BasicDisplayVisitor.h"

using namespace std; 

// constructor 
DisplayCommand::DisplayCommand(AbstractFileSystem* a) {
	afs = a; 
}

// displays how to use display command 
void DisplayCommand::displayInfo() {
	cout << "Type ds <filename> to display the contents of a file. Type ds <filename> -d to display the contents without formatting" << endl; 
}

// takes in string and uses BasicDisplayVisitor to print out contents of file 
// -d will print files without formatting 
// returns 0 if successful, other values based on point of failure 
int DisplayCommand::execute(string s) {
	int space = s.find(' '); 
	if (space == -1) {
		AbstractFile* file = afs->openFile(s); 
		if (file == nullptr) {
			cout << "file does not exist" << endl; 
			return (int)outputs::DOESNT_EXIST;
		}
		BasicDisplayVisitor* bdv = new BasicDisplayVisitor();
		file->accept(bdv); 
		afs->closeFile(file);  
		return (int)outputs::SUCCESS; 
	}
	else {
		string filename = s.substr(0, space);
		AbstractFile* file = afs->openFile(filename);
		if (file == nullptr) {
			return (int)outputs::DOESNT_EXIST; 
		}
		if (s.substr(space + 1) != "-d") {
			afs->closeFile(file); 
			return (int)outputs::INVALID_COMMAND; 
		}
		else {
			vector<char> v = file->read(); 
			for (int i = 0; i < v.size(); i++) {
				cout << v[i]; 
			}
			cout << endl; 
			afs->closeFile(file);
			return (int)outputs::SUCCESS;
		}
	}
}