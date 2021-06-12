#include<iostream>
#include<vector>
using namespace std;
void f_ori(vector<int>::iterator begin, vector<int>& v){
  while (begin != v.end()) {
      // do some processing
      ++begin;  // advance begin because we want to insert after this element
      begin = v.insert(begin, 42);  // insert the new value
      ++begin;  // advance begin past the element we just added
  }
}
void f_mod(vector<int>::iterator begin, vector<int>& v){
  while (begin != v.end()) {
      // do some processing
      ++begin;  // advance begin because we want to insert after this element
      v.insert(begin, 42);  // insert the new value
      ++begin;  // advance begin past the element we just added
  }
}
ostream& vprint(ostream& ros, vector<int>& crv){
  for(auto e : crv)
    ros << e << " ";
  return ros;
}
int main(){
  vector<int> v{0,1,2,3,4,5,6,7,8,9};
  vector<int> v2{0,1,2,3,4,5,6,7,8,9};
  auto begin = v.begin(); //end = v.end();
  auto begin2 = v2.begin();// end2 = v2.end();
  f_ori(begin, v);
  cout << "original inserting result: ";
  vprint(cout, v) << endl;;
  f_mod(begin2, v2);
  cout << "modified inserting result: ";
  vprint(cout, v2) << endl;
}
