#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
  const list<int> c_ilist{1,0,3,4,0,6,7,0,9,11};
  ostream_iterator<int> op_ite(cout, " ");
  cout << "original vector<int>: ";
  for(const auto i : c_ilist)
    cout << i << " ";
  cout << endl << "list<int> in reverse order: ";
  copy(c_ilist.crbegin(), c_ilist.crend(), op_ite);
  cout << endl;
  // find the last element with value 0
  auto rite_bef_last_zero = find(c_ilist.crbegin(), c_ilist.crend(), 0);
  if(rite_bef_last_zero != c_ilist.crend()){
    cout << "(distance(rite_bef_last_zero,c_ilist.crend())) - the last 0 is found at " << (distance(rite_bef_last_zero,c_ilist.crend()))  << "th element." <<  endl;
  }
}
