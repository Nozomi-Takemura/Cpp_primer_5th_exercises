#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

int main() {
	vector<int> ints;	
	int input;
	while( cin >> input) {
		ints.push_back(input);
	}
	for (auto i : ints) {
		cout << i << " ";
	}
	cout << endl;
}



