#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
ifstream& fread(ifstream& ifs, vector<string>& rvec, const string fname){
  ifs.open(fname);
  std::cout << "will open " << fname << std::endl;
  std::string tmp;
  if (ifs.is_open()){
    while(std::getline(ifs, tmp)){
      rvec.push_back(tmp);
    }
  } else
    std::cerr << "could't open: " + fname;
  return ifs;
}

ostringstream& vecprint(ostringstream& oss, const vector<string>& rcvec){
  for(auto line : rcvec){
    cout << "--ostream-- " << line << ", ";
    oss.str(line);
    oss << "--ostringstream-- " << line;
    cout << oss.str() << endl;
  }
  return oss;
}

int main(const int argc, const char** argv){
  const string fname = *(argv+1); // take a file name, argv[0] is the script name
  std::vector<std::string> vec;
  std::ifstream in;
  std::ostringstream op;
  if(fread(in, vec, fname).eof())
    vecprint(op, vec);
  else
    std::cerr << "could't open: " + fname;
}
