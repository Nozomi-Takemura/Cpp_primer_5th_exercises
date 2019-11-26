#include <iostream>
#include "const.h"

extern int a;
extern int b;
extern const int c;
int change(int* a, int* b, int* c)
{
	std::cout << "a: " << ::a << " b: " << ::b <<  " c: " << ::c << std::endl;
	*a = 0;
 	*b = 0;	
	*c = 0;
	std::cout << "a: " << *a << " b: " << *b <<  " c: " << *c << std::endl;
}
