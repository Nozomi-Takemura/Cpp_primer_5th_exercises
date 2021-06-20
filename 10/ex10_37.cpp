#include<vector>
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main() {
  const vector<int> c_ivec{1,2,3,4,5,6,7,8,9,10};
  list<int> ilist;
  ostream_iterator<int> op_ite(cout, " ");
  copy(c_ivec.crbegin()+3, c_ivec.crend()-2, back_inserter(ilist));
  cout << "original input vec: ";
  copy(c_ivec.cbegin(), c_ivec.cend(), op_ite);
  cout << endl << "elements at position between 3 and 7 in reverse order: " << endl;
  copy(ilist.cbegin(), ilist.cend(), op_ite);
  cout << endl;
}
