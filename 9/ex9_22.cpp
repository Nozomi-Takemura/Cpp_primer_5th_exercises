#include<iostream>
#include<vector>
using namespace std;
int main() {
  vector<int> iv = {1,2,3,4,5,6,7,8};
  int some_val = 3;
  vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size()/2;
  cout << "iv: ";
  for (const auto e : iv)
    cout << e << " ";
  cout << endl;
  while (iter != mid){
      if (*iter == some_val){
          iv.insert(iter, 2 * some_val);
      }
      ++iter;
  }
  cout << "iv: -after operation- ";
  for (const auto e : iv)
    cout << e << " ";
  cout << endl;
}
