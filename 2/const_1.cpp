#include <iostream>
#include "const.h"
//#include "const_2.cpp"


extern int a;
extern int b;
extern const int c;
int main()
{
//	extern const int bufSize = foo();
	int total = 10;
	std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
	a = 100;
 	b = 1000;	
//	c = 1;
	std::cout << "a: " << a << " b: " << b <<  " c: " << c << std::endl;
}
