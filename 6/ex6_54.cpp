#include <iostream>
#include <vector>
using namespace std;
int f(int i1, int i2){
  return i1 + i2;
}
int main(){
int(*pf)(int, int) = f;
vector<int(*)(int,int)> vpf = {pf,pf,pf};
for (auto pft:vpf){
  cout << (*pft)(1,2) << endl;
}
}
