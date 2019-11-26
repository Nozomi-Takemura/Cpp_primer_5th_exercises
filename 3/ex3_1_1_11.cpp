#include <iostream>
using std::cout; using std::cin; using std::endl;
int main() {
	int max, min;
	cout << "Enter two integers in a descendent order" << endl;
	cin >> max >> min;
	while (max >= min) {
		cout << max << " ";
		max--;
	}
	cout << endl;
}
