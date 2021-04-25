#include <iostream>
using namespace std;
int conditionand(int inp){
  static int conand = 1;
  if(inp>0){
    conand *= 1;}
  else {
    conand *= 0;
  }
  return conand;
}

int main(){
  int input;
  int finalinput;
  cout << "Type multiple pos and neg int. The program should return 1 if all ints are pos, while return 0 otherwise." << endl;
  while(cin >> input){
    conditionand(input);
  }
  cout << "final result = " << conditionand(1) << endl;
}
