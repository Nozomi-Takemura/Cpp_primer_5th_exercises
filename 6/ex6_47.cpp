#include <iostream>
#include<vector>
#include <cassert>
void vecpri(std::vector<int> vec){
  #ifndef NDEBUG
  std::cout << "size of the vector at current recursion is " << vec.size();
  #endif
  if(vec.size() >=1){
    std::cout  << ", and the value = "<< *vec.begin() << std::endl;;
    vec.erase(vec.begin());
    vecpri(vec);
  }
  else
    std::cout << ", and the value = " << vec.size() << std::endl;
}
int main(){
  std::vector<int> vecinp = {1,2,3,4,5,6,7,8};
  std::cout << "bef function call, the vector = " << "{1,2,3,4,5,6,7,8}" << std::endl;
  vecpri(vecinp);
}

