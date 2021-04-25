#include <iostream>
#include <vector>
using namespace std;
int f(int i1, int i2);
int fadd(int i1, int i2){
  return i1 + i2;
}
int fsub(int i1, int i2){
  return i1 - i2;
}
int fmul(int i1, int i2){
  return  i1*i2;
}
int fdev(int i1, int i2){
  return i1/i2;
}
int main(){
  typedef decltype(f) *pf;
  //int(*pf)(int, int) = f;
  vector<pf> vpf = {*fadd,*fsub,*fmul,*fdev};
  //vector<int(*)(int,int)> vpf = {*fadd,*fsub,*fmul,*fdev};
  cout << "given two integer, 1, 2, the 1. addition, 2.subtraction, 3.multiplication, 4.devision:" << endl;
  for (auto pft:vpf){
    cout << (*pft)(1,2) << endl;
  }
}
