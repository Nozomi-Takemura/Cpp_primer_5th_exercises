#include<fstream>
#include<StrBlob.h>
#include<iostream>
#include<string>
#include<sstream>
int main(int argc, char** argv){
  if(argc < 2)
    throw std::runtime_error("input file is missing.");
  std::ifstream fin(argv[1], std::ifstream::in);
  std::string input;
  StrBlob sb;
  if(fin.is_open()){
    std::getline(fin, input);
    std::stringstream ss(input);
    while(ss >> input)
      sb.push_back(input);
  }
  StrBlobPtr sbp(sb);
  // while(std::cout << sbp.deref()){
  std::size_t sz=0;
  while(sz!=sb.size()){
    std::cout << sbp.deref() << " ";
    sbp.incr();
    ++sz;
  }
  std::cout << std::endl;
}
