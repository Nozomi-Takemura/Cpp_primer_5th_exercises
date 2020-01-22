#include <iostream>
# include <vector>
# include <iterator>
# include <string>
using std::cout; using std::endl;
using std::vector;
using std::begin; using std::end;
using std::string;

void f(int val, int pre, string text) {
	if (val == pre) {
		cout << text << endl;
	} else {
		cout << "Your answer is wrong" << endl;
	}
}

int main() {
	// precedence order: 1 = . 2 = () , 3 = dereference *
	vector<int> vec{1,2,3};	
	auto beg = *vec.begin();	
	auto beg_pred = *(vec.begin()); // prediction
	// precedence order: 1 = . 2 = () , 3 = dereference * 4 = addition: +
	auto plu = *vec.begin() + 1;
	auto plu_pred = (*(vec.begin())) + 1; // prediction
	
	f(beg, beg_pred, "Your answer for 'a' is correct.");
	f(plu, plu_pred, "Your answer for 'b' is correct.");

}
