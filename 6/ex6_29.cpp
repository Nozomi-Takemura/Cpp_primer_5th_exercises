#include <iostream>
#include <initializer_list>
using namespace std;
int main(){
  std::initializer_list<int> ilint ={1,2,3,4,5};
  for (auto &i : ilint){
    std::cout << i << std::endl;
  }
  for (auto i : ilint)
    i = 50;
  for (auto i = ilint.begin(); i != ilint.end(); ++i){
    cout << *i << " ";
  }
  for (std::initializer_list<int>::const_iterator i = ilint.begin(); i != ilint.end(); ++i){
    cout << *i << "-";
  }
}
