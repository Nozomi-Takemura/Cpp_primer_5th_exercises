#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz){
  return s.size() >= sz;
}
int main(){
  const vector<int> civec{2,4,6,8,10,12};
  const string cs("Inputstr");  
  auto itefirele = find_if_not(civec.begin(), civec.end(), bind(check_size, cs, _1));
  cout << "input vector<int>: ";
  for (const auto ci : civec)
    cout << ci << " ";
  cout << endl << "input string: " << cs << endl;
  cout << "the first element in a vector of ints that has a value greater than the length of a specified string value: " << *itefirele << endl;
}
