/* MetadataDisplayVisitor.cpp
* Author: Catie Corley, Sam Lu
* Purpose: definitions for MetaDataDisplayVisitor class 
*/
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <iomanip>

using namespace std; 

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	cout << file->getName() << setw(23 - (file->getName()).length()) << "text" << "\t" << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	cout << file->getName() << setw(23 - (file->getName()).length() + 1) << "image" << "\t" << file->getSize() << endl;
}


