#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
  vector<string> svec;
  string input;
  float sum = 0;
  cout << "Type multiple floating-point values to be summed up.(with space) " << endl;
  while(cin >> input)
    svec.push_back(input);
  for (const auto e : svec){
    sum += stod(e, nullptr);
  }
  cout << "Sum of the integers: " << sum << endl;
}

