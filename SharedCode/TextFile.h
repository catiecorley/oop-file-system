#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile : public AbstractFile {
protected: 
	vector<char> fileContents; 
	string name; 
public: 
	TextFile(string s); 
	virtual vector<char> read();
	virtual int write(vector<char> v);
	virtual int append(vector<char> v);
	virtual unsigned int getSize();
	virtual string getName();
	void accept(AbstractFileVisitor*); 

	AbstractFile* clone(string name);
};

