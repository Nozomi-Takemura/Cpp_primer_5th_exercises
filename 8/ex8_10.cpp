#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
std::istream& f(std::istream& is){
  std::string inp;
  while(!is.eof()){
    is >> inp;
    std::cout << inp << " ";
  }
  is.clear();
  return is;
}
void line2vec(std::istream &cin, std::vector<std::string> &vec){
  std::string line;
//  while(!cin.eof()){
   while(std::getline(cin, line)){
    vec.push_back(line);
  }
}
int main(int argc, char** argv){
  //f(std::cin);
  std::ifstream inputf(argv[1]);
  std::vector<std::string> output;
  line2vec(inputf, output);
//  for(decltype(output.begin()) ite = output.begin(); ite != output.end(); ++ite){
  for(auto ite : output){
  //  std::cout << *ite << std::endl;
  //  std::stringstream record(*ite);
    std::stringstream record(ite);
    f(record);
    std::cout << "Done" <<  std::endl;
  }
/*  while (std::getline(std::cin, line))
  {
    std::stringstream record(line);
    f(record);
  }
  */
}
