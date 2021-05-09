#include <string>
#include <iostream>
struct Sales_data {
  // add constructors
  // default construct -1
  Sales_data() = default;
  // constructer only with bookNo -2
  Sales_data(const std::string& s): bookNo(s) { }
  // normal constructure -3
  Sales_data(const std::string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
  // istream constructer -4
  Sales_data(std::istream& is);

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
  // currently, the revenue is still price so needs to be multiplied by units_sold
  sd.revenue *= sd.units_sold;
  return inp;
}
std::ostream& print(std::ostream& out, const Sales_data& sd){
  out << "isbn: " << sd.isbn() << ", units_sold: " << sd.units_sold << ", total revenue: " << sd.revenue;
  return out;
}
//constructer definition for -4
Sales_data::Sales_data(std::istream &is) {
  read(is, *this);
}

int main(){
  // constr - 1
  Sales_data total;
  Sales_data trans;
  // constr -2
  Sales_data total2("booknr1");
  // constr -3
  Sales_data total3("booknr2", 3, 100);
  std::cout << "type, booknr, nr of units, and price with space" << std::endl;
  // constr -4
  Sales_data total4(std::cin);
  std::cout << "Sales_data initialized by 1st constructer:" << std::endl;
  print(std::cout, total) << std::endl;
  std::cout << "Sales_data initialized by 2nd constructer:" << std::endl;
  print(std::cout, total2) << std::endl;
  std::cout << "Sales_data initialized by 3rd constructer:" << std::endl;
  print(std::cout, total3) << std::endl;
  std::cout << "Sales_data initialized by 4th constructer:" << std::endl;
  print(std::cout, total4) << std::endl;

/*  if(read(std::cin, total)){
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
*/
}
