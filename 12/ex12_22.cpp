#include<StrBlob.h>
#include<vector>
#include<string>
#include<iostream>
int main(){
  const StrBlob sb({"a","b","c"});
  ConstStrBlobPtr csbptr(sb);
  std::size_t sz = 0;
  while(sz!=sb.size()){
    std::cout << csbptr.deref() << " ";
    csbptr.incr();
    ++sz;
  }
  std::cout << std::endl;
}
