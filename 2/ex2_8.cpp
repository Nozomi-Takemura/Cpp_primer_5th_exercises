#include <iostream>
int main()
{
	std::cout << "2\115\012" << std::endl;
	std::cout << sizeof("2\115\012") << std::endl;
	std::cout << "2M" << std::endl;
	std::cout << sizeof("2M\n") << std::endl;
	std::cout << sizeof(123456) << std::endl;
	std::cout << sizeof("123456") << std::endl;
	std::cout << "solution: \n" << "2\t\115\012" << std::endl;
	char a = 4;
	return 0;
}
