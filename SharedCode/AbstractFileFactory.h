#pragma once
// studio 18 - file factory interface declared here
#include "AbstractFile.h"
using namespace std; 

class AbstractFileFactory {
private:
public:
	virtual AbstractFile* createFile(string name) = 0;
};