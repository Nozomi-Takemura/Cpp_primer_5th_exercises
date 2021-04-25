#include <iostream>
#include <string>
using namespace std;
// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word,
                               const string &ending="s")
{
    return (ctr > 1) ? word + ending : word;
}
int main(int argc, char** ptrarrcha){
  for (auto i = 0; i != argc; ++i){
    char * inp = ptrarrcha[i];
    size_t sz=0;
    for(auto ptrc = inp; *ptrc != '\0'; ++ptrc){
      ++sz;
    }
  cout << make_plural(sz, inp) << endl;
  }
}
