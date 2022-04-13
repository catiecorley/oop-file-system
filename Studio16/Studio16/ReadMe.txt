Answer studio 16 questions here

1) Sam Lu 
Catie Corley 

2) To declare an interface on C++, we would create an abstract base class that uses pure virtual functions 

3) a) this is an example of interface inheritance because objects share an interface but have their own implementation 
b) these member variables should be private, because only this object needs access to them 

4) Test cases: wrote it with "h i " which worked and printed "h i "
- overwrote the "h i" with " b y e" which also worked and printed "h i" and "b y e"

5) we declared out variable as a pointer to an abstract file instead of a text file 
AbstractFile * tf = new TextFile("hello");
	tf->read();
	tf->write({ 'h','i' });
	tf->read(); 
	tf->write({ 'b','y', 'e'});
	tf->read();
still behaves as expected 