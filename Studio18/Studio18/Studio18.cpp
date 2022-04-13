// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"


using namespace std;

int main()
{
	AbstractFileSystem* s = new SimpleFileSystem();
	AbstractFileFactory* f = new SimpleFileFactory();
	AbstractFile* firstfile = f->createFile("test.txt");
	AbstractFile* secondfile = f->createFile("test2.img");

	s->addFile(firstfile->getName(), firstfile);
	s->addFile(secondfile->getName(), secondfile);

	firstfile->read();
	secondfile->read();

	firstfile->write({ 'h', 'i' });
	firstfile->read();

	firstfile->write({ 't','e','s','t' });
	firstfile->read();

	s->closeFile(firstfile);



	return 0;
}
