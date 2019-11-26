#include <iostream>
/*
int main()
{
	double salary = wage = 9999.99;
	std::cout << salary << std::endl;	
	std::cout << wage << std::endl;	
	return 0;
}
/*
--
ERROR MESSAGE
ex2_9_c.cpp: In function ‘int main()’:
ex2_9_c.cpp:5:18: error: ‘wage’ was not declared in this scope
  double salary = wage = 9999.99;
                  ^~~~
--
double salary = wage <-- this is an initialization where non-defined wage is used; hence a compile error occurs.

*/
// Corection
/*
int main()
{
	double salary, wage = 9999.99;
	std::cout << salary << std::endl;// output = 0	
	std::cout << wage << std::endl;	// output = 9999.99
	return 0;
}
*/
int main()
{
	double salary = 9999.99, wage = 9999.99;
	std::cout << salary << std::endl;// output = 9999.99
	std::cout << wage << std::endl;	// output = 9999.99
	return 0;
}
