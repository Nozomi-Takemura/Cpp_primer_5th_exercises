/*
a: int
b: int
c: int
d: int&
(a,b,c,d) = (4,4,4,4)
*/

#include <iostream>
int main()
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;
	std::cout << "(a,b,c,d) = (" << a << ", " << b << ", " << c << ", " << d << ")" << std::endl;
}
