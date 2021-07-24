#include<iostream>
#include<fstream>
#include<string>
#include<TextQuery_QueryResult_LAST.h>
using std::ifstream;
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);  //  store the file and build the query map
    while (true) {
      std::cout << "enter word to look for, or q to quit: ";
      std::string s;
      if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}
int main(int argc, char** argv){
  if(argc < 1)
    throw std::runtime_error("no input file.");
  std::ifstream fin(argv[1], std::ifstream::in);
  runQueries(fin);
}
