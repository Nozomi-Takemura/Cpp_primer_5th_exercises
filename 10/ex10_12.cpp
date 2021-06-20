#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Sales_data {
  public:
    Sales_data() = default;
    Sales_data(string argbk, unsigned argus, double argpr):bookNo(argbk), units_sold(argpr), revenue(argpr*argus)   {}
    inline string get_isbn() const{
      return bookNo;  
    }
    void display(){
      show();
    }
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    void show(){
      
    }
};
ostream& printSd(const Sales_data& rcsd, ostream& ros){
  ros << rcsd.get_isbn() << " ";
  return ros;
}
bool compareIsbn(const Sales_data& Sada1, const Sales_data& Sada2){
  const string isbn1 = Sada1.get_isbn();
  const string isbn2 = Sada2.get_isbn();
  return isbn1.size() < isbn2.size();
}

int main(){
 vector<Sales_data> vec{Sales_data("boo", 1, 2.5),Sales_data("book", 2, 3.5), Sales_data("boo", 1, 1.5)
   ,Sales_data("bookA", 1, 2.5), Sales_data("book", 2, 1.5), Sales_data("bookA", 1, 2.5)
   ,Sales_data("EnbookA",2, 4),Sales_data("GerbookA",3,5)};
 cout << "before sort - BookNumber of Sales_data in a vector: " << endl;
 for (const auto e : vec){
  printSd(e, cout);
 }
 cout << endl;
 sort(vec.begin(), vec.end(), compareIsbn);
 cout << "after sort - BookNumber of Sales_data in a vector: " << endl;
 for (const auto e : vec){
  printSd(e, cout); 
 }
 cout << endl;
}
