#include<iostream>
#include<forward_list>
#include<string>
#include<algorithm>
using namespace std;
void f(forward_list<string>& fls, const string& cstre, const string& cstri){
  // auto fls_preite = fls.begin_before();
  // auto fls_curite = fls.begin();
  // auto result = find(fls.begin(), fls.end(), cstre);
  forward_list<string>::const_iterator locins;
  bool doneins = false;
  for(auto fls_curite = fls.begin(); fls_curite != fls.end(); fls_curite++){
    locins = fls_curite;
    // cout << "inside loop-" << *fls_curite;
    if(cstre.compare(*fls_curite)==0){
      fls_curite = fls.insert_after(fls_curite, cstri);
      doneins = true;
    }
  }
  if(!doneins){
      // if((++fls_curite) == fls.end())
        fls.insert_after(locins, cstri);
  }
  // if(result == fls.end()){
    // fls.insert_after(fls.end, cstri);
  // :w
  // }
  // else {
    // fls.insert_after()
  // }
  // while(fls_curite != fls.end()){
    // find()
  // }
}
ostream& flsprint(ostream& ros, const forward_list<string>& crfls){
  for(const auto e : crfls)
    ros << e << " ";
  return ros;
}
int main(){
  forward_list<string> fls;
  auto preiter = fls.before_begin();
  string strinp;
  string strinpser;
  string strinpins;
  cout << "type forward_list<string>: ";
  while(cin >> strinp)
    preiter = fls.insert_after(preiter, strinp);
  cin.clear();
  cout << endl << "type a string to be searched: ";
  cin >> strinpser;
  cin.clear();
  cout << endl << "type a string to be inserted: ";
  cin >> strinpins;
  f(fls, strinpser, strinpins);
  cout << endl << "after the insert-funciton, forward_list: ";
  flsprint(cout, fls) << endl;
}
