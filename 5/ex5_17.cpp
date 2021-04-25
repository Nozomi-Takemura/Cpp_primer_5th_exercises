#include <iostream>
#include <string>
#include <vector>
int main() {
  using namespace std;
  vector<int>  VecOne;
  vector<int>  VecTwo;
  int inp;
  auto beg_one = VecOne.begin();
  auto beg_two = VecTwo.begin();
  auto end_two = VecTwo.end();
  auto end_one = VecOne.end();
  bool result =  true;
  bool final_result = false;
  int sz_dif;
  // vector<int>::size_type sz;
  // read inputs
  cout << "Please type the first vector of integers" << endl;
  while (cin >> inp){
    VecOne.push_back(inp);
  }
  cout << "Please type the first vector of integers" << endl;
  cin.clear();
  while (cin >> inp){
    VecTwo.push_back(inp);
  }
  sz_dif = VecOne.size() - VecTwo.size();
//  if((VecOne.size() - VecTwo.size())>0){
  if (sz_dif > 0){
    while (beg_one != end_one){
        //auto it = beg_one, it_two = beg_two; it != end_one; it++){
      for (auto it_one = beg_one, it_two = beg_two; (it_two != end_two) or ((it_one + sz_dif) != end_one) ; it_two++, it_one++){
        if(*it_one != *it_two){
          result = false;
        }
      }
      ++beg_one;
      if (result == true)
        final_result = result;
    }
  }
  else {
    while (beg_two != end_two){
        //auto it = beg_one, it_two = beg_two; it != end_one; it++){
      for (auto it_one = beg_one, it_two = beg_two; (it_one != end_one) or ((it_two - sz_dif) != end_two); it_two++, it_one++){
        if(*it_one != *it_two){
          result = false;
        }
      }
      ++beg_two;
      if (result == true)
        final_result = result;
    }
  }
  if (final_result == true)
    cout << endl << "If one vector is a prefix of the other?: True" << endl;
  else
    cout << endl << "If one vector is a prefix of the other?: False" << endl;
}

