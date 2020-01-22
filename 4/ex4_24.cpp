#include <iostream>
#include <string>
using std::string; using std::cout; using std::endl;

int main(){
  bool p{true};
  bool q{false};
  string a = "high pass" ? "a" : "b";
  string b = p  ? "a" : "b";
  string c = q ? "fail" : "pass"; //
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
}
