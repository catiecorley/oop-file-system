/* BasicDisplayVisitor.cpp
Author: Catie Corley and Sam Lu
Purpose: Defines the BasicDisplayVisitor which visits a file and displays its contents.
*/
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <vector>
#include "TextFile.h"
#include "ImageFile.h"
#include <math.h>

using namespace std; 

// visit function for displaying a text file 
void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	vector<char> v = file->read(); 
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}

// visit function for displaying an image file with correct formatting
void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
	vector<char> v = file->read(); 
	int length = sqrt(file->getSize()); 
	for (int x = 0; x < length; x++) {
		for (int y = 0; y < length; y++) {
			if ((x * length + y) < file->getSize()) { //going out of bounds and not printing
				cout << v[x * length + y];
			}
		}
		cout << endl;
	}
}

