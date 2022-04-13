// declare PasswordProxy proxy which adds functionality to protect files with a password

#pragma once
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* fileptr;
	string password;

public:
	PasswordProxy(AbstractFile* f, string pass);
	~PasswordProxy();

	 vector<char> read() ;
	 int write(vector<char> v) ;
	 int append(vector<char> v) ;
	 unsigned int getSize() ;
	 string getName();
	 void accept(AbstractFileVisitor*) ;

	 AbstractFile* clone(string name);

protected:
	string passwordPrompt();
};