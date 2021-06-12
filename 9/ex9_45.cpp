#include<string>
#include<iostream>
using namespace std;
string& f(string& name, const string& prefix, const string& suffix){
  name.insert(0," ");
  name.insert(name.begin(), prefix.begin(), prefix.end());
  name.append(" ");
  name.append(suffix.begin(), suffix.end());
  return name;
}
int main(){
  string name("Robert Downy");
  cout << "before function call - name: " << name << endl;
  name = f(name, "Mr.", "Jr.");
  cout << "after function call - name: " << name << endl;
}
