#include<iostream>
#include<vector>
#include<algorithm>
int main(){
  std::vector<int> ivec;
  int i;
  std::cout << "type a series of integers: " << std::endl;
  while(std::cin >> i){
    ivec.push_back(i);
  }
  std::cout << "type the integer you want to count: " << std::endl;
  std::cin.clear();
  std::cin >> i;
  std::cout << "the integer " << i<< " appears " << count(ivec.begin(), ivec.end(), i) << " times." << std::endl;
}
