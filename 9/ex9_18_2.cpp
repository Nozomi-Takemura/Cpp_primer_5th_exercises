#include<iostream>
#include<deque>
using namespace std;
int main(){
  string input;
  deque<string> deqstr;
  // deque<string>::const_reverse_iterator criter;
  deque<string>::const_iterator citer;
  while(cin >> input){
   deqstr.push_back(input); 
  }
  citer = deqstr.begin();
  cout << "deque<string>: ";
  while(citer != deqstr.end()){
    cout << *citer << " ";
    ++citer;
  }
  cout << endl;
}
