#include<iostream>
int calc(int* a, int* b){return *a;}
int calc( int* const a, int*  const b){return *a;}
int main(){
  int aderef = 5;
  int bderef = 10;
  int* a=&aderef;
  int* const b = &bderef;
  std::cout << "nonconst" << calc(a,a) << std::endl;
  std::cout << "const" << calc(b,b) << std::endl;
}
