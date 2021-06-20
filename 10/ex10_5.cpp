#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<char*> roster1;
  vector<char*> roster2;
  int ifequal;
  char c[] = {'a', 'b'};
  char c2[] = {'a', 'b','c'};
  char c3[] = {'a', 'b','c'};
  roster1.push_back(c);
  roster2.push_back(c2);
  cout << roster1.at(0) << " vs " << roster2.at(0) << endl; 
  ifequal = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  cout << "c:{'a', 'b'}; and c2{'a', 'b','c'} equal?" << endl;
  cout << "ifequal: " << ifequal << endl;

  roster1.clear();
  roster2.clear();
  roster1.push_back(c3);
  roster2.push_back(c2);
  cout << "c3:" << roster1.at(0) << " vs " << "c2:" << roster2.at(0) << endl; 
  ifequal = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  cout << "c3{'a', 'b', 'c'}; and c2{'a', 'b','c'} equal?" << endl;
  cout << "ifequal: " << ifequal << endl;

  roster1.clear();
  roster2.clear();
  roster1.push_back(c2);
  roster2.push_back(c2);
  cout << "c2:" << roster1.at(0) << " vs " << "c2:" << roster2.at(0) << endl; 
  ifequal = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  cout << "c2{'a', 'b', 'c'}; and c2{'a', 'b','c'} equal?" << endl;
  cout << "ifequal: " << ifequal << endl;

}
