/* CommandPrompt.cpp
Author: Catie Corley and Sam Lu
Purpose: defines the CommandPrompt class which handles the user input and output
*/

#include "CommandPrompt.h"
#include <iterator>
#include <iostream>
#include <sstream>
#include "TextFile.h"

// constructor
CommandPrompt::CommandPrompt() {
	absFileSystem = nullptr;
	absFileFactory = nullptr;
}

// setter for abstract file system 
void CommandPrompt::setFileSystem(AbstractFileSystem* a) {
	absFileSystem = a;
}

// setter for abstract file factory 
void CommandPrompt::setFileFactory(AbstractFileFactory* a) {
	absFileFactory = a;
}

// takes in a string, pointer to abstract command, and adds that abstract command which is mapped to the string 
// returns 0 if successful, other return value if not 
int CommandPrompt::addCommand(string s, AbstractCommand* a) {

	m.insert(pair<string, AbstractCommand*>(s, a));
	map<string, AbstractCommand*>::iterator it = m.find(s);
	if (it != m.end()) {
		return  (int)outputs::SUCCESS;
	}
	return (int)outputs::UNSUCCESSFUL_INSERTION; 

}

// prints out all commands currently in map 
void CommandPrompt::listCommands() {
	map<string, AbstractCommand*>::iterator it = m.begin();
	while (it != m.end()) {
		cout << (*it).first << endl;
		it++;
	}
}

// prompts user and takes in input 
string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	cout << "$   ";
	string input;
	getline(cin, input); 
	return input;
}

// in a while loop, continuously prompts the user, takes input and executes commands based on user prompt, until quit
int CommandPrompt::run() {
	while (1) {
		string s = prompt();
		if (s == "q") {
			return (int)outputs::QUIT;
		}
		else if (s == "help") {
			listCommands();
		}
		else {
			int space = s.find(' ');
			if (space == -1) {
				map<string, AbstractCommand*>::iterator it = m.begin();
				bool found = false;
				while (it != m.end()) {
					if (s == it->first) {
						found = true;
						if (it->second->execute("") != 0) {
							cout << "the command failed" << endl;
						}
					}
					it++;
				}
				if (!found) {
					cout << "command did not exist" << endl;
				}
			}
			else {
				istringstream iss(s);
				string str;
				iss >> str;
				string str2;
				iss >> str2;
				if (str == "help") {
					

					bool found = false;
					map<string, AbstractCommand*>::iterator it = m.begin();
					while (it != m.end()) {
						if (it->first == str2) {
							found = true;
							(*it).second->displayInfo();
						}
						it++;
					}
					if (!found) {
						cout << "command does not exist" << endl;
					}
				}
				else {
					istringstream iss(s);
					string entireInput;
					string input;
					string first;
					iss >> first;
					
					bool found = false;
					string secondpart = s.substr(space+1, s.size()-1); 
					map<string, AbstractCommand*>::iterator it = m.begin();
					while (it != m.end()) {
						if (it->first == first) {
							found = true;
					
								int ret = it->second->execute(secondpart);
								if (ret != (int)outputs::SUCCESS) {
									cout << "execution failed" << endl;
								}
							
						}
						it++;
					}
					if (!found) {
						cout << "command does not exist" << endl;
					}
				}
			}
		}
	}
}

 