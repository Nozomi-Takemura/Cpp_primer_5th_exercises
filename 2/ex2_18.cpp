#include <iostream>
int main()
{
	int a = 4, b = 6, *ptra = nullptr;
	ptra = &a;
	std::cout << "*ptra: " << *ptra << std::endl;	
	ptra = &b;
	std::cout << "*ptra: " << *ptra << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	*ptra = a;
	std::cout << "*ptra: " << *ptra << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	*ptra = 10;
	std::cout << "*ptra: " << *ptra << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
}

	
