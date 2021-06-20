#include<iostream>
using namespace std;
int main(){
  int i = 10;
  bool tof;
  auto lambda = [&i] () -> bool {
    if (i>0){
      --i;
      return (i==0);
    }
    else if (i == 0)
      return (i==0); 
  };
  cout << "while (!lambda()) for int=10:" << endl;
  cout << "chnages of (i,lambda())  per iteration: " << endl;
  while(!(tof=lambda()))
    cout << "(" << i << ", " << tof  <<  "), ";
  cout << endl;
  cout << "after while (!lambda()) loop" << endl;
  cout << "(" << i << ", " << tof  <<  "), ";
  cout << endl;
}
