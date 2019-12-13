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
	cout << "use for range - auto type"  << endl;
	cout << "{" << endl;
	for (auto &arr : ia) 
	{	
		cout << "{";
		for (auto p : arr)
		{
			cout << p << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;

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
	cout << "{" << endl;
	for (arr4int *ptrarr = begin(ia); ptrarr != end(ia); ++ptrarr) {
		cout << "{";
		for (int *ptr = begin(*ptrarr); ptr != end(*ptrarr); ptr++) {
			cout << *ptr << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;

*/
	cout << "use for loop - subscripts - auto type" << endl;			
	for (auto row = 0; row != end(ia) - begin(ia); ++row) {
		cout << "{";
		for (auto col = 0; col != end(ia[row]) - begin(ia[row]); ++col) {
			cout << ia[row][col] << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;

// 3. use for -- loop - pointer
	cout << "use for loop - pointer + auto type" << endl;
	cout << "{" << endl;
	for (auto ptrarr = begin(ia); ptrarr != end(ia); ++ptrarr) {
		cout << "{";
		for (auto arr = begin(*ptrarr); arr != end(*ptrarr); ++arr) {
			cout << *arr << ", ";
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;

	
}
