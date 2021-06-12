#include<vector>
#include<list>
#include<deque>
#include<iostream>
int main(){
  std::list<std::deque<int>> listofdequeofint = {{1,2}};
  for(auto dequeofint : listofdequeofint){
    for(auto i : dequeofint)
      std::cout << "- " << i;
  }
  std::cout << std::endl;
}
