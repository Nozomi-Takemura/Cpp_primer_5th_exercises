#include<string>
#include<iostream>
using namespace std;
size_t find_first(const string& crs, const string::size_type pos, const string& searchfrom){
  return crs.find_first_of(searchfrom, pos);
}
size_t find_not_first(const string& crs, const string::size_type pos, const string& searchfrom){
  return crs.find_first_not_of(searchfrom, pos);
}
int main(){
//version 1
  const string inp("ab2c3d7R4E6");
  const string alph("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  const string nume("0123456789");
  string::size_type pos = 0;
  // find all index for alphabet
  cout << "target string: " << inp << endl;
  while((pos = find_first(inp, pos, alph))!= string::npos){
    cout << "alphabet was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
  pos = 0;
  while((pos = find_first(inp, pos, nume))!= string::npos){
    cout << "numeric was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
  cout << "########## case: find_not_of ##########" << endl;
  cout << "target string: " << inp << endl;
  pos = 0;
  while((pos = find_not_first(inp, pos, nume))!= string::npos){
    cout << "alphabet was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
  pos = 0;
  while((pos = find_not_first(inp, pos, alph))!= string::npos){
    cout << "numeric was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
}
