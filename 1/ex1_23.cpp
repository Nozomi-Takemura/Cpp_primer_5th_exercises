#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item curite, ite;
	int cnt;
//	while(std::cin >> curite)
//	{
	std::cin >> curite;
	cnt = 1;
	while(std::cin >> ite)
	{
		if(curite.isbn() == ite.isbn())
			++cnt;
		else
		{
			std::cout << "ISBN: " << curite.isbn() << " occurs " << cnt << " times." << std::endl;
			curite = ite;
			cnt = 1;  
		}
	}
	std::cout << "ISBN: " << curite.isbn() << " occurs " << cnt << " times." << std::endl;
	return 0;
//	}
}
