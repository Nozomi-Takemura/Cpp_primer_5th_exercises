#include<iostream>
#include<vector>
#include<forward_list>
using namespace std;
int main(){
  forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
  auto iter = vi.begin(); // call begin, not cbegin because we're changing
  decltype(iter) preiter = vi.before_begin();  
  while (iter != vi.end()) {
      if (*iter % 2) {
          // preiter = iter;
          // ++iter; // advance to the iterator before which insertion is done.
          iter = vi.insert_after(iter, *iter);  // duplicate the current
          preiter = iter;
          ++iter; // advance past this element and the one inserted before it
      } else
          iter = vi.erase_after(preiter);          // remove even elements
          // don't advance the iterator; iter denotes the element after the one we
  }
  cout << " after erase - vi: ";
  for (const auto e : vi){
    cout << e << " ";
  }
  cout << endl;
}

