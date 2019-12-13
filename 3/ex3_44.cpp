#include <iostream>
#include <string>
#include <vector>
#include <iterator>
//#include <cstring>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::iterator; using std::begin; using std::end;
//using std::strcmp;
using wage = double;
typedef double wage;

//using arr4int = int[4];
//typeof arr4int int[4];
typedef int arr4int[4];

int main() {
	int ia[3][4] = {    //
	    {0, 1, 2, 3},   //
	    {4, 5, 6, 7},   //
	    {8, 9, 10, 11}  //
	};

// 1. use for - range
/*
	cout << "{" << endl;
	for (arr4int &arr : ia) 
	{	
		cout << "{";
		for (int p : arr)
		{
			cout << p << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;
*/
// 2. use for - loop - subscript
/*
	cout << "{" << endl;
	for (int (*row)[4] = begin(ia); row != end(ia); ++row) {
		cout << "{";
		for (int *col = begin(*row); col != end(*row); ++col) {
			cout << *col << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;
// 2.5
*/
/*
	cout << "{" << endl;
	for (arr4int *ptrarr = begin(ia); ptrarr != end(ia); ++ptrarr) {
		cout << "{";
		for (int *ptr = begin(*ptrarr); ptr != end(*ptrarr); ptr++) {
			cout << *ptr << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;

	

		
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
	for (arr4int *ptrarr = ia; ptrarr != ia + 3; ++ptrarr) {
		cout << "{";
		for (int *arr = *ptrarr; arr != *ptrarr + 4; ++arr) {
			cout << *arr << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;

	
}
