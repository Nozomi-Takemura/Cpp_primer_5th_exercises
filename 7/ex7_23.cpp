#include <iostream>
#include <string>
class Screen{
  public:
    typedef std::string::size_type pos;
    // constructor;
    Screen() = default;
    Screen(pos ht, pos wd, char c): cursol(wd*h), h(ht), w(wd), contents(ht*wd,c) {}
    // member functions
    inline char get() const {
      return contents[cursol];}
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    void some_member() const;
    std::ostream& print(std::ostream& io){
      io << "h="<<(*this).h << ", contents=" << (*this).contents;
    }
  private:
    pos cursol;
    pos h=0;
    pos w=0;
    std::string contents;
    mutable pos access_ctr;
};
inline char Screen::get(pos r, pos c) const {
  pos row = r*(*this).w;
  return (*this).contents[row+c];}
inline
Screen& Screen::move(pos r, pos c){
  pos row = r*((*this).w);
  (*this).cursol = row + c;
  return *this;
}
void Screen::some_member() const{
  ++access_ctr;
}
int main(){
  Screen A = Screen();
  Screen B = Screen(3, 2, 'a');
  A.print(std::cout) << std::endl;
  B.print(std::cout) << std::endl;

}
