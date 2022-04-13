/* TextFile.cpp
Author: Catie Corley, Sam Lu
Purpose: definitions of concrete text file class
*/
#include "TextFile.h"
#include <iostream>

//constructor 
TextFile::TextFile(string s) : name(s) {}; 

//returns size of text file 
unsigned int TextFile::getSize() {
	return (unsigned int)fileContents.size(); 
}

//returns name of text file 
string TextFile::getName() {
	return name; 
}

// writes new characters into file contents 
int TextFile::write(vector<char> v) { 
	fileContents = v; 
	return (int)outputs::SUCCESS;
}

// appends new contents to the end of file 
int TextFile::append(vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		fileContents.push_back(v[i]); 
	}
	return (int)outputs::SUCCESS;
}

// returns vector of file contents 
vector<char> TextFile::read() {
	vector<char> v; 
	for (int i = 0; i < fileContents.size(); i++) {
		v.push_back(fileContents[i]);
	}
	return v;
}

// calls AbstractFileVisitor on this pointer 
void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this); 
}

// creates a new text file wiht same contents
AbstractFile* TextFile::clone(string name) {
	AbstractFile* newImageFile = new TextFile(name + ".txt");
	newImageFile->write(fileContents);

	return newImageFile;
}