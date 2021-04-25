#include <iostream>
using namespace std;
void swap(int* int1, int* int2){
  int tmp_int1;
  int tmp_int2;
  tmp_int1 = *int1;
  *int1 = *int2;
  *int2 = tmp_int1;
}
int main(){
  int int1;
  int int2;
  cout << "Type integer 1:" << endl;
  cin >> int1;
  cout << "Type integer 2:" <<endl;
  cin >> int2;
  cout << "after applyting the funciton:" << endl;
  swap(&int1, &int2);
  cout << "Integer 1: " << int1 << ", Integer 2: " << int2 << endl;
  }
