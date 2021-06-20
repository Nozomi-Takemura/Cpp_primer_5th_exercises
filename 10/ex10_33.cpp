#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;
int main(int argc, char** argv){
  ifstream fin(argv[1], ifstream::in);
  ofstream fop_odd(argv[2], ofstream::out);
  ofstream fop_even(argv[3], ofstream::out);
  istream_iterator<int> in_ite(fin), end;
  ostream_iterator<int> op_ite_odd(fop_odd, "\n");
  ostream_iterator<int> op_ite_even(fop_even, "\n");
  for(auto iter = in_ite; iter!= end; ++iter){
    (*iter%2)? *op_ite_odd++ = *iter : *op_ite_even++ = *iter; 
  }
  // copy_if(in_ite, end, op_ite_odd, [] (const int i) -> bool {return i%2;});
  // copy_if(in_ite, end, op_ite_even, [] (const int i) -> bool {return !(i%2);});
}
