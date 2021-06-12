#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
using namespace std;
int main(){
  vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
  auto iter = vi.begin(); // call begin, not cbegin because we're changing
  while (iter != vi.end()) {
      if (*iter % 2) {
          iter = vi.insert(iter, *iter++);  // duplicate the current
          // iter += 2; // advance past this element and the one inserted before it
          ++iter;
      } else
          iter = vi.erase(iter);          // remove even elements
          // don't advance the iterator; iter denotes the element after the one we
  }
  cout << " after erase - vi: ";
  for (const auto e : vi){
    cout << e << " ";
  }
  cout << endl;
}

