#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
  vector<string> vec;
  auto iter = vec.begin();
  string word;
  while(cin >> word)
    iter = vec.insert(iter, word);
  cout << "vector<string>: ";
  for(const auto e : vec)
    cout << e << " ";
  cout << endl;
}

