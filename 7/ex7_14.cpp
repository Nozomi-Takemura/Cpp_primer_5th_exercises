#include <string>
#include <iostream>
struct Sales_data {
  // add constructors
  // default construct -1
  Sales_data(): bookNo(), units_sold(), revenue() {};
  // constructer only with bookNo -2
  Sales_data(const std::string& s): bookNo(s) { }
  // normal constructure -3
  Sales_data(const std::string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
  // istream constructer -4
  //constructer definition for -4
  Sales_data(std::istream &is) {
    Sales_data::read(is, *this);
}
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  Sales_data& combine(const Sales_data&);
  std::string isbn() const {return (*this).bookNo;}
  // moved print function to create a constructer inside class definition
  std::istream& read(std::istream& inp, Sales_data& sd);//{
/*  inp >> sd.bookNo >> sd.units_sold >> sd.revenue;
    // currently, the revenue is still price so needs to be multiplied by units_sold
    sd.revenue *= sd.units_sold;
    return inp;
  }
*/};
std::istream& read(std::istream& inp, Sales_data& sd){
  inp >> sd.bookNo >> sd.units_sold >> sd.revenue;
  // currently, the revenue is still price so needs to be multiplied by units_sold
  sd.revenue *= sd.units_sold;
  return inp;
}
Sales_data& Sales_data::combine(const Sales_data& rdh){
  (*this).units_sold += rdh.units_sold;
  (*this).revenue += rdh.revenue;
  return *this;}
Sales_data add(const Sales_data& rsd1, const Sales_data& rsd2){
  Sales_data sum = rsd1;
  sum.combine(rsd2);
  return sum;
}
std::ostream& print(std::ostream& out, const Sales_data& sd){
  out << "isbn: " << sd.isbn() << ", units_sold: " << sd.units_sold << ", total revenue: " << sd.revenue;
  return out;
}

int main(){
  // constr - 1
  Sales_data total;
  Sales_data trans;
  print(std::cout, total) << "<-- this is total" << std::endl;
  print(std::cout,trans) << "<-- this is trans" << std::endl;
  std::cout << "type the value for total " << std::endl;
  read(std::cin, total);
  std::cout << "type the value for trans " << std::endl;
  read(std::cin, trans);
  print(std::cout, total) << "<-- this is total after read" << std::endl;
  print(std::cout,trans) << "<-- this is trans after read" << std::endl;
  return 0;
}
