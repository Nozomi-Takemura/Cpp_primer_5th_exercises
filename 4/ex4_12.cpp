/*
i != j < k means (i != j) && (j < K). Namely, K is larger than j, which is not equal to i. This is what the authour would expect.

However, in the reality, i != j returns bool, which is converted into either 0 or 1 when passed to the left operand for < operator. Hence, 1/0 < k is evaluated depending on the values i, j. 
1. i is not equal to j, and k is larger than 1.
2. i is equal to j, and k is larger than 0.   


*/
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
	int i, j, k;
	cout << "give int value for i" << endl;
	cin >> i;
	cout << "give int value for j" << endl;
	cin >> j;
	cout << "give int value for k" << endl;
	cin >> k;
	if (i != j < k) {
		std::cout << "Either \n 1. i is not equal to j, and k is larger than 1. \n 2. i is equal to j, and k is larger than 0." << std::endl;
	}
}
