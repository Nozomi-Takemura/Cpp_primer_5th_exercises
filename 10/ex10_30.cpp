#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
 istream_iterator<int> is_iter(cin), end;
 ostream_iterator<int> os_iter(cout, " ");
 vector<int> ivec; 
 copy(is_iter, end, back_inserter(ivec));
 sort(ivec.begin(), ivec.end());
 copy(ivec.begin(), ivec.end(), os_iter);
 cout << endl;
}
