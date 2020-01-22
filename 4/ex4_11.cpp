#include <iostream>
using std::cin; using std::cout; using std::endl;
int main() {
	int a, b, c, d;
	cout << "give int value for a" << endl;
	cin >> a;
	cout << "give int value for b" << endl;
	cin >> b;
	cout << "give int value for c" << endl;
	cin >> c;
	cout << "give int value for d" << endl;
	cin >> d;

	if ((a > b) && (b > c) && (c > d)) {
		cout << "a is greater than b, which is greater than c, which is greater than d" << endl;
	} else {
		cout << " It is not ensured that a > b > c > d" << endl;
	}
}	
