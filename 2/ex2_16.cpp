#include <iostream>
int main()
{
	int i = 0, &r1 = i; double d = 0, &r2 = d;
	std::cout << "i: " << i << "r1: " << r1 << "d: " << d << "r2: " << r2 << std::endl;
	r2 = 3.14159; // 0 --> 3.14159
	std::cout << "i: " << i << "r1: " << r1 << "d: " << d << "r2: " << r2 << std::endl;
//	r2 = r1; // invalid bc int vs double
	std::cout << "i: " << i << "r1: " << r1 << "d: " << d << "r2: " << r2 << std::endl;
	i = r2; // invalid bc int <- double ; the result is trancated
	std::cout << "i: " << i << "r1: " << r1 << "d: " << d << "r2: " << r2 << std::endl;
	r1 = d; // invalid bc int <- double ; the result is trancated
	std::cout << "i: " << i << "r1: " << r1 << "d: " << d << "r2: " << r2 << std::endl;
}
