#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
  cout << "original sequence: ";
  for(const int i : ivec){
    cout << i << " ";
  }
  cout << endl;
  cout << "after fill_n - sequence: ";
  fill_n(ivec.begin(), ivec.size(), 0);
  for(const int i : ivec){
    cout << i << " ";
  }
  cout << endl;
}
