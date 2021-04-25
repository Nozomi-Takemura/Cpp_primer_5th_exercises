#include <iostream>
int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};
decltype(odd) &arrref(int i){
  return (i % 2)? odd: even;
}
int main(){
  std::cout << "input an integer" << std::endl;
  int inp;
  std::cin >> inp;
  for (auto i : arrref(inp))
    std::cout << i << " ";
  std::cout << std::endl;
}
