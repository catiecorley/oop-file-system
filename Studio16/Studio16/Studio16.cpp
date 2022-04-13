// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>

using namespace std;


int main()
{
	AbstractFile * tf = new TextFile("hello");
	tf->read();
	tf->write({ 'h', 'i' });
	tf->read(); 
	tf->write({ 'b','y', 'e'});
	tf->read();
	return 0;
}


