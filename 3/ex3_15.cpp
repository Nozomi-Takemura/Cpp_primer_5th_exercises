#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

int main() {
	vector<string> vec_str;
	string input;
	while( cin >> input) {
		vec_str.push_back(input);
	}
	for (auto s : vec_str) {
		cout << s << " ";
	}
	cout << endl;
}
