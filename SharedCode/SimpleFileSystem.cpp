/* SimpleFileSystem.cpp
* Author: Catie Corley, Sam Lu
* Purpose: definitions for SimpleFileSystem  class 
*/
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

// checks if a file already exists in the system, if not adds it with its name to map of strings and files  
int SimpleFileSystem::addFile(string filename, AbstractFile* a) {
	map<string, AbstractFile*>::iterator it = files.find(filename); 
	if (it != files.end()) {
		return (int)outputs::ALREADY_EXISTS;
	}
	if (a == nullptr) {
		return (int)outputs::NULL_POINTER;
	}
	files.insert(pair<string, AbstractFile*>(filename, a)); 
	return (int)outputs::SUCCESS;
}

//int SimpleFileSystem::createFile(string filename) {
//	map<string, AbstractFile*>::iterator it = files.find(filename);
//	if (it != files.end()) {
//		return 5; // change this later (file is already in system) 
//	}
//	int index = filename.find('.'); 
//	string ext = filename.substr(index+1); 
//	if (ext == "txt") {
//		TextFile* t = new TextFile(filename);
//		files.insert(pair<string, AbstractFile*>(filename, t)); 
//		return 0; 
//	}
//	if (ext == "img") {
//		ImageFile* i = new ImageFile(filename);
//		files.insert(pair<string, AbstractFile*>(filename, i));
//		return 0;
//	}
//}

// finds designated file and checks if it is open, if not, file is deleted from the system 
int SimpleFileSystem::deleteFile(string filename) {
	map<string, AbstractFile*>::iterator it = files.find(filename);
	if (it != files.end()) {
		AbstractFile* f = files[filename];
		set<AbstractFile*>::iterator it2 = openFiles.find(f);
		if (it2 != openFiles.end()) {
			return (int)outputs::FILE_OPEN;
		}
		else {
			files.erase(filename);
			delete f; 
			return (int)outputs::SUCCESS; 
		}
	}
	return (int)outputs::ALREADY_EXISTS;
}

// checks if file is already open, if not, adds it to set of open files 
AbstractFile* SimpleFileSystem::openFile(string filename) {
	map<string, AbstractFile*>::iterator it = files.find(filename);

	if (it != files.end()) {
		AbstractFile* f = files[filename];
		set<AbstractFile*>::iterator it2 = openFiles.find(f);
		if (it2 == openFiles.end()) {
			openFiles.insert(f); 
			return f; 
		}
	}
	return nullptr; 
}

// checks if file is open, if so, removes it from set of open files 
int SimpleFileSystem::closeFile(AbstractFile* a) {
	set<AbstractFile*>::iterator it2 = openFiles.find(a);
	if (it2 != openFiles.end()) {
		openFiles.erase(it2); 
		return (int)outputs::SUCCESS; 
	}
	return (int)outputs::FILE_CLOSED;
}

// returns a set of all file names in the system.
set<string> SimpleFileSystem::getFileNames() {
	set<string> names;
	map<string, AbstractFile*>::iterator it = files.begin();
	while (it != files.end()) {
		names.insert(it->first);
		it++;
	}
	return names;
	
}