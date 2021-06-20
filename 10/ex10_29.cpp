#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<string>
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ostream_iterator;
using std::istream_iterator;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
// using namespace std;

int main(int argc, char** argv){
  // vector<string> svec;
  if(argc>1){
    ifstream fin (argv[1], ifstream::in);
    ostream_iterator<string> out(cout, " ");
    istream_iterator<string> initer(fin), end;
    vector<string> svec(initer, end);
    // copy(initer, end, back_inserter(svec));
    for (const auto &rcstr : svec)
      *out++ = rcstr;
    cout << endl;
  }else{
    cerr << "there are no input file." << endl;
  }

} 
