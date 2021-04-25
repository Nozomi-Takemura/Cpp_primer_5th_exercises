#include <iostream>
void f(){std::cout<<"no input"<<std::endl;}
void f(int){std::cout << "one input "<< std::endl;}
void f(int, int){std::cout << "two int inputs" << std::endl;}
void f(double, double = 3.14){std::cout << "two double inputs" << std::endl;}
int main(){
//  f(2.56, 42);
  f(42);
  f(42,0);
  f(2.56,3.14);
}
