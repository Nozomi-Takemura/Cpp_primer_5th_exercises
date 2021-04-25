#include <iostream>
using namespace std;
//int compare(const int& cint,int* cptr){
int compare(const int& cint,const int* cptr){
  if(cint > (*cptr)){
    return cint;}
  else {
    return (*cptr);}
}
int main(){
  const int* tmptr;
  int tmp;
  int tmp2;
  cout << "Type integer 1 for integer" << endl;
  cin >> tmp;
  const  int& cint = tmp;
  cout << "Type integer 2 that is the dereferenced int to which the pointer points" << endl;
  cin >> tmp2;
  tmptr = &tmp2;
//  const int* cptr = tmptr;
  cout << "*cptr" << (*tmptr) << endl;
  cout << "larger value is " << compare(cint, tmptr) << endl;
  //cout << "larger value is " << compare(cint, cptr) << endl;
}
