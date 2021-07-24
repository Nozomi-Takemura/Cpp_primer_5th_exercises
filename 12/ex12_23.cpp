#include<memory>
#include<iostream>
#include<string>
int main(){
  const char* cptr = "abcde""fghij";
  std::unique_ptr<char[]> uptr(new char[10]);
  // for (auto ptr = uptr, char* ptr2 = cptr; (ptr != uptr+10) and (
        // ptr2 != cptr+10); ++ptr,++ptr2){
  const char* ptr = cptr;
  for (std::size_t i = 0; i!=10; ++i){
    uptr[i] = *ptr++;
  }
  for (std::size_t i = 0; i!=10; ++i){
    std::cout << uptr[i] << " ";
  }
  std::cout << std::endl;
  uptr.reset();
  
  // string
  std::string s1("abcde");
  std::string s2("fghij");
  s1.append(s2);
  std::cout << s1 << std::endl;
}
