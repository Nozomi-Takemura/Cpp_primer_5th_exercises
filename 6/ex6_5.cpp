#include <iostream>
using namespace std;
unsigned int abso(int inp){
  int oup;
  if(inp<0){
    oup = -1*inp;
  }
  else {
    oup = inp;
  }
  return oup;
}

int main(){
  int ui;
  cout << "Type any integer value for which the absolute value needs to be returned : " << endl;
  cin >> ui;
  cout << "abosolute(" << ui <<")=" << abso(ui) << endl;
}

