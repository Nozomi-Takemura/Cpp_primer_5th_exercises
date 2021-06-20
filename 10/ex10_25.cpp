#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using std::placeholders::_1;
void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto IteToOnePastUniEnd = unique(words.begin(), words.end());
  words.erase(IteToOnePastUniEnd, words.end());
}
inline string make_plural(string::size_type sz, const string &word, const string &ending){
  return (sz > 1)? word+ending : word;
}
inline bool check_size(const string &s, string::size_type sz){
  return s.size() >= sz;
}
inline bool isShorter(const string &s1, const string &s2){
  return s1.size() < s2.size();
}
void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), isShorter);
  // for testing the effect of stable_partition, remove stable_sort
  // stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        // const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = find_if(words.begin(), words.end(),
      bind(check_size,_1,sz));
      
  cout << "## after bind(check_size,-1,sz) parts: ";
  for (const auto &rcs : words)
    cout << rcs << " ";
  cout << endl;
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
int main(){
  vector<string> svec{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle"};
  cout << "input words: " << endl;
  for (const auto e : svec)
    cout << e << " ";
  cout << endl;
  biggies(svec, 5);
}
