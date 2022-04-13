studio 18 answers here
Catie Corley
Sam Lu

2. To create a new file system other than SimpleFileSystem, we would have to declare/define all of the same functions that we implemented
in SimpleFileSystem. This would be a lot of extra work just to add another type of file system. 
To create a new concrete file type, we would have to modify the concrete file system so that it is aware of the new concrete file types. 
Becuase the concrete file system depends on the types of concrete files, we would have to modify code in the file system class along
with adding the functionality to the new concrete type. 

3. advantage of an abstract facotry pattern is that is simplifies the amount of code needed to create different file types. We don't
need to rewrite code/funcitons to create files/interact with them due to the different file types. The factory will take care of the
differentiation. 
You would only want to create a new concrete factory class if the objects/classes/filetypes you were implementing shared none of the 
same interfaces as the other files types in the exisitng factory. 
Only the code in the simple file facotry if new file type was introduced. all other code would not have to be modified and would not be impacted by the additional file type.
If two file implementations manage the same types of files, you can use the same factory for both becaseu this will consolidate the 
creationo of the different file types to one place instead of having to deal with the file types seperately.
If the two file system implementations manage different types of files, the factory can still be used but will have to have added
ability to differentiate between file types when creating/modifying files. 

4. we created both a tezt and image file. we read these files and we wrote new text to the text file and read that after to check for
the correct output. we also checked to makes ure we could close our file by calling closeFile() on our textfile. These all ran 
successfully.

5. Because we removed all createFile implementations in abstractFileSystem and SimpleFileSystem, it now nolonger depends on any concrete files
types and depends on teh AbstractFile interface only.