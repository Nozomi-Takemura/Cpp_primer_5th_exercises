#include <iostream>
#include <vector>
using namespace std;
void vecprint(std::vector<int> vec){
  if (vec.size() >= 1){
    cout << *vec.begin() << " ";
    vec.erase(vec.begin());
    vecprint(vec);
  }
  else
    cout << endl;
}
void priminmin(const int i){
  cout << "f-" << i << " ";
}
int main(){
  std::vector<int> inpvec={1,2,3,4,5};
  cout << "input vector = {1,2,3,4,5}" << endl;
  vecprint(inpvec);
  for (auto i = 10; i!=0; --i){
    cout << i << " ";
    priminmin(--i);
  }
  cout << endl;
  for (auto i = 10; i!=0; --i){
    priminmin(i--);
  }
  cout << endl;
}
