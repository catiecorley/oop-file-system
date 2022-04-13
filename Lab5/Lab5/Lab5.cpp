// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Authors: Sam Lu and Catie Corley 
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
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/CopyCommand.h"
#include "CatAndDsParsingStrategy.h"


int main()
{
	// initializing file system, file factory, and all commands 
	SimpleFileSystem* sfs = new SimpleFileSystem();
	SimpleFileFactory* sff = new SimpleFileFactory();
	TouchCommand* touchc = new TouchCommand(sfs, sff);
	LSCommand* lsc = new LSCommand(sfs); 
	RemoveCommand* rmc = new RemoveCommand(sfs);
	CopyCommand* copyc = new CopyCommand(sfs); 
	CatCommand* cc = new CatCommand(sfs);
	CommandPrompt* commprompt = new CommandPrompt();
	DisplayCommand* dc = new DisplayCommand(sfs); 

	// creating rename macro command
	MacroCommand* mc = new MacroCommand(sfs);
	RenameParsingStrategy* rps = new RenameParsingStrategy();
	
	mc->setParseStrategy(rps);
	mc->addCommand(copyc);
	mc->addCommand(rmc);

	//creating cat and ds macro command
	MacroCommand* catds = new MacroCommand(sfs);
	CatAndDsParsingStrategy* cadps = new CatAndDsParsingStrategy();

	catds->setParseStrategy(cadps);
	catds->addCommand(cc);
	catds->addCommand(dc); 

	commprompt->setFileSystem(sfs);
	commprompt->setFileFactory(sff);

	//adding all commands to command prompt and running 
	commprompt->addCommand("touch", touchc);
	commprompt->addCommand("ls", lsc);
	commprompt->addCommand("rm", rmc);
	commprompt->addCommand("cp", copyc); 
	commprompt->addCommand("cat", cc);
	commprompt->addCommand("ds", dc); 
	commprompt->addCommand("rn", mc);
	commprompt->addCommand("catds", catds); 
	commprompt->run();

	return (int)outputs::SUCCESS; 
}


