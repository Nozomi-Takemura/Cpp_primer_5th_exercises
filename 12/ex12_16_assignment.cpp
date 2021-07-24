#include<iostream>
#include<memory>
#include<string>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::string;
int main(){
  unique_ptr<string> uptr(new string("unique_ptr"));
  unique_ptr<string> uptr2;
  uptr2 = uptr;
}
