#include <iostream>
using namespace std;
void print(const int (&ia)[2]){
  for(auto ele : ia)
      cout << ele << " ";
    cout << endl;
}
int main(){
  int i = 0,  j[2] = {0,1};
  cout << "for i, ";
//  print(&i);
  cout << "for j[2], ";
  print(j);
}
