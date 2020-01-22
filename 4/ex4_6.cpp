/*
Write an expression to determine whether an int value is
even or odd.
*/

#include <iostream>
# include <string>
# include <stdexcept>
using std::cout; using std::endl; using std::cin;
using std::string;
using std::runtime_error;

void f(int val, int pre, string text) {
	if (val == pre) {
		cout << text << endl;
	} else {
		cout << "Your answer is wrong" << endl;
	}
}

int main() {
	int input;
	cout << "Type an integer" << endl;
	if (!(cin >> input)) {
		throw runtime_error("Input must be an integer type");
	}
	if (input % 2){
		cout << input << " is an odd value" << endl;
	} else {
		cout << input << " is an even value" << endl;
	}
}

