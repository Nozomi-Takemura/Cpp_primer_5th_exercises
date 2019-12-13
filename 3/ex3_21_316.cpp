#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;
// page 159
// 3_16

int main() {
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};	

	cout << "V1: ";
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "V2: ";
	for (auto i = v2.begin(); i != v2.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "V3: ";
	for (auto i = v3.begin(); i != v3.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "V4: ";
	for (auto i = v4.begin(); i != v4.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "V5: ";
	for (auto i = v5.begin(); i != v5.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;



}
