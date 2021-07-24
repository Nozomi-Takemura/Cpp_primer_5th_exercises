#include<StrBlob.h>
#include<iostream>
#include<string>
using std::cout;
using std::endl;
int main(){
  StrBlob b2 = {"a", "an", "the"};
  StrBlob b1;
  const StrBlob b3 = {"1","2","3"};
  string s;
  b1 = b2;
  b2.push_back("about");
  s = b1.back();
  b1.back() = "OverWrite";
  cout << "--- non const version ----" << endl;
  std::cout << "last element of b1 - " << s << std::endl;
  cout << "--- after chages----" << endl;
  std::cout << "last element of b1 - " << b1.back() << std::endl;
  const string s2 = b3.back();
  cout << "--- const version ----" << endl;
  std::cout << "last element of b1 - " << s2 << std::endl;
  // this raises error
  //b3.back() = "4";
}
