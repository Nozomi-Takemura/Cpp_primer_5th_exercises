#include <iostream>
#include <string>
#include <vector>
#include <iterator>
//#include <cstring>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::iterator; using std::begin; using std::end;
//using std::strcmp;

int main() {
	int arr[] = {1,2,3,4,5};
	vector<int> Vec(begin(arr), end(arr));
	int arr2[Vec.size()] = {1,1,1,1,1};
	
// This does the job, but is not a good loop.
/*
	int *ptr = arr2;
	auto it = Vec.begin();

	cout << endl;

	for (;it != Vec.end(); ++ptr, ++it) {
		*ptr = *it;
	
	}

	for (auto p : arr) {
		cout << p << " ";
	}
	cout << endl;
*/

// Alternative:
	auto ptr_b = arr2; //ptr_int
	auto ptr_e = arr2 + Vec.size(); //ptr_int
	auto it = Vec.begin(); // iterator
	for (auto ptr = ptr_b; ptr < ptr_e; ++ptr, ++it) {
		*ptr = *it;
	}
	
	for (auto p : arr2) {
		cout << p << " ";
	}
	cout << endl;

}
