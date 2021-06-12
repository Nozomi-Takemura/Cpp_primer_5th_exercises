#include<iostream>
#include<vector>
#include<deque>
using namespace std;
ostream& vecprint(ostream& ros, const vector<int>& cvi){
  for(auto e : cvi)
    ros << e << " ";
  return ros;
}
int main(){
  vector<double> vint1 = {1.11,2.22,3.33}; //1st way - list initialization
  //vint1 contains three elemetns: 1,2,3
  
  // vector<int> vint2(vint1);
  //the above gives compilation error
  
  deque<int> vint3(vint1.begin(), vint1.end()); //3rd way - copy the container via iterator
  // the above line is valid because 
  // - there is no requirement that both container types need to be the same when iterators are used for initialization of the containe

  //print the each vector
  for (auto e : vint1)
    cout << e << " ";
  cout << "<-- vint1" << endl;
  for (auto e : vint3)
    cout << e << " ";
  cout << "<-- vint3" << endl;
}
