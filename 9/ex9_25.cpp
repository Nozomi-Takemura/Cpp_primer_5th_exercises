#include<iostream>
#include<list>
using namespace std;
int main(){
  list<int> slist = {0,1,2,3,4,5,6,7,8,9};
  cout << "original - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
  auto elem1 = slist.begin();
  auto elem2 = slist.begin();
  elem1 = slist.erase(elem1, elem2);
  cout << "when elem1==elem2(slist.begin()) - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
  elem1 = slist.begin();
  elem2 = slist.end();
  elem1 = slist.erase(elem1, elem2);
  cout << "when elem1==slist.begin(), elem2=slist.end() - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
  cout << endl;
  slist = {0,1,2,3,4,5,6,7,8,9};
  elem1 = slist.end();
  elem2 = slist.end();
  elem1 = slist.erase(elem1, elem2);
  cout << "when elem1==elem2=slist.end() - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
}
