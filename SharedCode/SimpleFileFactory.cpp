/* SimpleFileFactor.cpp 
* Author: Catie Corley, Sam Lu
* Purpose: definitions for SimpleFileFactory class 
*/
#include "SimpleFileFactory.h"
#include "AbstractFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

// checks filename extension and creates a new concrete file based on what it is 
AbstractFile* SimpleFileFactory::createFile(string filename) {
	int index = filename.find('.');
	string ext = filename.substr(index + 1);
	if (ext == "txt") {
		TextFile* t = new TextFile(filename);
		return t;
	}
	if (ext == "img") {
		ImageFile* i = new ImageFile(filename);
		return i;
	}
	else {
		return nullptr;
	}
}



