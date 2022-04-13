Lab 5 Readme
Authors: Catie Corley and Sam Lu

CSE 332S Lab 5: OOP Design

Splitting up work:
To divide up the work, we worked together during studio to complete all of the studio code. For Lab5, we worked 
seperately on coding the individual classes/commands and met up to share our work with each other and to also work 
together to debug errors we ran into. 

Testing Lab 5:

- Ran into errors and tests not passing with adding the newline character to the CatCommand function. Fixed by adding
a boolean variable to only add a space before the line if it was not the first line. 

- Many missing success returns that led to getting failure output of 69. Functions had no value to return due to 
missing else statements where success should be returned.

- password loop. We had an uncessasary loop checking if the insertion operator was returning true in the commandprompt class
that caused the password to be asked for multiple times. Simply deleting this while loop fixed these errors.

- Errors with appending to image file. We were missing proper return values after the if/else statements.

- CatCommand was not building. Forgot to implement clone in PasswordProxy.

- MetaDataDisplayVisitor formatting was a little bit off, added more spaces for longer file names

- wasn't building after adding MacroCommand, changed vector to be a vector of pointers to AbstractCommands, instead of a 
vector of AbstractCommands 

- ds -d for image files was not working, tweaked vector indices to match to fix 

- CatAndDs Macro command was running into an out of bounds error if the inputs were invalid, changed to return just a vector of 2 
invalid strings if the input was invalid 

Macro Command: 
We chose to implement a combined cat and ds macro command 
To invoke this command, use: 
catds <filename> 
catds <filename> -a 
catds <filename> -d
catds <filename> -a -d : only supports input with both -a and -d in this order, won't work the other way 
To ensure it ran properly, we called it with each add on and both add ons on both text and image files, and they acted accordingly. 
We also tested with invalid input, and the execution failed as expected. 

Overall Testing in the command line: 
- tested touch command for text and image files, as well as invalid input, and password protected files, all acted as expected 
- tested ls command and ls -m command, acted as expected 
	- ls followed by invalid input results in failed execution as expected 
- tested remove command on text and image files, and invalid input, all behaved as expected 
- tested cat command on text and image files, and invalid input 
	- tested with -a add on
	- tested :wq and q 
	- all behaved as expected 
- tested ds command on test and image files 
	- also tested -d add on, all behaved as expected 
- tested copy on text and image files, as well as invalid input, all behaved as expected 
- tested rename on text and image files, as well as invalid input, all behaved as expected


