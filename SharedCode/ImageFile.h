#pragma once
// Image file class declaration here
#include "AbstractFile.h"
 
class ImageFile : public AbstractFile {
private: 
	string filename; 
	vector<char> filecontents; 
	char size; 
public: 
	ImageFile(string name); 
	unsigned int getSize(); 
	string getName(); 
	int write(vector<char> v); 
	int append(vector<char> v); 
	vector<char> read(); 
	void accept(AbstractFileVisitor*);

	AbstractFile* clone(string name);
};
