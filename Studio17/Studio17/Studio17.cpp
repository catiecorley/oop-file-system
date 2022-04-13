// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "../../SharedCode/ImageFile.h" 
#include "../../SharedCode/AbstractFile.h" 

#include<vector>
using namespace std;



int main()
{
	vector<char> v = { 'X', ' ', 'X', ' ','X', ' ', 'X', ' ', 'X', '3'};
	ImageFile i = ImageFile("test");
	i.write(v);
	i.read();

	return 0;
}

