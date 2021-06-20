#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
ostream& svecprint(ostream& ros, const vector<string> &words ){
  for (const auto e : words){
    ros << e << " ";
  }
  return ros;
}
void elimDump(vector<string> &words){
  cout << "after read: ";
  svecprint(cout, words) << endl;
  sort(words.begin(), words.end());
  cout << "after sort: ";
  svecprint(cout, words) << endl;
  auto it = unique(words.begin(), words.end());
  cout << "after unique: ";
  svecprint(cout, words) << endl;
  words.erase(it, words.end());
  cout << "after erase: ";
  svecprint(cout, words) << endl;
}

int main(){
  vector<string> csvec{"dog","cat", "bird", "monkey", "dog","pigeon", "ticken","cat", "dog"};
  elimDump(csvec);
}
