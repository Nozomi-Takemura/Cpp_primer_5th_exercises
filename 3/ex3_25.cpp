#include <iostream>
#include <string>
#include <vector>
using std::string; using std::cin; using std::endl;using std::cout;
using std::vector;


int main() {
	vector<int> grade(11);
	int input;
	while(cin >> input) {
		++ *(grade.begin() + input/10); 
	}
	for (auto it = grade.begin(); it != grade.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}
