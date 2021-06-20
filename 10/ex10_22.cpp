#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using std::placeholders::_1;
inline bool ifstrlen(const string &rcs, const string::size_type sz){
  return rcs.size() <= sz;
}
int main(){
  vector<string> words{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle", "peanuts"};
  auto count = count_if(words.begin(), words.end(), bind(ifstrlen, _1, 6));
  cout << "input words vector: " << endl;
  for (const auto & rcstr : words)
    cout << rcstr << " ";
  cout << endl;
  cout << count << (count>1? " words ": " word ") << "of length equal to or less than " << 6 <<  endl;
}
