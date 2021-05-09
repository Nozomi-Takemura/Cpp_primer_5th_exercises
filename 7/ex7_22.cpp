#include <iostream>
struct Person {
  private:
    std::string name;
    std::string address;
  public:
    std::string pop_name() const {return (*this).name;}
    std::string pop_address() const {return (*this).address;}
    // constructer
    Person () = default;
    Person (std::istream& is) {
      is >> (*this).name >> (*this).address;
    }
  friend std::istream& read(std::istream &is, Person& aperson);
};
std::istream& read(std::istream &is, Person& aperson){
  is >> aperson.name >> aperson.address;
  return is;
}
std::ostream& print(std::ostream &os, const Person& aperson){
  os << "name: " << aperson.pop_name() << ", address: " << aperson.pop_address();
  return os;
}
int main(){
  std::cout << "type your name;" << std::endl;
  std::cout << "type your address;" << std::endl;
  Person Aperson(std::cin);
  std::cout << "output from your class:" << std::endl;
  print(std::cout, Aperson) << std::endl;
}
