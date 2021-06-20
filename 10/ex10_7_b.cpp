#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> vec;
  vec.reserve(10); 
  cout << "vec.reserve(10);" << endl;
  for (const auto i : vec)
    cout << i << " ";
  cout << "vec.resize(10);" << endl;
  vec.resize(10); 
  for (const auto i : vec)
    cout << i << " ";
  fill_n(vec.begin(), 10, 0);
  cout << endl << "works" << endl;
}
