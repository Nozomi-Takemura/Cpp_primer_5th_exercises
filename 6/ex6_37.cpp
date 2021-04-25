#include <string>
#include<iostream>
// type alias
typedef std::string arrT[10];
arrT &f(){
  static std::string staarrstr[10]={"a","a","a","a","a","b","b","b","b","b"};
  return staarrstr;} 
// trailing return 
auto tr() -> std::string (&)[10]{

  static std::string staarrstr[10]={"a","a","a","a","a","b","t","r","a","i"};
  return staarrstr; 
} // -> std::string (&)[10];

// decltype
std::string arr_global[10]={"a","a","a","a","a","b","d","e","c","l"};
decltype(arr_global) &dt(){
  return arr_global;
  }
int main(){
  std::cout << "type alias:" << std::endl;
  for (auto str : f()){
    std::cout << str << " ";
  }
  std::cout << std::endl;
  std::cout << "trailing return:" << std::endl;
  for (auto str : tr()){
    std::cout << str << " ";
  }
  std::cout << std::endl;
  std::cout << "decltype:" << std::endl;
  for (auto str : dt()){
    std::cout << str << " ";
  }
  std::cout << std::endl;
}

