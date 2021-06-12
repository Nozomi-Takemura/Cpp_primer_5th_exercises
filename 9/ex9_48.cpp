#include<iostream>
#include<string>
using namespace std;
int main(){
  string numbers("0123456789"), name("r2d2");
  string::size_type pos = numbers.find(name);
  string::size_type const_npos = string::npos;
  cout << "numbers: " << numbers << ", name: " << name << endl;
  cout << "numbers.find(name) returns " << pos << endl;
  cout << "if string::npos == numbers.find(name)? : " << ((const_npos == pos)? "true":"false") << endl; 
}
