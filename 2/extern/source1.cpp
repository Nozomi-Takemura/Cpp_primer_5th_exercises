//#include "header.h"
#include <iostream>
#include "source2.cpp"

int global_x = 10000;
//void print_global_x();
//const int myage = 27;
int main()
{

	std::cout << global_x << std::endl;
	print_global_x();
	global_x = 5;
	print_global_x();
}

