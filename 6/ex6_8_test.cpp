#include <iostream>
#include "exheader.h"
#include <string>
using namespace std;
/*
int fact_6_3(int n){
  int prod = 1;
  while(n > 0){
    //cout << n << " ";
    prod *= n;
    --n;
  }
  return prod;
}
int* fact_6_4(int results [2]){
  int prod = 1;
  int inp;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  results[0] = inp;
  while(inp > 0){
    //cout << n << " ";
    prod *= inp;
    cout << "current prod = " << prod << " ";
    --inp;
  }
  results[1] = prod;
  cout << endl;
  return results;   
}
unsigned int abso_6_5(int inp){
  int oup;
  if(inp<0){
    oup = -1*inp;
  }
  else {
    oup = inp;
  }
  return oup;
}
*/
int main(){
  int inp;
//  int* outputs;
  int outputs [2];
  int ui;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  cout << "factorial of "<< inp << " is " << fact_6_3(inp) << endl;
  cin.clear();
  fact_6_4(outputs);
  cout << "factorial of "<< *(outputs) << " is " << *(outputs+1) << endl;
  cout << "Type any integer value for which the absolute value needs to be returned : " << endl;
  cin.clear();
  cin >> ui;
  cout << "abosolute(" << ui <<")=" << abso_6_5(ui) << endl;
  cout << "Type any integer value for which the absolute value needs to be returned : " << endl;
  cin >> ui;
  cout << "abosolute(" << ui <<")=" << abso_6_5(ui) << endl;
}
