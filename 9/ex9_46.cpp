#include<string>
#include<iostream>
using namespace std;
string& f(string& name, const string& prefix, const string& suffix){
  name.insert(0," ");
  name.insert(0, prefix,0, prefix.size());
  name.insert(name.size(), " ");
  name.insert(name.size(), suffix, 0, suffix.size());
  return name;
}
int main(){
  string name("Robert Downy");
  cout << "before function call - name: " << name << endl;
  name = f(name, "Mr.", "Jr.");
  cout << "after function call - name: " << name << endl;
}
