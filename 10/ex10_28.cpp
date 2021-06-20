#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
template<typename T>
ostream& vprint(const T civec, ostream &ros){
  for (const auto ci : civec)
    ros << ci << " ";
  return ros;
}
int main(){
  const vector<int> civec{1,2,3,4,5,6,7,8,9};  
  vector<int> ivec{10,20,30};
  vector<int> ivec2{10,20,30};
  list<int> ivec3{10,20,30};
  vector<int>::iterator iter = ivec2.begin() + 1;
  cout << "original input vector<int>: ";
  vprint(civec,cout) << endl;
  cout << "original target vector<int>: ";
  vprint(ivec,cout) << endl;
  cout << "back_inserter: " << endl; 
  copy(civec.cbegin(), civec.cend(), back_inserter(ivec));
  cout << "target vector<int> -back_inserter - " << endl;
  vprint(ivec,cout) << endl;
  cout << "front_inserter: " << endl; 
  copy(civec.cbegin(), civec.cend(), front_inserter(ivec3));
  cout << "target vector<int> -front_inserter - " << endl;
  vprint(ivec3,cout) << endl;
  cout << "inserter(): " << endl; 
  copy(civec.cbegin(), civec.cend(), inserter(ivec2,iter));
  cout << "target vector<int> -inserter() - " << endl;
  vprint(ivec2,cout) << endl;
}
