#include <iostream>
#include "Sales_data.h"

double calc_avepri(double totalRev, int totalCtr) {
	double avepri = 0.0;
	if (totalCtr != 0) {
		avepri = totalRev/totalCtr;
	}
	else {
		std::cout << "These are no sales" << std::endl;
	}
	return avepri;
}

int g(Sales_data book) {

	int totalCtr = 0;
	Sales_data curbook;
	double totalRev = 0.0;
	double avepri = 0.0;
	// check if the input does exist	
	if (std::cin >> book.bookNo >> book.units_sold >> book.revenue) {
		totalCtr = book.units_sold;
		totalRev = book.units_sold * book.revenue;
		curbook.bookNo = book.bookNo;
		// keep reading all the transactions.
		while(std::cin >> book.bookNo >> book.units_sold >> book.revenue) {
			// check if the bookIDs of multiple books are the same
			if (curbook.bookNo == book.bookNo) {
				totalCtr += book.units_sold;
				totalRev += book.units_sold * book.revenue;
			}
			// if different ID is included, the progam is immediately terminated.
			else {
				avepri = calc_avepri(totalRev, totalCtr);
				std::cout << book.bookNo << " " << totalCtr << " " << totalRev << " " << avepri << std::endl;
				std::cerr << "The input transaction contains the different bookIDs:  "<< book.bookNo << "." <<  std::endl;
				return -1;
			}
		}
		// When bookIDs are the same, calculate average price and print
		avepri = calc_avepri(totalRev, totalCtr);
		std::cout << book.bookNo << " " << totalCtr << " " << totalRev << " " << avepri << std::endl;
		return 0;
	}
	else {
		std::cerr << "There are no suitable inputs transactions at all." << std::endl;
		return -1;
	}

}

int main() {
	Sales_data book;
	g(book);
}

