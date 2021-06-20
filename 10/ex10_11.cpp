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
inline bool isShorter(const string& s1, const string& s2){
 return (s1.size() < s2.size());
}
void elimDump(vector<string> &words,bool ifstablesort){
  cout << "after read: ";
  svecprint(cout, words) << endl;
  if(ifstablesort == true){
    stable_sort(words.begin(), words.end(), isShorter);
    cout << "after stable_sort: ";
  }
  else{
    sort(words.begin(), words.end());
    cout << "after sort: ";
  }
  svecprint(cout, words) << endl;
  auto it = unique(words.begin(), words.end());
  cout << "after unique: ";
  svecprint(cout, words) << endl;
  words.erase(it, words.end());
  cout << "after erase: ";
  svecprint(cout, words) << endl;
}

int main(){
  vector<string> csvec1{"dog","cat", "bird", "monkey", "dog","pigeon", "chicken","cat", "dog"};
  vector<string> csvec{"the","quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  vector<string> csvec2{"the","quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  cout << "-----Firtst apply normal elimDump based on normal sort:-----" << endl;
  elimDump(csvec, false);
  cout << "-----Additionaly, apply the elimDump based on stable_sort:-----" << endl;
  elimDump(csvec, true);
  cout << endl; 
  cout << "-----other example  :-----" << endl;
  elimDump(csvec1, false);
  elimDump(csvec1, true);

}
