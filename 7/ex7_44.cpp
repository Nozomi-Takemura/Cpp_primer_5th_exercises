#include<vector>
#include <iostream>
using namespace std;
class NoDefault{
  public:
    NoDefault(int i) ;
};
struct C{
    //C() = default;
    C(int i = 0): cmember(i) { }
    //C(int i): cmember(i) { }
    NoDefault cmember;
};
int main(){
  std::vector<NoDefault> vec(10);
//  C c;
//  std::cout << c.cmember << std::endl;
}
