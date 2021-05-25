#include <string>
#include <iostream>
#include <sstream>
std::istream& f(std::istream& is){
  std::string inp;
  std::cout << std::endl;
  while(!is.eof()){
    is >> inp;
    std::cout << inp << " ";
  }
  is.clear();
  return is;
}
int main(){
  //f(std::cin);
  std::string line;
  while (std::getline(std::cin, line))
  {
    std::stringstream record(line);
    f(record);
  }
}
