#include <iostream>
int* reset(int *ptri){return ptri;}
double* reset(double * ptrd){return ptrd;}
int main(){
  int i = 1;
  double d = 3.14;
  std::cout << "int - " << *reset(&i) << std::endl;
  std::cout << "double - " << *reset(&d) << std::endl;
  std::cout << "int with double input- " << *reset(&d) << std::endl;
  std::cout << "double with int input - " << *reset(&i) << std::endl;
}
