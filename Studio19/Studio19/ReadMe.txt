studio 19 answers here
Sam Lu
 Catie Corley 

 2) We created an empty text file and then iterated through teh return vector to read and print it, then we wrote to the file and read it again 
 and printed the contents of the vector, and we were able to see the changes made 

 3) we pass in a pointer to the object which the operation is being defined for to the visitor, which then gives the visitor access 
 to this object. The visitor uses double dispatch, which calls different concrete function depending on runtime types of two objects 
 involved 

 4) They way that visitors use delegation is their use of double dispatch. Delegation includes a receiver and a sender, which is useful
 because you can call a member function oft he receiver using the state of the sender. To do this, we pass a pointer to the sender 
 to the receiver function, therefore for the receiver has access to the state of the sender. This is a more efficient and less cluttered
 way to add functionality. 

 5) If we wanted to add new concrete file types, all of the visitor classes would need to be modified. It's easy to add functionality to 
 existing types and delegating those, but adding new concrete file types might not be efficient. 
