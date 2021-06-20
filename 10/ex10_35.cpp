#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main(){
  const vector<int> c_ivec{1,2,3,4,5,6,7,8,9,10};
  ostream_iterator<int> op_ite(cout, " ");
  cout << "original vector<int>: ";
  for(const auto i : c_ivec)
    cout << i << " ";
  cout << endl << "vector<int> in reverse order: ";
  for(auto i = c_ivec.end(); i!=c_ivec.begin();){
    --i;
    cout << *i << " ";
  }
  // copy(c_ivec.crbegin(), c_ivec.crend(), op_ite);
  cout << endl;
}
