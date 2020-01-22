#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector; using std::iterator;

void f(vector<int> ivec){
  for(auto &integer : ivec)
    cout << integer << " ";
  cout << endl;
}

int main (){

  for (int i=0; i!=3;i++)
    cout << i << " " ;
  cout << endl;
  for (int j = 0; j !=3; ++j)
    cout << j << " ";
  cout << endl;
  
  // using prefix
  vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
  f(ivec);
  vector<int>::size_type ix = 0, cnt = ivec.size();
  while(ix != ivec.size()){
      --cnt;
      ivec[ix] = cnt;
      ++ix;
  }
  f(ivec);

  // using postfixi
  ivec = {0,1,2,3,4,5,6,7,8,9};
  f(ivec);
  ix  = 0; cnt = ivec.size();
  while(ix != ivec.size()){
    cnt--;
    ivec[ix] = cnt;
    ix++;
  }
  f(ivec);

  ivec = {0,1,2,3,4,5,6,7,8,9};
  cnt = ivec.size();
  // assign values from size... 1 to the elements in ivec
  for(vector<int>::size_type ix = 0;
                  ix != ivec.size(); ++ix, --cnt)
      ivec[ix] = cnt;
  f(ivec);

  ivec = {0,1,2,3,4,5,6,7,8,9};
  cnt = ivec.size();
  // assign values from size... 1 to the elements in ivec
  for(vector<int>::size_type ix = 0;
                  ix != ivec.size(); ix++, cnt--)
      ivec[ix] = cnt;
  f(ivec);
}
// these result in the same result because for loops shown above can be rewritten with while as:
// int i=0; // j=0
// while(i!=10){ // j!=10
  // cout << i << endl;// cout << j << endl;
  // i++; // ++j
// }
// in both senarios, new loop begins with the incremented i/j.
/*
0 1 2 
0 1 2 
0 1 2 3 4 5 6 7 8 9 
9 8 7 6 5 4 3 2 1 0 
0 1 2 3 4 5 6 7 8 9 
9 8 7 6 5 4 3 2 1 0 
10 9 8 7 6 5 4 3 2 1 
10 9 8 7 6 5 4 3 2 1 
*/
