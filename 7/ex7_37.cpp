#include <string>
#include <iostream>
struct Sales_data {
  public:
    // add constructors
    // default construct -1
//    Sales_data() = default;
//    ex7_37
    Sales_data(std::string s = ""): bookNo(s) { }
    // constructer only with bookNo -2
    //Sales_data(const std::string& s): bookNo(s) { }
    // normal constructure -3
    Sales_data(const std::string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    // istream constructer -4
    //constructer definition for -4
    Sales_data(std::istream &is) {
      Sales_data::read(is, *this);
    }
    Sales_data& combine(const Sales_data&);
    std::string isbn() const {return (*this).bookNo;}
  // moved print function to create a constructer inside class definition
    std::istream& read(std::istream& inp, Sales_data& sd){
      inp >> sd.bookNo >> sd.units_sold >> sd.revenue;
      // currently, the revenue is still price so needs to be multiplied by units_sold
      sd.revenue *= sd.units_sold;
      return inp;
    }
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
  friend Sales_data add(const Sales_data& rsd1, const Sales_data& rsd2);
  friend std::ostream& print(std::ostream& out, const Sales_data& sd);
  inline double avg_price() const;/*{
    return    revenue / units_sold;}*/
};
inline double Sales_data::avg_price() const{
  return    (*this).revenue / (*this).units_sold;}
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
  out << "isbn: " << sd.isbn() << ", units_sold: " << sd.units_sold << ", total revenue: " << sd.revenue << ", average_price" << sd.avg_price();
  return out;
}

Sales_data first_item(std::cin);
int main() {
print(std::cout, first_item) << "<-- member values for first_ite initializer" << std::endl;
    Sales_data next;
    print(std::cout, next) << "<-- member values for next initializer" << std::endl;
    Sales_data last("9-999-99999-9");
    print(std::cout, last) << "<-- member values for last initializer" << std::endl;
}
/*
int main(){
  Sales_data test;
  print(std::cout, test) << "<-- member values for default constructer initializer" << std::endl;
  Sales_data total(std::cin);
  if(std::cin){
    Sales_data trans(std::cin);
    while (std::cin){
      if(total.isbn() == trans.isbn())
        total.combine(trans);
      else {
        print(std::cout, total) << "inside else " <<  std::endl;
        total = trans;
      }
      trans.read(std::cin, trans);
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << "No data" << std::endl;
    return -1;
  }
  return 0;
}
*/
