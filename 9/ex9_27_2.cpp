#include<iostream>
#include<forward_list>
using namespace std;
int main(){
  forward_list<int> fl;
  int input;
  forward_list<int>::iterator itercur;
  forward_list<int>::iterator iterpre;
  cout << "give the integers to pass to forward_list: ";
  iterpre = fl.before_begin();
  while(cin >> input)
    iterpre = fl.insert_after(iterpre, input);
  iterpre = fl.before_begin();
  itercur = fl.begin();
  while(itercur != fl.end()){
    if(*itercur % 2)
      itercur = fl.erase_after(iterpre);
    else{
      iterpre = itercur;
      ++itercur;
    }
  }
  cout << "after the 'erase_after': forward_list<int> = ";
  for(const auto e : fl)
    cout << e << " ";
  cout << endl;

}
