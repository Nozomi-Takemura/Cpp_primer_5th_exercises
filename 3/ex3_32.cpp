#include <iostream>
#include <vector>
using std::vector;

int main() {
/*
	int arr[10];
	int index = 0;
	for (auto &i : arr) {
		 i = index;
		 ++ index;
	}
	index = 0;	
	int arrco[10];
	for (auto i : arr) {
		arrco[index] = i;
		++ index;
	}

	for (auto i : arrco) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
*/

// part2
	vector<int> arr;
	for (decltype(arr.size()) index = 0; index != 10; ++index) {
		arr.push_back(index);
		std::cout << index;
	}
	std::cout << std::endl;
	vector<int> arrco = arr;
	for (auto i : arrco) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
}

/*
KEY: In the intialization, array cannot be initilized by another array (probably because it is automatically derefernced into a poiner to the first element of the array.)
   : On the other hand, vector can be initilized by another vector.
*/
