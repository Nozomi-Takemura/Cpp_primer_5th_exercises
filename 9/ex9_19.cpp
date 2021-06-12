#include<iostream>
#include<list>
using namespace std;
int main(){
  string input;
  list<string> deqstr;
  list<string>::iterator iter = deqstr.begin();
  while(cin >> input){
   iter = deqstr.insert(iter, input); 
  }
  iter = deqstr.begin();
  cout << "deque<string>: ";
  while(iter != deqstr.end()){
    cout << *iter << " ";
    ++iter;
  }
  cout << endl;
}
