#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

int main() {
	vector<string> VecStr;
	string input;
	while (cin >> input) {
		VecStr.push_back(input);
	}
	for (auto &str : VecStr) {
		for (auto &c : str) {
			c = toupper(c);
		}
	}
	decltype (VecStr.size()) PreInd = 0;
	for (decltype (VecStr.size()) index = 0; index != VecStr.size(); ++index) {
		if ( index/8 > PreInd) {
			cout << endl;
		}
		PreInd = index/8;
		cout << VecStr[index] << " ";
	}
	cout << endl;
}
