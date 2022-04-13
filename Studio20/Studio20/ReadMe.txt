Studio 20 ReadMe.txt

2. we must delete the pointer to the actual AbstractFile because if we do not delete this pointer, there will be a 
dangling pointer because the pointer points to another pointer which points to the AbstractFile and therefore our
member variable will point to nothing if not deleted by destructor.

3. we iterated through the vector<char> that is returned when read() is called to check that the initial textfile was empty.
we then wrote to the file and then iterated through the newly returned vector from calling read again and saw that 
what we wrote was added to the text file. All three of these commands correctly prompted us for the password. 
Inputing the wrong password successfully stopped the file from being accessed/changed.

