#include <iostream>
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
  C c;
//  std::cout << c.cmember << std::endl;
}
