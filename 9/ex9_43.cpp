#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
void fandr(string& s, const string& oldVal, const string& newVal){
  size_t sz = s.find(oldVal,0);
  string::const_iterator beg = s.begin();
  // cout << oldVal << " is found at the location from " << sz << endl;
  auto erbeg = beg+sz;
  auto erend = erbeg+oldVal.size();
  auto inbeg = s.begin() + sz;
  s.erase(erbeg, erend);
  cout << "just after erase :" << s;
  s.insert(inbeg, newVal.begin(), newVal.end());
  // s.replace(sz, oldVal.size(), newVal);
}
ostream& sprint(ostream& ros, const string& s, const string& oldVal, const string& newVal){
  ros << "s: " << s << endl;
  ros << "oldVal: " << oldVal << endl;
  ros << "newVal: " << newVal << endl;
  return ros;
}
int main(){
  string s("Water comes thru the pipe, tho it hasn't rained for almost one year.");
  string oldVal = "thru";
  string newVal = "through";
  cout << "case1: " << endl;
  cout << "before erase+insert" << endl;
  sprint(cout, s, oldVal, newVal);
  fandr(s,oldVal,newVal);
  cout << "after erase+insert: " << endl;
  sprint(cout, s, oldVal, newVal);
  cout << "case2: " << endl;
  oldVal = "tho";
  newVal = "though";
  cout << "before erase+insert" << endl;
  sprint(cout, s, oldVal, newVal);
  fandr(s,oldVal,newVal);
  cout << "after erase+insert: " << endl;
  sprint(cout, s, oldVal, newVal);
}
