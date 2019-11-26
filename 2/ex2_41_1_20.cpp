#include <iostream>
#include "Sales_data.h"

void f(Sales_data data) {
	if (std::cin >> data.bookNo >> data.units_sold >> data.revenue)
		std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << std::endl;
		while (std::cin >> data.bookNo >> data.units_sold >> data.revenue)
					std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << std::endl;

}

int main()
{
	Sales_data data;
	f(data);
	
}
