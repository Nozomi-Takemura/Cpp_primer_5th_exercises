#include <iostream>
using std::cout; using std::endl;

int main(){
  char a;
  bool bol{true};
  int d=0;
  short c;
  long i;
  long long j;
  wchar_t k;
  double b;
  float l;
  long double m;
  int *ptr;
  bool *ptrbol;
  long double *ptrld;
  cout << "char: " << sizeof(a) << endl;
  cout << "bool" << sizeof(bol) << endl;
  cout << "int: " << sizeof(d) << endl;
  cout << "short: " << sizeof(c) << endl;
cout << "long : " << sizeof(i) << endl;
  cout << "longo long: " << sizeof(j) << endl;
  cout << "wchar_t: " << sizeof(k) << endl;
  cout << "double: " << sizeof(b) << endl;
  cout << "float: " << sizeof(l) << endl;
  cout << "long double: " << sizeof(m) << endl;
  cout << "ptrtoint:" << sizeof(ptr) << endl;
  cout << "ptrtobool: " << sizeof(ptrbol) << endl;
  cout << "ptrld: " << sizeof(ptrld) << endl;
   }
