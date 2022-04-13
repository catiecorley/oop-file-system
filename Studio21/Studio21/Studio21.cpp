// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"

int main()
{
	SimpleFileSystem* sfs = new SimpleFileSystem(); 
	SimpleFileFactory* sff = new SimpleFileFactory(); 
	TouchCommand* touchc = new TouchCommand(sfs, sff); 
	CommandPrompt* commprompt = new CommandPrompt(); 
	commprompt->setFileSystem(sfs); 
	commprompt->setFileFactory(sff); 
	commprompt->addCommand("touch", touchc); 
	commprompt->run(); 

	sfs->openFile("test.txt");
}

