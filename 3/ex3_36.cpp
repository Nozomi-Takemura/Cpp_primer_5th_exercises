#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::iterator; using std::begin; using std::end;
/*
template <typename iterator>
void fun(iterator begin, iterator end)
{
	for (auto i = begin; i != end; ++i) {
		cout << *i << " ";
	}
	cout << endl;
}
*/  
int f(int *arr_e, int *arr_b, int *arr2_e, int *arr2_b) {
/* // std::begin cannot be applied to a passed array because it is not longer of int array type but int* type. 
	auto arr_e = end(arr);
	auto arr_b = begin(arr);
	auto arr2_e = end(arr2);
	auto arr2_b = begin(arr2);
*/
	if (arr_e - arr_b != arr2_e - arr2_b) {
		cout << "Two arays are different" << endl;
		return -1;
	}
	else {
		for (; arr_b != arr_e && arr2_b != arr2_e; ++arr_b, ++arr2_b) {
			cout << "arr: " << *arr_b << ", arr2: " << *arr2_b << endl;
			if ( *arr_b != *arr2_b ) {
				cout << "Two arrays are different: at least 1 element is not matched" << endl;
				return -1;
			}
		}
		cout << "Two arrays are the same." << endl;
		return 0; 	
	}

}

int main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {1,2,3,4,5,6,7,8,9,11};
	int arr4[] = {1,2,3,4,5,6};
	f(end(arr), begin(arr), end(arr2), begin(arr2));
	f(end(arr), begin(arr), end(arr3), begin(arr3));
	f(end(arr), begin(arr), end(arr4), begin(arr4));

}
