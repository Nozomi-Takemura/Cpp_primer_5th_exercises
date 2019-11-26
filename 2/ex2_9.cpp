#include <iostream>
/*
int main()
{
	std::cin >> int input_value;
	return 0;
}
/*
----
error: expected primary-expression before ‘int’
- The type delaration must be used only when the variable is defined; 
----
*/
int main()
{
	int input_value;
	std::cin >> input_value;
	std::cout << input_value << std::endl;
	return 0;
}
