#include <iostream>
#include <string>
using namespace std;
int main(){
  int intone;
  int inttwo;
  cout << "please type tow integers: " << endl;
  cin >> intone >> inttwo;
  if (inttwo == 0)
    throw runtime_error("the denominator for devision must not be zero.");
  cout << "input1 divided by input2 is " << intone/inttwo << endl;
}
