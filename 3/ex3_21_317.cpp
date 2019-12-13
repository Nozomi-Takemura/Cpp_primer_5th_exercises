#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

int main() {
	vector<string> VeSt;
	string input;
	int prei = 0;
	int Cnt = 0;
	while(cin >> input) {
		VeSt.push_back(input);
	}
	for (auto i = VeSt.begin(); i != VeSt.end(); ++i) {
		for (auto &c : *i) {
			c = toupper(c);
		}
	}
	
	for (auto i = VeSt.begin(); i != VeSt.end(); ++i) {
		cout << *i << " ";
		++Cnt;
		if (prei != Cnt/8) {
			cout << endl;
			++ prei;
		}
	}
	cout << endl;
}
