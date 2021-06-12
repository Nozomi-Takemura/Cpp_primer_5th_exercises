#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<char> chvec{'H', 'i', '!',',', 'r', 'e','a', 'd', 'e','r','.'};
  string s1(chvec.begin(),chvec.end());
  cout << "vector<char>: ";
  for (const auto e : s1)
    cout <<  e << " ";
  cout << endl;
  cout << "string(vector<char>.begin(), vector<char>.end(): ): ";
  for (const auto e : s1)
    cout <<  e << " ";
  cout << endl;
}
