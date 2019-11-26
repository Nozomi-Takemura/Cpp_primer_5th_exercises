#include <iostream>
#include "Sales_data.h"

void f(Sales_data data) {
	if (std::cin >> data.bookNo >> data.units_sold >> data.revenue)
		std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << std::endl;
		while (std::cin >> data.bookNo >> data.units_sold >> data.revenue)
					std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << std::endl;

}

int g(Sales_data book1, Sales_data book2) {
	double totalRev = 0.0;
	int totalCtr = 0;
	double avepri = 0.0;
	if (std::cin >> book1.bookNo >> book1.units_sold >> book1.revenue) {
		//std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << std::endl;
		while (std::cin >> book2.bookNo >> book2.units_sold >> book2.revenue) {
			if (book1.bookNo == book2.bookNo) {
				totalCtr = book1.units_sold +  book2.units_sold;
				totalRev = book1.revenue * book1.units_sold + book2.revenue * book2.units_sold;
				if (totalCtr != 0)				
					avepri = totalRev/totalCtr;
				else {
					std::cout << "There is no sales." << std::endl;				
				}
			}
			else {
				std::cerr << "The book IDs must be the same" << std::endl;
				return -1;
			}
		}
		std::cout << book1.bookNo << " " << totalCtr << " " << totalRev << " " << avepri << std::endl;
		return 0;
	} 
	else {
		std::cerr << "The input requires two lines of book sales information." << std::endl;	//		
		return -1;
	}
}
int main()
{
	Sales_data book1, book2;
	g(book1, book2);
	
}
