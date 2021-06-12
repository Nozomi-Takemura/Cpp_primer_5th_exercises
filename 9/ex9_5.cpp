#include<vector>
#include<iostream>
using namespace std;
vector<int>::iterator f(vector<int>::iterator beg, const vector<int>::iterator end, const int cint){
  vector<int>::iterator res;
  while(beg != end){
    if(*beg == cint)
      return beg;
    ++beg;
  }
    return beg;
}
int main(){
  int uint;
  vector<int>::iterator reite;
  vector<int> vinput = {1,2,3,4,5,6,7,8,9};
  cout << "type an integer between 1 and 9" << endl;
  if(cin >> uint){
    cout << "ok" << endl;
    reite = f(vinput.begin(), vinput.end(), uint);
    if(reite!=vinput.end())
      cout << "if " << uint << " exist within {1,2,3,4,5,6,7,8,9}? " <<  *reite << endl;
    else
      cerr << "the value " << uint << " is not found in {1,2,3,4,5,6,7,8,9}." << endl;
  }
}
