#include<iostream>
int calc(int& a, int& b){return a;}
int calc(const int& a, const int& b){return a;}
int main(){
  int a=5;
  const int b = 10;
  std::cout << "nonconst" << calc(a,a) << std::endl;
  std::cout << "const" << calc(b,b) << std::endl;
}
