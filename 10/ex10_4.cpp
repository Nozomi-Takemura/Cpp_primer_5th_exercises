#include<vector>
#include<iostream>
#include<numeric>
using std::vector;
using std::cin;
using std::cout;
using std::endl;//, std::accumulate;
int main(){
  vector<double> ivec;
  double i;
  cout << "type series of integers: " << endl;
  while(cin >> i)
    ivec.push_back(i);
  cout << "sum of the given integers 'accumulate(ivec.cbegin(), ivec.cend(), 0)' is " << accumulate(ivec.cbegin(), ivec.cend(), 0) << "." << endl;
  cout << "sum of the given integers 'accumulate(ivec.cbegin(), ivec.cend(), 0.0)' is " << accumulate(ivec.cbegin(), ivec.cend(), 0.0) << "." << endl;
}
