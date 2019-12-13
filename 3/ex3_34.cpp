#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::iterator; using std::begin; using std::end;


int main() {
/*
	int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
	int *beg = begin(ia); // pointer to the first element in ia
	int *last = end(ia);  // pointer one past the last element in ia
*/
	int arr[10] = {1,2,3,4,5,6,7,8,9,10} ;
	auto p1 = end(arr)  , p2 = end(arr);
	cout << *p1 << endl;
	p1 += p2 - p1;
	cout << *p1 << endl;

}

/*
-Prediction:
This program enables p1 to point to the element which is pointed by the p2.

When both p1 and p2 point to the past after the last element, the value is not correct.
*/
