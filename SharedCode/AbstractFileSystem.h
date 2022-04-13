#pragma once
// declaration of the AbstractFileSystem interface all file systems provide here
#include <string>
#include "AbstractFile.h"
#include <set>
class AbstractFileSystem {
public: 
	virtual int addFile(string filename, AbstractFile* a) = 0; 
	//virtual int createFile(string filename) = 0; 
	virtual int deleteFile(string filename) = 0; 
	virtual AbstractFile* openFile(string filename) = 0;
	virtual int closeFile(AbstractFile* a) = 0;
	virtual set<string> getFileNames() = 0;
};
