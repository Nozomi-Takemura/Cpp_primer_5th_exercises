#include <iostream>
//# include <vector>
//# include <iterator>
# include <string>
using std::cout; using std::endl;
//using std::vector;
//using std::begin; using std::end;
using std::string;

void f(int val, int pre, string text) {
	if (val == pre) {
		cout << text << endl;
	} else {
		cout << "Your answer is wrong" << endl;
	}
}

int main() {
	auto val = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
	int pre = ((12 / 3) * 4) + (5 * 15) + ((24 % 4)/2);
	f(val, pre, "Your answer is correct");
}

