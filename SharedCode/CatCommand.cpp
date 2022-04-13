/* CatCommand.cpp
Author: Catie Corley and Sam Lu
Purpose: Defines the CatCommand class which allows user to write/append to an existing file
*/

#include "CatCommand.h"
#include <iostream>
#include <map>
#include <sstream>

// constructor
CatCommand::CatCommand(AbstractFileSystem* a) {
	afs = a;
}

// displays how to use CatCommand
void CatCommand::displayInfo() {
	cout << "Type cat <filename> or cat <filename> -a to append" << endl;
}

// takes string input, opens designated file and either writes over or appends to the file
// returns 0 if successful, other return values if cat is unsuccessful somewhere 
int CatCommand::execute(string s) {
	int space = s.find(' '); 
	if (space == -1) {
		AbstractFile* file = afs->openFile(s);
		if (file == nullptr) {
			return (int)outputs::DOESNT_EXIST;
		}
		vector<char> fileContents = file->read();

		vector<char> temporary;
		cout << "Input data to write to the file, type :wq to save and quit, or :q to quit without saving: " << endl;
		bool firstInput = true;
		while (true) {
			string input;

			getline(cin, input);
			
			if (input == ":wq") {
				file->write(temporary); //write over instead of append
				afs->closeFile(file);
				return (int)outputs::SUCCESS;
			}
			else if (input == ":q") {
				afs->closeFile(file); 
				return (int)outputs::SUCCESS;
			}
			else {
				if (firstInput) {
					firstInput = false;
				}
				else {
					temporary.push_back('\n');
				}
				for (int i = 0; i < input.length(); i++) {
					temporary.push_back(input[i]);
				}
			}
		}
	}
	else {
		string filename = s.substr(0, space); 
		AbstractFile* file = afs->openFile(filename);
		if (file == nullptr) {
			return (int)outputs::DOESNT_EXIST; 
		}
		vector<char> fileContents = file->read();
		string substring = s.substr(space + 1);
		int space2 = substring.find(' ');

		vector<char> temporary;

		for (int i = 0; i < fileContents.size(); i++) {
			cout << fileContents[i];
		}
		cout << endl;

		if (substring == "-a") {
			cout << "Input data to append to file, type :wq to save and quit, or :q to quit without saving: " << endl;
			bool firstInput = true;
			while (true) {
				
				string input;

				
				getline(cin, input); 

				if (input == ":wq") {
					if (file->append(temporary) != (int)outputs::SUCCESS) {
						return (int)outputs::OPERATION_NOT_SUPPORTED;
					}
					afs->closeFile(file); 
					return (int)outputs::SUCCESS;
				}
				else if (input == ":q") {
					afs->closeFile(file); 
					return (int)outputs::SUCCESS;
				}
				else {
					if (firstInput) {
						firstInput = false;
					}
					else {
						temporary.push_back('\n');
					}
					for (int i = 0; i < input.length(); i++) {
						temporary.push_back(input[i]);
					}
				}
			}
		}
	}
}
