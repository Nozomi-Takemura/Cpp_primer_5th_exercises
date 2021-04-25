#include <iostream>
#include <string>
using namespace std;
void check(string& s){
  for (decltype (s.size()) sz = 0; sz != s.size(); ++sz){
    char c;
    c = std::tolower(s[sz]);
    s[sz] = c;
  }
}
int main(){
  string inp_re = "ABCDE";
  cout << "input : " << inp_re << endl;
  check(inp_re);
  cout << "output : " << inp_re << endl;
}
