#include <string>
using std::string;
int main() {
  int i;  double d;  const string *ps;  char *pc;  void *pv;
//  const string *ps;
//  void *pv;
  // (a)	
  //pv = (void*)ps; <-- wrong
  pv = static_cast<void*>(const_cast<string*>(ps));

  //(b)
  //i = reinterpret_cast<int>(reinterpret_cast<int*>(pc));
  i = *reinterpret_cast<int*>(pc);


  //(c)
  pv = static_cast<void*>(&d);

  //(d)
  pc = static_cast<char*>(pv);
}
