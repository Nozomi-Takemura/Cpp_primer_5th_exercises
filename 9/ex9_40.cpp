#include<iostream>
#include<vector>
#include<string>
using namespace std;
void vadd(vector<string>& svec, const int ni){
  for(auto i = 0; i != ni; i++){
    svec.push_back("a");
  }
}
int main(){
  vector<string> svec;
  svec.reserve(1024);
  const vector<int> cv{256, 512, 1000, 1048};
  // string word;
  // while (cin >> word)
          // svec.push_back(word);
  for (const auto e : cv){
    cout << e << " number of words are added." << endl;
    vadd(svec, e);
    cout << "svec.size() - before resize: " << svec.size() << endl;
    svec.resize(svec.size()+svec.size()/2);
    cout << "svec.size() - after resize: " << svec.size() << endl;
    cout << "svec.capacity(): " << svec.capacity() << endl;
    svec.clear();
    svec.reserve(1024);
  }

}
