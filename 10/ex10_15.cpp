#include<iostream>
using namespace std;
int main(){
  const int ig = 10;
  auto lambda = [ig] (int i1, int i2) -> int {return i1+i2+ig;};
  cout << " lambda expression: 1 + 5 + 10(<- captured by enclosing function) = " << lambda(1,5) << endl;
}
