#include <iostream>
#include <string>
#include <vector>
int main() {
using namespace std;
string inp = "abcdefgh";
auto it = inp.begin();
auto it_end = inp.end();
cout << "Type" << endl;
for (auto i : inp){
  cout << i << endl;
}
cout << "this is 'while' loop: " << endl;
while(it!=it_end){
  cout << *it << endl;
  ++it;
}
}

