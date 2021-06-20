#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  const vector<int> civec{1,2,3,4,5,6,7,8,9,2,2,3,3,4,4};  
  vector<int> ivec{1,2,3,4,5,6,7,8,9,2,2,3,3,4,4};  
  vector<int> ivec2;
  vector<int> ivec3;
  unique_copy(civec.cbegin(), civec.cend(), back_inserter(ivec2));
  cout << "original input vector<int>: ";
  for(const auto ci : civec)
    cout << ci << " ";
  cout << endl;
  cout << "only unique_copy - copied vector: ";
  for(const auto ci : ivec2)
    cout << ci << " ";
  cout << endl;
  sort(ivec.begin(), ivec.end());
  unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ivec3));
  cout << "sort + unique_copy - copied vector: ";
  for(const auto ci : ivec3)
    cout << ci << " ";
  cout << endl;
}
