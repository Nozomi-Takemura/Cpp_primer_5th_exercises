#include <string>
#include <iostream>
std::istream& f(std::istream& is){
  std::string inp;
  while(!is.eof()){
    is >> inp;
    std::cout << inp << " ";
  }
  is.clear();
  return is;
}
int main(){
  f(std::cin);
}
