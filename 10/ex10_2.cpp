#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using std::string;
int main(){
  std::list<string> ilist;
  string s;
  std::cout << "type a series of integers: " << std::endl;
  while(std::cin >> s){
    ilist.push_back(s);
  }
  std::cout << "type the integer you want to count: " << std::endl;
  std::cin.clear();
  std::cin >> s;
  std::cout << "the integer " << s<< " appears " << count(ilist.begin(), ilist.end(), s) << " times." << std::endl;
}
