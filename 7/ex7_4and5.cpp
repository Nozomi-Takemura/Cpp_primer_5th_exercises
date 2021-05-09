#include <iostream>
struct Person {
  std::string name;
  std::string address;
  std::string pop_name() const {return (*this).name;}
  std::string pop_address() const {return (*this).address;}
};
int main(){
  Person Aperson;
  std::cout << "type your name;" << std::endl;
  std::cin >> Aperson.name;
  std::cout << "type your address;" << std::endl;
  std::cin >> Aperson.address;
  std::cout << "output from your class:" << std::endl;
  std::cout << Aperson.pop_name() << " - " << Aperson.pop_address()<< std::endl;

}
