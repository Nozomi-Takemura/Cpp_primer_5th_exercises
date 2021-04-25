#include <iostream>
#include <string>
inline bool isShorter(const std::string &s1, const std::string &s2){
  return s1.size() < s2.size();
}
int main(){
  std::string tmp;
  std::cout << "type first string" << std::endl;
  std::cin >> tmp;
  const std::string cstr1 = tmp;
  std::cout << "type second string" << std::endl;
  std::cin >> tmp;
  const std::string cstr2 = tmp;
  std::cout << "if first string is shorter than second string: " << (cstr1.size() < cstr2.size())<< std::endl;
  //std::cout << "if first string is shorter than second string: " << isShorter(cstr1, cstr2) << std::endl;
}
