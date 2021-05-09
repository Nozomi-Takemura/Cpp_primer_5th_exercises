#include <string>
#include <iostream>
struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main(){
  Sales_data total;
  Sales_data trans;
  if(std::cin >> total.bookNo >> total.units_sold >> total.revenue){
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue ){
      std::cout << std::endl;
      if(total.bookNo == trans.bookNo)
        total.units_sold += trans.units_sold;
      else {
        std::cout << "isbn: " << total.bookNo << "-units_sold: " << total.units_sold << std::endl;
        total.units_sold = trans.units_sold;
      }
    }
    std::cout << "isbn: " << total.bookNo << ", units_sold: " << total.units_sold << std::endl;
    std::cout << total.units_sold << std::endl;
  } else {
    std::cerr << "No data" << std::endl;
    return -1;
  }
  return 0;
}
