#include <iostream>
using namespace std;
int fact(int n){
  int prod = 1;
  while(n > 0){
    //cout << n << " ";
    prod *= n;
    --n;
  }
  return prod;
}

int main(){
  int inp;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  cout << "factorial of "<< inp << " is " << fact(inp) << endl;
}

