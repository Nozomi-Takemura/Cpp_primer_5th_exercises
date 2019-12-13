#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::iterator; using std::begin; using std::end;

int main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	for (auto ptr = begin(arr); ptr != end(arr); ++ptr) {
		*ptr = 0;
	}
	for (auto ptr = begin(arr); ptr != end(arr); ++ptr) {
		cout << *ptr << " ";
	}
	cout << endl;
}
