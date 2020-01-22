#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl;
using std::string;
using std::vector;
int main(){
  string s = "word";
  // auto p  = s[s.size()-1] == "s";
  //string pl 
  string  p  = s + (s[s.size() - 1] == 's' ? "" : "s" );
//  string ss="abcdefg";
//  string t =  ss + ss[ss.size() - 1];
//  cout << (t=='s') << endl;
//  string s = "word";
//  string pl = s + s[s.size() - 1] == "s" ? "" : "s" ;
  cout << p << endl;

}

