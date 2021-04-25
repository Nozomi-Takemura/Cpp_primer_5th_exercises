#include <iostream>
using namespace std;
void print(const int ia[], size_t size){
  for(size_t sz = 0; sz!= size; ++sz){
      cout << ia[sz] << " ";
    }
    cout << endl;
}
int main(){
  int i = 0,  j[2] = {0,1};
  cout << "for i, ";
//  print(&i);
  cout << "for j[2], ";
  print(j,end(j)-begin(j));
}
