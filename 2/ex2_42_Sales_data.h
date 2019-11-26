#ifndef SALES_DATA
#define SALES_DATA
#include <string>
struct Sales_data {
	std::string bookNo;
	int units_sold = 0;
	double revenue = 0.0;
};
#endif 
