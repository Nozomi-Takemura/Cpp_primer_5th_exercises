#include <iostream>
#include <string>
using namespace std;
int main(){
  string inp;
  string preinp;
  bool ifbreak=true;
  while(cin >> inp){
    cout << inp << endl;
    if (!inp.compare(preinp)){
      cout << "word " << inp << " occurs twice" << endl;
      ifbreak = false;
      break;
    }
    preinp = inp;
  }
  if(ifbreak){
    cout << "no word was repeated."<<endl;
  }
}
