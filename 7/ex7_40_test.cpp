#include <string>
#include <iostream>
struct Sales_data {
  public:
/*    Sales_data(std::string s = ""): bookNo(s) { }
    Sales_data(std::istream& is = std::cin) {is >> (*this).bookNo;  }
    Sales_data(const std::string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data& combine(const Sales_data&);
    std::string isbn() const {return (*this).bookNo;}
  */  std::istream& read(std::istream& inp, Sales_data& sd){
      inp >> sd.bookNo >> sd.units_sold >> sd.revenue;
      sd.revenue *= sd.units_sold;
      return inp;
    }
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

