#include<deque>
#include<list>
#include<iostream>
using namespace std;
int main(){
  deque<int> odd;
  deque<int> even;
  list<int> input;
  int i;
  div_t divresult;
  list<int>::const_iterator cite;// = input.begin();
  cout << "type a bunch of integers" << endl;
  while(cin >> i){
    input.push_back(i);
  }
  cite = input.begin();
  while(cite != input.end()){
    divresult = div(*cite, 2);
    // cout << divresult.rem << " ";
    if(divresult.rem == 0)
      even.push_back(*cite);
    else
      odd.push_back(*cite);
    ++cite; 
  }
  cout << "odd - list: ";
  for(auto e : odd)
    cout << e << " ";
  cout << endl;

  cout << "even - list: ";
  for(auto e : even)
    cout << e << " ";
  cout << endl;

}
