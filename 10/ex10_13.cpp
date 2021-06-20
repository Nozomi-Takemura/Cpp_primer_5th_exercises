#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline bool ifmorethanfive(const string& s1){
  return s1.size() >= 5;
}
int main(){
 vector<string> svec{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle"};
 vector<string>::iterator iter =  partition(svec.begin(), svec.end(), ifmorethanfive);
 cout << "original vector of words after partition: ";
 for (const auto e : svec){
  cout << e << " ";
 }
 cout << endl;
 cout << "the elements that have file or more chars: " << endl;
 for(decltype(iter) it = svec.begin(); it != iter; it++){
  cout << *it << " ";
 }
 cout << endl;
}
