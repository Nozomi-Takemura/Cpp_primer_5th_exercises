/*
What does overflow mean? Show three expressions that will
overflow.

Overflow indicates the situation where a value is assigned to to a variable whose type cannot represent that value.  
*/

#include <iostream>
# include <string>
# include <stdexcept>
using std::cout; using std::endl; using std::cin;
using std::string;



int main() {
	// case. 1
	short sh = 32767;
	sh += 2;
	// case. 2
	char ch_int = 255;
	ch_int += 1;
	// case. 3
	int in = 2147483648 - 1;
	in += 10;
	long lo = -461168601800000000;//  999999999;//  - 1;
	lo -= -9000000000000000000;            
	cout << "more than 32767 for short type value: " << sh << endl;
	cout << "more than 255 for char type value: " << ch_int << endl;
	cout << "more than 1073741824 for int type value: " << in << endl;
	cout << "more than ~10^19 for long type value: " << lo << endl;
}

