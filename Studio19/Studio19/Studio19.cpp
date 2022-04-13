// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include <iostream>


using namespace std; 

int main()
{
	TextFile f = TextFile("test.txt");
	vector<char> v = f.read(); 
	f.write({ 't', 'e', 's', 't' }); 
	v = f.read(); 
	BasicDisplayVisitor b; 
	f.accept(&b); 

	return 0;
}
