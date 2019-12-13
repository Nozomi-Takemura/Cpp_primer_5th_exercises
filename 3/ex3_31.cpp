#include <iostream>

int main() {
	int arr[10];
	int index = 0;
	for (auto &i : arr) {
		 i = index;
		 ++ index;
	}
	for (auto i : arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
