#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Sales_data {
  friend ostream& print(ostream& os, const Sales_data& crsd);
  friend istream& read(istream& is, Sales_data& rsd);
  public:
    inline const string& isbn() {return bookNo;}
    Sales_data& combine(const Sales_data& crsd);
  private:
    /*
    ostream& do_disply(ostream& os){
      os << "bookNo=" << bookNo << " " << "units_sold=" << units_sold << " revenue=" << revenue;
      return os;
    }
    */
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& crsd){
  units_sold += crsd.units_sold;
  revenue += crsd.revenue;
  return (*this);
}
istream& read(istream& is, Sales_data& rsd){
  double price;
  is >> rsd.bookNo >> rsd.units_sold >> price;
  rsd.revenue = price*rsd.units_sold;
  return is;
}
ostream& print(ostream& os, const Sales_data& crsd){
  os << "bookNo=" << crsd.bookNo << " " << "units_sold=" << crsd.units_sold << " revenue=" << crsd.revenue;
}
int main(int argc, const char** argv){
  string fname(argv[1]);
  string foutname(argv[2]);
  cout << fname << endl;
  Sales_data total;         // variable to hold the running sum
  ifstream fin;
  ofstream fout;
  fin.open(fname);
  fout.open(foutname);
  if(fin.is_open()){
    if (read(fin, total))  {  // read the first transaction
        Sales_data trans;     // variable to hold data for the next transaction
        while(read(fin, trans)) {      //  read the remaining transactions
            if (total.isbn() == trans.isbn())   // check the isbns
                total.combine(trans);  // update the running total
            else {
              if(fout){
                print(fout, total) << endl;  // print the results
                total = trans;               // process the next book
              }
            }
        }
        if(fout){
          print(fout, total) << endl;          // print the last transaction
        }
    } else {                                 // there was no input
        cerr << "No data?!" << endl;         // notify the user
    }
  } else 
    cerr << "Cannot find/open Input file: " << fname; 
  fin.close();
  fout.close();
}
