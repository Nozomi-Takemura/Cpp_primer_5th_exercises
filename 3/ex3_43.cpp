#include <iostream>
#include <string>
#include <vector>
#include <iterator>
//#include <cstring>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::iterator; using std::begin; using std::end;
//using std::strcmp;

int main() {
	int ia[3][4] = {    //
	    {0, 1, 2, 3},   //
	    {4, 5, 6, 7},   //
	    {8, 9, 10, 11}  //
	};
// 1. use for - range
/*
	cout << "{" << endl;
//	for (int **(&ptr) : ia) // ia[0] = ptr to int arr[4] --decayed--> ptr to ptr to int;
	for (int (&ptr)[4] : ia) // ia[0] = int arr[4] --decayed--> ptr to int;
	{	
		cout << "{";
//		for (int *(&p) : *ptr) // *(ptr to int arr) --> int arr --decayed--> ptr to int;
		for (int p : ptr) // *(ptr to int)[0] -???-> int arr[0] --> int ;	
		{
			cout << p << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;

// 2. use for - loop - subscript
	cout << "{" << endl;
	for (size_t row = 0; row != 3; ++row) {
		cout << "{";
		for (size_t col = 0; col != 4; ++col) {
			cout << ia[row][col] << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;
*/
// 3. use for -- loop - pointer
	cout << "{" << endl;
	for (int (*ptrarr)[4] = ia; ptrarr != ia + 3; ++ptrarr) {
		cout << "{";
		for (int *arr = *ptrarr; arr != *ptrarr + 4; ++arr) {
			cout << *arr << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;
	
}
