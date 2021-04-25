#include <iostream>
using namespace std;
void switchint(const int*& cptr1, const int*& cptr2){
  const int* tmpcptr;
  tmpcptr = cptr1;
  cptr1 = cptr2;
  cptr2 = tmpcptr;
}
int main(){
  int test1 = 10;
  int test2 = 3;
  const int* cptr1;
  const int* cptr2;
  cout << "original - test1 = 10 & test2 = 3" << endl;
  cptr1 = &test1;
  cptr2 = &test2;
  cout << "bef: *cptr1=test1 = " << *cptr1 << ", *cptr2=test2=" << *cptr2 << endl;
  cout << "bef: cptr1= " << cptr1 << ", cptr2=" << cptr2 << endl;
  switchint(cptr1, cptr2);
  cout << "aef: cptr1= " << cptr1 << ", cptr2=" << cptr2 << endl;
  cout << "aft: *cptr1=test1 = " << *cptr1 << ", *cptr2=test2=" << *cptr2 << endl;
  cout << " shouldn't be valid. It should be switched." << endl;
}
