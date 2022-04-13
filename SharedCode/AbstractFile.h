#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"

using namespace std; 

class AbstractFile {
public:  
	virtual vector<char> read() = 0; 
	virtual int write(vector<char> v) = 0; 
	virtual int append(vector<char> v) = 0; 
	virtual unsigned int getSize() = 0; 
	virtual string getName() = 0; 
	virtual ~AbstractFile() = default; 
	virtual void accept(AbstractFileVisitor*) = 0;

	virtual AbstractFile* clone(string name) = 0;
private: 
};

enum struct outputs { SUCCESS = 0, WRONG_CONTENTS = 1, WRONG_SIZE = 2, OPERATION_NOT_SUPPORTED = 3, INCORRECT_PASSWORD = 4, ALREADY_EXISTS = 5, NULL_POINTER = 6, DOESNT_EXIST = 7, FILE_OPEN = 8, UNSUCCESSFUL_INSERTION = 9, QUIT = 10, FILE_CLOSED = 11, NOT_ADDED = 12, UNSUCCESSFUL_CREATION = 13, FAILED_LS = 14, NOT_DELETED = 15, INVALID_COMMAND = 16, UNSUCCESSFUL_EXECUTION
 = 17};