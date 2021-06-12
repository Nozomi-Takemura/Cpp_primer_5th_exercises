#include<iostream>
#include<vector>
#include<list>
using namespace std;
ostream& vecprint(ostream& ros, const vector<int>& cvi){
  for(auto e : cvi)
    ros << e << " ";
  return ros;
}
int main(){
  list<int> liin = {1,2,3};
  vector<int> vecin = {4,5,6,7};
  vector<double> v1 = {liin.begin(), liin.end()}; //1st way - list initialization
  vector<double> v2 = {vecin.begin(), vecin.end()}; //1st way - list initialization
  //vint1 contains three elemetns: 1,2,3
  
  //print the each vector
  for (auto e : v1)
    cout << e << " ";
  cout << "<-- v1" << endl;
  for (auto e : v2)
    cout << e << " ";
  cout << "<-- v2"<< endl;
}
