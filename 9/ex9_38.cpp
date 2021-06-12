#include<iostream>
#include<vector>
using namespace std;
ostream& vprint(ostream& ros, vector<int>& v){
  ros << "v.size(): " << v.size() << endl << "v.capacity: " << v.capacity() << endl;
  ros << "v.push_back(0);" << endl;
  v.push_back(0);
  ros << "v.size(): " << v.size() << endl << "v.capacity: " << v.capacity();
  return ros;
}
void addelement(vector<int>& crv){
  while(crv.size() != crv.capacity())
    crv.push_back(0);
}
int main(){
  vector<int> v;
  cout << "---v is empty---" << endl;
  vprint(cout, v) << endl;
  v.reserve(10);
  cout << "---v.researve(10);---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---first push_back cycle---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---second push_back cycle---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---3rd push_back cycle---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---4th push_back cycle---" << endl;
  vprint(cout, v) << endl;

}
