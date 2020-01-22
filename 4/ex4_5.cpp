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
	auto a = -30 * 3 + 21 / 5;
	auto b = -30 + 3 * 21 / 5;
	auto c = -30 / 3 * 21 % 5;
	auto d = -30 / 3 * 21 % 4;

	int a_pre = -86;
/*
	int b_pre = -18; // WRONG
	int c_pre = -42; // WRONG
	int d_pre = -52; // WRONG
*/
	int b_pre = -18 ; // WRONG
	int c_pre = 0; // WRONG
	int d_pre = -2; // WRONG

	f(a, a_pre, "Your answer for 'a' is correct");
	f(b, b_pre, "Your answer for 'b' is correct");
	f(c, c_pre, "Your answer for 'c' is correct");
	f(d, d_pre, "Your answer for 'd' is correct");
}

