#include <iostream>
#include <string>
using namespace std;
bool ex6_18_check(const string& s){
  bool re = false;
  for (auto c : s){
    if (isupper(c)) re = true;
    // cout << c << ' ';
  }
  return re; 
}
int main(){
  bool re;
  re = ex6_18_check("test Subject");
  cout << "for (auto c: s) style - a string, test Subject , contains a capital letter = " << re <<  endl;
  re = ex6_18_check("test subject");
  cout << "for (auto c: s) style - a string, "<< "test subject , contains a capital letter = " << re <<  endl;
  }
