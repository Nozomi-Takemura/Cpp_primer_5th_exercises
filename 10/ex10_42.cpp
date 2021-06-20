#include<string>
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void elimDumps(list<string> &words){
  ostream_iterator<string> op_ite(cout, " ");
  cout << "original input: ";
  copy(words.cbegin(), words.cend(), op_ite);
  cout << endl;
  words.sort();
  words.unique();
  cout << "after sort+unique: ";
  copy(words.cbegin(), words.cend(), op_ite);
  cout << endl;
}
int main(){
  istream_iterator<string> ip_ite(cin), end;
  list<string> words;
  copy(ip_ite, end, back_inserter(words));
  elimDumps(words);
}
