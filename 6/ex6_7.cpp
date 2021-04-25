#include <iostream>
using namespace std;
int gen(){
  static int seq;
    return seq++;
}
int main(){
  int tem;
  for (size_t i=0; i!=10;++i){
    tem = gen(); 
    while(tem >=  0){
      cout << tem << " ";
      --tem;
    }
    cout << endl;
  }
}
