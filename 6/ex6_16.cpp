#include <iostream>
#include <string>
using namespace std;

bool is_empty_const(const string& s){ return s.empty();}
bool is_empty_original(string& s){ return s.empty();}

int main(){
/*  cout << "is_empty('AAA'): " << is_empty_const("AAA") << endl;
  cout << "is_empty('')" << is_empty_const("") << endl;
 */ cout << "is_empty_original('AAA'): " << is_empty_original("AAA") << endl;
  }
