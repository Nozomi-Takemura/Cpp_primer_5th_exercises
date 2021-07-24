#include<new>
#include<memory>
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using std::cout; 
using std::cin;
using std::endl;
using std::vector;
using std::istream;
using std::ostream;
using std::endl;
vector<int>* create(vector<int>* pt)
{
 pt = new vector<int>();
 return pt;
}
istream& fill(vector<int>* pt, istream& in)
{
  int i;
  while(in >> i)
  {
    pt->push_back(i);
  }
  return in;
}
ostream& print(vector<int>* pt, ostream& op)
{
  // ostream_iterator<int>& op_ite(op, " ");
  // copy(pt->begin(), pt->end(), op_ite);
  for(const auto i : *pt)
    op << i << " ";
  delete pt;
  return op;
}
int main(){
  vector<int>* pt = nullptr;
  pt = create(pt);
  fill(pt, cin);
  print(pt, cout) << endl;
}
