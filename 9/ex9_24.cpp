#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> c = {};
  auto val = c.at(0);
  auto val2 = c[0];
  auto val3 = c.front();
  auto val4 = *c.begin();
  cout << "val: " << val << "val2:" << val2 << "val3:" << val3 << "val4" << val4 << "last" << endl;

  // if (!c.empty()) {
      // val and val2 are copies of the value of the first element in c
      // auto val = *c.begin(), val2 = c.front();
      // val3 and val4 are copies of the of the last element in c
      // auto last = c.end();
      // auto val3 = *(--last); // can't decrement forward_list iterators
      // auto val4 = c.back();  // not supported by forward_list
      // cout << "val: " << val << "val2:" << val2 << "val3:" << val3 << "val4" << val4 << "last" << endl;
  // }
}
