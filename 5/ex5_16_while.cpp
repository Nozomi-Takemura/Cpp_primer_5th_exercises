#include <iostream>
#include <string>
#include <vector>
int main() {
using namespace std;
//using namespace vector;
string inp;
vector<string> vec;
// auto beg = vec.begin();
int ifreapp = 0;
int maxrep = 1;
string word;
string cinpre;
cout << "Type" << endl;
while (cin >> inp){
  cout << inp << " ";
  if (inp.compare(cinpre)==0){
    ++ifreapp;
  } else {
    if (maxrep < ifreapp){
      maxrep = ifreapp;
      word = cinpre;
    } 
    ifreapp = 1;
  }
    vec.push_back(inp);
  cinpre = inp;
}
cout << "Maximum repetition is the word " << word << ", and occurred " << maxrep  << "times." << endl;
cout << "help" << endl;
}

