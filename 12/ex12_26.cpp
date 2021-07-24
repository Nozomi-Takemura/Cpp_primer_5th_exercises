#include<string>
#include<memory>
#include<iostream>
int main(){
  std::allocator<std::string> alloc;
  std::size_t sz = 10;
  std::string s;
  std::string *const p = alloc.allocate(sz);
  std::string * q = p;
  while(std::cin >> s && q!=p+sz){
    alloc.construct(q, s);
    std::cout << *q << " ";
  }
  std::cout << std::endl;
  while(q!=p)
    alloc.destroy(--q);
  alloc.deallocate(p, sz);
}
