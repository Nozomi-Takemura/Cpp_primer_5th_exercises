#include<iostream>
#include <string>
std::string (*f())[10]{
  static std::string staarrstr[10]={"a","a","a","a","a","b","b","b","b","b"};
  return &staarrstr;} 
int main(){
  for (auto str : *f()){
    std::cout << str << " ";
  }
  std::cout << std::endl;
}
