#include <iostream>
using namespace std;
void reset(int &input){
  cout << "Initialize input:" << endl;
  input = 0;
}
int main(){
  int input = 100;
  cout << "Original input :" << input << endl;
  reset(input);
  cout << "input after reset : " << input << endl;
}
