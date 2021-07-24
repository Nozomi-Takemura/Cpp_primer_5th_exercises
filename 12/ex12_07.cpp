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
using std::shared_ptr;
using std::make_shared;
shared_ptr<vector<int>> create()//(shared_ptr<vector<int>> pt)
{
  return make_shared<vector<int>>(); 
}
istream& fill(shared_ptr<vector<int>> pt, istream& in)
{
  int i;
  while(in >> i)
  {
    pt->push_back(i);
  }
  return in;
}
ostream& print(shared_ptr<vector<int>> pt, ostream& op)
{
  // ostream_iterator<int>& op_ite(op, " ");
  // copy(pt->begin(), pt->end(), op_ite);
  for(const auto i : *pt)
    op << i << " ";
return op;
}
int main(){
  // vector<int>* pt = nullptr;
  auto pt = create();
  fill(pt, cin);
  print(pt, cout) << endl;
}
