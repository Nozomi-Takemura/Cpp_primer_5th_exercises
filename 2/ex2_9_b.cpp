#include <iostream>
/*
int main()
{
	int i = { 3.14 };
	std::cout << i << std::endl;	
	return 0;
}
/*
--
ERROR MESSAGE
ex2_9_b.cpp: In function ‘int main()’:
ex2_9_b.cpp:4:17: error: narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]
  int i = { 3.14 };
--
3.14 is type double, which cannot be used for the initialization with {}.
*/
// Corection
int main()
{
	double i = { 3.14 };
	std::cout << i << std::endl;	
	return 0;	
}
