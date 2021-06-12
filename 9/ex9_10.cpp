#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin();
vector<int>::iterator it1A;
auto it2 = v2.begin();
vector<int>::const_iterator it2A;
auto it3 = v1.cbegin();
vector<int>::const_iterator it3A;
auto it4 = v2.cbegin();
vector<int>::const_iterator it4A;
it1A = it1 +1;
cout << *it2 << endl;
it2A = it2;
it3A = it3;
it4A = it4;
}
