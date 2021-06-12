#include<iostream>
#include<list>
#include<vector>
#include<iterator>
using namespace std;
  // template <class Container>
  // auto begin (Container& cont) -> decltype (cont.begin());
int main(){
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  vector<int> v;
  list<int> l;
  auto iter = std::begin(ia);
  cout << "ia[] = ";
  while(iter != end(ia)){
    cout << *iter << " ";
    v.push_back(*iter);
    l.push_back(*iter);
    ++iter;
  }
  cout << endl;
  for(auto i = v.begin(); i != v.end();){
    if(*i % 2 == 0)
      i = v.erase(i);
    else
      ++i;
  }
  for(auto i = l.begin(); i != l.end();){
    if(*i % 2 != 0)
      i = l.erase(i);
    else
      ++i;
  }
  cout << "list<int>: ";
  for(auto e : l)
    cout << e << " ";
  cout << endl;
  cout << "vector<int>: ";
  for(auto e : v)
    cout << e << " ";
  cout << endl;
} 
