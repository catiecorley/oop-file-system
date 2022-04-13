/* PasswordProxy.cpp
Author: Catie Corley and Sam Lu
Purpose: defines the proxy to add password to a file
*/

#include "PasswordProxy.h"
#include <iostream>

// constructor
PasswordProxy::PasswordProxy(AbstractFile* f, string pass) {
	fileptr = f;
	password = pass;
}

// destructor 
PasswordProxy::	~PasswordProxy() {
	delete fileptr;
}

// prompts user for password 
string PasswordProxy ::passwordPrompt() {
	cout << "input passowrd" << endl;
	string pass;
	cin >> pass;
	return pass;
}

// prompts user for password, reads file if password is correct 
vector<char> PasswordProxy::read() {
	string pass = passwordPrompt();
	if (pass == password) {
		return fileptr->read();
	}
	else {
		vector<char> empty;
		return empty;
	}
}

// prompts user for pass, writes file if password is correct 
int PasswordProxy::write(vector<char> v) {
	string pass = passwordPrompt();
	if (pass == password) {
		return fileptr->write(v);
	}
	else {
		return (int)outputs::INCORRECT_PASSWORD; 
	}
}

// prompts user for password, appends to file if password is correct 
int PasswordProxy::append(vector<char> v) {
	string pass = passwordPrompt();
	if (pass == password) {
		return fileptr->append(v);
	}
	else {
		return (int)outputs::INCORRECT_PASSWORD;
	}
}

// returns size of password protected file 
unsigned int PasswordProxy::getSize() {
	return fileptr->getSize();
}

// returns name of password protected file 
string PasswordProxy::getName() {
	return fileptr->getName();
}

// prompts user for password, accepts AbstractFileVisitor if correct 
void PasswordProxy::accept(AbstractFileVisitor* v) {
	string pass = passwordPrompt();
	if (pass == password) {
		fileptr->accept(v);
	}
	
}

// prompts user for password, clones file if correct 
AbstractFile* PasswordProxy::clone(string name) {
	AbstractFile* newFile = fileptr->clone(name);
	AbstractFile* newPasswordProxy = new PasswordProxy(newFile, password);
	

	return newPasswordProxy;
}


