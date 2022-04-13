/* TouchCommand.cpp
Author: Catie Corley and Sam Lu
Purpose: defines the TouchCommand Class
*/
#include "TouchCommand.h"
#include <iostream>
#include "PasswordProxy.h"
using namespace std; 

// constructor 
TouchCommand::TouchCommand(AbstractFileSystem* a, AbstractFileFactory* b) {
	afs = a; 
	aff = b; 
}

// displays how to use touch command 
void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <filename>. add -p to add passoword to file. " << endl; 
}

// checks if file is password protected, creates new file acordiningly 
// prompts for password if creating a passwork protected file 
// returns 0 if successful, various return vales indicating failure otherwise 
int TouchCommand::execute(string s) {
	int space = s.find(' ');
	AbstractFile* file;
	if (space != -1) {
		 file = aff->createFile(s.substr(0, space));
	}
	else {
		file = aff->createFile(s);
	}

	string afterspace = s.substr(space + 1);
	int space2 = afterspace.find(' ');

	cout << afterspace << endl; 

	if (file != nullptr) {
		if (space != -1 && afterspace == "-p") {
			string password;
			cout << "What is the password?" << endl;
			getline(cin, password);
			PasswordProxy* p = new PasswordProxy(file, password);
			int ret = afs->addFile(s.substr(0, space), p);
			cout << "adding password file return value" << ret << endl;
			if (ret != (int)outputs::SUCCESS) {
				delete file;
				cout << "file created but not added" << endl;
				return (int)outputs::NOT_ADDED;
			}
			return (int)outputs::SUCCESS;
		}
		else if(space == -1) {
			if (afs->addFile(s, file) != 0) {
				delete file;
				cout << "file created but not added" << endl;
				return (int)outputs::NOT_ADDED;
			}
			else {
				return (int)outputs::SUCCESS;

			}
		}
		else {
			return (int)outputs::SUCCESS; 
		}
	}
	else {
		cout << "file not created" << endl; 
		return (int)outputs::UNSUCCESSFUL_CREATION;
	}
}