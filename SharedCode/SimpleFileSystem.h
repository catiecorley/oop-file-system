#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>
#include <set>

using namespace std; 

class SimpleFileSystem : public AbstractFileSystem {
private: 
	map<string, AbstractFile*> files; 
	set<AbstractFile*> openFiles; 
public: 
	int addFile(string filename, AbstractFile* a);
	//int createFile(string filename);
	int deleteFile(string filename);
	AbstractFile* openFile(string filename);
	int closeFile(AbstractFile* a);
	set<string> getFileNames();
};
