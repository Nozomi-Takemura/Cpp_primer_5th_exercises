#include <string>
#include <iostream>
struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  Sales_data& combine(const Sales_data&);
  std::string isbn() const {return (*this).bookNo;}
};
Sales_data& Sales_data::combine(const Sales_data& rdh){
  (*this).units_sold += rdh.units_sold;
  (*this).revenue += rdh.revenue;
  return *this;}
Sales_data add(const Sales_data& rsd1, const Sales_data& rsd2){
  Sales_data sum = rsd1;
  sum.combine(rsd2);
  return sum;
}
std::istream& read(std::istream& inp, Sales_data& sd){
  //double price; 
  //inp >> sd.bookNo >> sd.units_sold >> price;
  inp >> sd.bookNo >> sd.units_sold >> sd.revenue;
  return inp;
}
std::ostream& print(std::ostream& out, const Sales_data& sd){
  out << "isbn: " << sd.isbn() << ", units_sold: " << sd.units_sold << ", total revenue: " << sd.revenue;
  return out;
}

int main(){
  Sales_data total;
  Sales_data trans;
  if(read(std::cin, total)){
    while (read(std::cin, trans)){
      std::cout << std::endl;
      if(total.isbn()== trans.isbn())
        total.combine(trans);
      else {
        print(std::cout, total) << std::endl;
        total = trans;
      }
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << "No data" << std::endl;
    return -1;
  }
  return 0;
}
