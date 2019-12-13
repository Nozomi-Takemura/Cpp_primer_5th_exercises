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
	vector<int> Vec2(arr+0, arr+(end(arr)-begin(arr))/2);
	for (auto i : Vec) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : Vec2) {
		cout << i << " ";	
	}
	cout << endl;
}
