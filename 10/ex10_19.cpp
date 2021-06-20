#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto IteToOnePastUniEnd = unique(words.begin(), words.end());
  words.erase(IteToOnePastUniEnd, words.end());
}
inline string make_plural(string::size_type sz, const string &word, const string &ending){
  return (sz > 1)? word+ending : word;
}
void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = find_if(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() >= sz;});
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
void biggiesPartition(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  // for testing the effect of stable_partition, remove stable_sort
  // stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        // const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = partition(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() < sz;});
  cout << "## after partition algorithm ##: ";
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
void biggiesStablePartition(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  // for testing the effect of stable_partition, remove stable_sort
  // stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        // const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = stable_partition(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() < sz;});
  cout << "## after stable_partition algorithm ##: ";
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
  vector<string> svec2(svec);
  vector<string> svec3(svec);
  cout << "input words: " << endl;
  for (const auto e : svec)
    cout << e << " ";
  cout << endl;
  biggies(svec, 5);
  // use partition algorithm instead
  cout << "-- case: partition algorithm --" << endl;
  for (const auto e : svec2)
    cout << e << " ";
  cout << endl;
  biggiesPartition(svec2, 5);
  // use stable_partition algorithm instead
  cout << "-- case: partition algorithm --" << endl;
  for (const auto e : svec3)
    cout << e << " ";
  cout << endl;
  biggiesStablePartition(svec3, 5);
}
