#include <string>
#include <iostream>
class Book{
  //friend Book read(std::istream& is, Book& rbk);
  friend std::ostream& print(std::ostream& os, const Book& crbk);
  public:
    Book(std::string s = "", int i = 0): title(s), aurthor(s), NrPages(i), genre(s) { }
    Book(const std::string& ti, const std::string& au, const int np, const std::string ge): title(ti), aurthor(au), NrPages(np), genre(ge) { }
    Book(std::istream& is) {
      read (is, *this);
    }
//    std::istream& read(std::istream& is, Book& rbk);
    std::istream& read(std::istream& is, Book& rbk){
      is >> rbk.title >> rbk.aurthor >> rbk.NrPages >> rbk.genre;
      return is;
    }
  private:  
    std::string title;
    std::string aurthor;
    int NrPages = 0;
    std::string genre;
};
std::ostream& print(std::ostream& os, const Book& crbk){
  os << "tile:" << crbk.title << ", aurthor:" << crbk.aurthor << ", NrPages:" << crbk.NrPages << ", genre:" << crbk.genre;
  return os;
}
int main(){
  Book A;
  Book B("HarryPotter", "JKRolling", 560, "fantazy");
  Book C(std::cin);
  std::cout << "Book A - default constructor initialization: " << std::endl;
  print(std::cout, A) << std::endl;
  std::cout << "Book B - initialization passing all 4 member values: " << std::endl;
  print(std::cout, B) << std::endl;
  std::cout << "Book C - initialization with user input: " << std::endl;
  print(std::cout, C) << std::endl;
}
