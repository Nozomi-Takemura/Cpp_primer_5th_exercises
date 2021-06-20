#include<iostream>
using namespace std;
int main(){
  auto lambda = [] (int i1, int i2) -> int {return i1+i2;};
  cout << " lambda expression: 1 + 5 = " << lambda(1,5) << endl;
}
