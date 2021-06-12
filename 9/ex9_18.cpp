#include<iostream>
#include<deque>
using namespace std;
int main(){
  string input;
  deque<string> deqstr;
  deque<string>::iterator iter = deqstr.begin();
  while(cin >> input){
   deqstr.push_back(input); 
  }
  cout << "deque<string>: ";
  while(iter != deqstr.end()){
    cout << *iter << " ";
    ++iter;
  }
  cout << endl;
}
