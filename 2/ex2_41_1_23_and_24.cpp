#include <iostream>
#include "Sales_data.h"

int g(Sales_data book) {

	int totalCtr = 0;
	Sales_data curbook;

	// check if the input does exist	
	if (std::cin >> book.bookNo >> book.units_sold >> book.revenue) {
		// store current bookID
		curbook.bookNo = book.bookNo;
		totalCtr = 1;
		std::cout << "(totalCtr, bookNo) : (" << totalCtr << ", " << curbook.bookNo << ")" << std::endl;  
		// keep reading all the transactions.
		while(std::cin >> book.bookNo >> book.units_sold >> book.revenue) {
			// check if the bookIDs of multiple books are the same --> if so increace totalCtr
			if (curbook.bookNo == book.bookNo) {
				totalCtr += 1;
			}
			// if different ID is included, print totalCtr for curbook, initialize it to 1, and update curbook.
			else {
				std::cout << curbook.bookNo << " " << totalCtr << std::endl;
				totalCtr = 1;
				curbook = book;
			}
			std::cout << "(totalCtr, bookNo) : (" << totalCtr << ", " << curbook.bookNo << ")" << std::endl;
		}
		// print totalCtr for book.
		std::cout << book.bookNo << " " << totalCtr << std::endl;	
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

