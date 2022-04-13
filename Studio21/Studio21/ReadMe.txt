Studio 21 ReadMe.txt 

2. It is important to declare a virtual destrcutor in the base class so that derived classes will have access to a
destructor which they can override if necessary. 

3. this makes the command prompt flexible an resusable because you can give the command prompt any file system/command
object that you have created wihtout having to change the implementation of the command prompt class. This allows
us to modify and add to our file system without having to worry about the impact on the command prompt and it makes 
these changes more efficient due to command prompt not needing to be updated.
Yes it could be reconfigured becasue these classes all override the same methods and therefore you could set it to point to
these other classes by creating a method to do so. 

4. We tested all of the possible commands (help, help <command>, q, the touch command). We also tested non valid inputs and tried
to call touch on files that already existed. By adding print statements, we were able to see that all of these ran successfully. 
