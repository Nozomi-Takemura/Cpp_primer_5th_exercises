#include<iostream>
#include<list>
#include<string>
#include<vector>
using namespace std;
int main(){
  char Cstr1[]{"string1"};
  char Cstr2[]{"string2"};
  list<char*> liptr2cha = {Cstr1,Cstr2};

//container type and element type are different so normal assignement cannot be used.`
  vector<string> vecstr(1);
  vecstr.assign(liptr2cha.begin(), liptr2cha.end());

  for (auto e : liptr2cha)
    cout << e << " ";
  cout << "<-- lipt2cha" << endl;
  for (auto e : vecstr)
    cout << e << " ";
  cout << "<-- vecstr" << endl;
  
}
