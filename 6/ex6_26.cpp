#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
  cout << "supplied arguments are: "<< endl;
  char* tmp;
  for (int ind = 0; ind != argc; ++ind){
    tmp = argv[ind];
    while(*tmp!='\0'){
      cout << *tmp;
      tmp += 1;
    }
    cout << " ";
  }
  cout << endl;
}
