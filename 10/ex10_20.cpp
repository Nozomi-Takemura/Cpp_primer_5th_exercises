#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<string> words{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle", "peanuts"};
  auto count = count_if(words.begin(), words.end(), [] (const string &word) 
      -> bool {return word.size()>6? true : false;});
  cout << "input words vector: " << endl;
  for (const auto & rcstr : words)
    cout << rcstr << " ";
  cout << endl;
  cout << count << (count>1? " words ": " word ") << "of length greater than " << 6 <<  endl;
}
