#include <iostream>
#include <vector>
using namespace std;
int main(){
  vector<int> vecint1 = {1,2,3,4};
  vector<int> vecint2 = {5,6,7,8};
  cout << "vecint1 == vecint2: " << (vecint1 == vecint2) << endl;
  cout << "vecint1 != vecint2: " << (vecint1 != vecint2) << endl;
}
