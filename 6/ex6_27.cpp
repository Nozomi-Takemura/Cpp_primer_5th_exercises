#include <iostream>
#include <initializer_list>
int sum_initializer_list(std::initializer_list<int> il_int){
  int sum;
  for (auto i: il_int){
    sum += i;
  }
  return sum;
}
int main(){
  std::initializer_list<int> il_int_rea = {1,2,3,4,5,6,7,8,9};
  std::cout << "sum of {1,2,3,4,5,6,7,8,9} = "<< sum_initializer_list(il_int_rea) << std::endl;
  }
