#include<vector>
#include<iostream>
using namespace std;
bool f(vector<int>::iterator beg, const vector<int>::iterator end, const int cint){
  while(beg != end){
    if(*beg == cint)
      return true;
    ++beg;
  }
  return false;
}
int main(){
  int uint;
  vector<int> vinput = {1,2,3,4,5,6,7,8,9};
  cout << "type an integer between 1 and 9" << endl;
  if(cin >> uint){
    cout << "ok" << endl;
    cout << "if " << uint << " exists within {1,2,3,4,5,6,7,8,9}? " <<  f(vinput.begin(), vinput.end(), uint) << endl;
  }
}
