#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
  vector<string> svec;
  string input;
  int sum = 0;
  cout << "Type multiple integers to be summed up.(with space) " << endl;
  while(cin >> input)
    svec.push_back(input);
  for (const auto e : svec){
    sum += stoi(e, nullptr);
  }
  cout << "Sum of the integers: " << sum << endl;
}

