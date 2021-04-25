#include <iostream>
using namespace std;
int* fact(int results [2]){
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

int main(){
  int* outputs;
  outputs = fact(outputs);
  cout << "factorial of "<< *(outputs) << " is " << *(outputs+1) << endl;
}

