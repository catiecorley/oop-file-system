/* ImageFile.cpp
Author: Catie Corley, Sam Lu
Purpose: definitions of concrete image file class 
*/
#include "ImageFile.h"
#include <iostream>

using namespace std;  

ImageFile::ImageFile(string name) : filename(name), size(0){}

// returns the horizontal dimensions of the image  
unsigned int ImageFile::getSize(){
	return (unsigned int)filecontents.size(); 
}

// returns the name of the image file 
string ImageFile::getName() {
	return filename; 
}

// clears filecontents vector and then writes in new contents 
int ImageFile::write(vector<char> v) {
	filecontents.clear(); 
	size = (int)v[v.size() - 1]; 
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] != 'X' && v[i] != ' ') {
			size = '0';
			filecontents.clear(); 
			return (int)outputs::WRONG_CONTENTS;
		}
		if ((int)size - 48 != (int)sqrt(v.size() - 1)) {
			return (int)outputs::WRONG_SIZE;
		}
		filecontents.push_back(v[i]); 
	}
	return (int)outputs::SUCCESS;
}

// image files do not support the append operation 
int ImageFile::append(vector<char> v) {
	return (int)outputs::OPERATION_NOT_SUPPORTED; 
}

// returns a vector of the contents of the image file 
vector<char> ImageFile::read() {
	int length = size -48;
	vector<char> v;
	for (int x = 0; x < length; x++) {
		for (int y = 0; y < length; y++) {
			if ((x * length + y) < filecontents.size()) { //going out of bounds and not printing
				v.push_back(filecontents[x * length + y]);
			}
		}
	}
	return v; 
}

// accepts AbstractFileVisitor, calls visit function on this pointer 
void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}

// creates a new image file with the same contents 
AbstractFile* ImageFile::clone(string name) {
	AbstractFile* newImageFile = new ImageFile(name + ".img");
	vector<char> copy = filecontents; 
	copy.push_back(size); 
	newImageFile->write(copy);
	return newImageFile;
}