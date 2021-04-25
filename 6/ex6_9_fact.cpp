#include <iostream>
using namespace std;
int fact_6_3(int n){
  int prod = 1;
  while(n > 0){
    //cout << n << " ";
    prod *= n;
    --n;
  }
  return prod;
}

