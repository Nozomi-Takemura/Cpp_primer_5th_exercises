#include<memory>
#include<string>
#include<iostream>
int main(){
  std::cout << "type required array size" << std::endl;
  std::size_t sz;
  std::cin >> sz;
  std::unique_ptr<char[]> uptr(new char[sz]);
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  std::cout << "type input string" << std::endl;
  std::cin.get(uptr.get(),sz);
  // std::cin.get(cptr,10);
  for(std::size_t szt = 0; szt!=sz and uptr[szt]!='\0';++szt){
    std::cout << uptr[szt];
  }
  std::cout << std::endl << "this can contain memory leak" << std::endl;
  for(std::size_t szt = 0; uptr[szt]!='\0';++szt){
    std::cout << uptr[szt];
  }
  std::cout << std::endl;
}
