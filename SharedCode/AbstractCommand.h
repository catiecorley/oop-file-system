// declare AbstractCommand here. As all methods are virtual and will not be defined, no .cpp file is necessary


#pragma once
#include <string>

using namespace std; 

class AbstractCommand {
public:
	virtual int execute(string s) = 0;
	virtual void displayInfo() = 0;
	~AbstractCommand() = default;
};