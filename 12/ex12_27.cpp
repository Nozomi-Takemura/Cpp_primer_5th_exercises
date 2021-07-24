#include<iostream>
#include<fstream>
using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::cin;
#include<TextQueryQueryResult.h>
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);  //  store the file and build the query map
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        QueryResult::print(cout, tq.query(s)) << endl;
    }
}
int main(int argc, char** argv){
  if(argc > 0){
    std::ifstream fin(argv[1], std::ifstream::in);
    runQueries(fin);
  }
  else{
    throw std::runtime_error("no input file was found.");
  }
}
