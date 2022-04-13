// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"

#include <iostream>

int main()
{

	AbstractFile* a = new TextFile("test.txt");
	PasswordProxy p = PasswordProxy(a, "1234");
	vector<char> v = p.read();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	p.write({ 'h','i' });
	v = p.read();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}

