#include <iostream>
#include <string>
#include <vector>
using std::string; using std::cin; using std::endl;using std::cout;
using std::vector;
int main() {
	vector<int> Vec{1,2,3,4,5,6,7,8,9,10};
	for (auto in = Vec.begin(); in != Vec.end(); ++in) {
		*in = *in * *in;
	}
	for (auto in = Vec.begin(); in != Vec.end(); ++in) {
		cout << *in << " ";
	}
	cout << endl;
}
