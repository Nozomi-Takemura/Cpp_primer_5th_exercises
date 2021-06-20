#ifndef MY_SALES_ITEM_H
#define MY_SALES_ITEM_h 
#include<iostream>
#include<string>
using namespace std;
class Sales_item {
  public:
    double price;
    Sales_item() = default;
    // this constructor is required to clean revenue and avg_price with new bookNo
    Sales_item(const string c_bookNo): bookNo(c_bookNo) {}
    Sales_item(istream &ris) {
      // double price;
      ris >> (this->bookNo) >> (this->units_sold) >> price;
      revenue = price*units_sold;
      ave_price = revenue/units_sold;
    }
    inline string isbn() const {return bookNo;};
    inline int get_units_sold() const {return units_sold;};
    inline double get_revenue() const {return revenue;};
    inline double get_ave_price() const {return ave_price;};
    bool if_bookNo_same (const Sales_item&) const;
    // bool if_bookNo_same() const;
    friend ostream & operator<<(ostream &, const Sales_item &);
    friend istream & operator>>(istream &, Sales_item &);
    // summation should be done between two Sales_items so no 'friend' is necessary
    Sales_item& operator+(const Sales_item &rc_sal_ite){
      //assume the bookNo is the same
      this->bookNo = rc_sal_ite.bookNo;
      this->units_sold += rc_sal_ite.units_sold;
      this->revenue += rc_sal_ite.revenue;
      this->ave_price = (this->revenue)/(this->units_sold);
      return *this;
    }
    // != will be used inside accumulate so needs to be defined
    // comparison needs to be done only for Sales_item type so no 'friend' is necessary
    inline bool operator!=(const Sales_item& rhs){
      return this->isbn().compare(rhs.isbn());
    }
    // assignment = operator is also mandatory for accumulate
    // it is supposed that two Sales_items are the same if their bookNo are the same
    // inline Sales_item& operator=(const Sales_item& rhs){
      // this->bookNo = rhs.isbn();
      // this->units_sold = rhs.get_units_sold();
      // this->revenue = rhs.get_revenue();
      // this->ave_price = rhs.get_ave_price();
      // return *this;
    // }
  private:
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
    double ave_price = 0.0;
};
bool Sales_item::if_bookNo_same(const Sales_item &rc_sal_ite) const{
  return !(this->bookNo).compare(rc_sal_ite.isbn()); 
}

ostream & operator<<(ostream & ros, const Sales_item &rc_sal_ite){
  ros << "bookNo: " << rc_sal_ite.isbn() << ", units_sold: " 
    << rc_sal_ite.get_units_sold() << ", revenue: "
    << rc_sal_ite.get_revenue() << ", ave_price: " << rc_sal_ite.get_ave_price();
  return ros;
}
istream & operator>>(istream & ris, Sales_item &r_sal_ite){
  ris >> r_sal_ite.bookNo >> r_sal_ite.units_sold >> r_sal_ite.price; 
  r_sal_ite.revenue = r_sal_ite.price*r_sal_ite.units_sold;
  r_sal_ite.ave_price = r_sal_ite.revenue/r_sal_ite.units_sold;
  return ris;
}
#endif
