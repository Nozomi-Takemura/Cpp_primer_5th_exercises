#include <vector>
#include <string>
//#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
int main(const int argc, const char** argv){
  std::fstream in;//(*argv);
  std::ostringstream op;
  std::vector<std::string> vec;
  in.open(*(argv+1));
  std::cout << "will open " << std::string(*argv) << std::endl;
  std::string tmp;
  if (in){
    while(std::getline(in, tmp)){
      vec.push_back(tmp);
      std::cout << tmp << std::endl;
      op.str(tmp);
      op << "--stringstream--" << tmp << std::endl; 
      std::cout << op.str();
    }
  } else
    std::cerr << "could't open: " + std::string(*argv);
}
