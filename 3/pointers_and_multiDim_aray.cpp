#include <iostream>
using std::cout; using std::endl;
int main()
{
	int ia[3][4] = {    //
	    {0, 1, 2, 3},   //
	    {4, 5, 6, 7},   //
	    {8, 9, 10, 11}  //
	}; // array of array of int -->decayed--> pointer(to array[?]) to pointer(to int) --> array of pointers() 
/*
	for (auto p = ia; p != ia + 3; ++p) {
		cout << "*p = " << *p << ", p = " << p << endl;
		for (auto q = *p; q != *p + 4; ++q) {
			cout << "*q = " << *q << ", q = " << q << endl;
		}
	}
*/
	for (int (*p)[4] = ia; p != ia + 3; ++p) { // pointer to array of int
		for (int *q = *p; q != *p + 4; ++ q) { // dereferenced --> an array of int -->decayed--> an pointer of 1st element.
			cout << "*q = " << *q << endl;
		}
	}
		
}
