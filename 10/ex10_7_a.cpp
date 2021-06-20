#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
int main(){
  vector<int> vec; list<int> lst; int i;
  while (cin >> i)
       lst.push_back(i);
  // this will raise an error
  // copy(lst.cbegin(), lst.cend(), vec.begin());
  copy(lst.cbegin(), lst.cend(), back_inserter(vec));
  cout << "works" << endl;
}
