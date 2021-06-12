#include<iostream>
#include<vector>
using namespace std;
ostream& vecprint(ostream& ros, const vector<int>& cvi){
  for(auto e : cvi)
    ros << e << " ";
  return ros;
}
int main(){
   vector<int> vint1 = {1,2,3}; //1st way - list initialization
  //vint1 contains three elemetns: 1,2,3
   vector<int> vint2(vint1); //2nd way - copy from already existing ocntainer (type match)
  //vint2 contains the copy of the vint1; namely 1,2,3
  vector<int> vint3(vint1.begin(), vint1.end()); //3rd way - copy the container via iterator
  //vint3 contains the range specified [1st_iterator, 2nd_iterator); namely, 1,2,3

  //sequential container specific constructors
   vector<int> vint4(3,1); //4th way - size & element initializer
  //vint4 contains 1,1,1 
   vector<int> vint5(3); //5th way - value initialization
  //vint5 contains 0,0,0
   vector<int> vint6(vint1.begin(), vint1.begin()+1); //6th way - copy a subset of the container via iterator
  //vint6 contains 1
   vector<int> vint6_2; //another possibility for 6th way - default initilization
  //vint6_2 contains nothing

  //print the each vector
  const vector<vector<int>> vecvecint = {vint1, vint2, vint3, vint4, vint5, vint6, vint6_2};
  for (auto vecint : vecvecint){
    vecprint(cout, vecint) <<  endl;
  }
}
