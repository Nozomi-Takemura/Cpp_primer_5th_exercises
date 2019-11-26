#include <iostream>
//#include "header.h"

extern int global_x;
int const myage = 60;
void print_global_x()
//const int myage = 60;
{
//	myage = 30;
	std::cout << "global_x " << global_x << " myage: " << myage << std::endl;
}
