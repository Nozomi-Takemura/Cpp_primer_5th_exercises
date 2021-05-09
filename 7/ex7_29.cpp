#include <iostream>
#include <string>
class Screen{
  public:
    typedef std::string::size_type pos;
    // constructor;
    Screen() = default;
    Screen(pos ht, pos wt): contents(ht*wt, ' ') {}
    Screen(pos ht, pos wd, char c): cursol(wd*h), h(ht), w(wd), contents(ht*wd,c) {}
    // member functions
    inline char get() const {
      return contents[cursol];}
    inline char get(pos ht, pos wd) const;
    Screen move(pos r, pos c);
    Screen set(pos r, pos col, char c);
    Screen set(char c);
    Screen display(std::ostream& io) {
      do_display(io);
      return *this;
    }
    const Screen display(std::ostream& io) const {
      do_display(io);
      return *this;
    }
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
    void do_display(std::ostream& io) const {
      io << (*this).contents;  
    }
};
inline char Screen::get(pos r, pos c) const {
  pos row = r*(*this).w;
  return (*this).contents[row+c];}
inline
Screen Screen::move(pos r, pos c){
  pos row = r*((*this).w);
  (*this).cursol = row + c;
  return *this;
}
inline
Screen Screen::set(pos r, pos col, char c){
  (*this).contents[r*(*this).w+col] = c;
  return (*this);
}
inline
Screen Screen::set(char c){
  (*this).contents[(*this).cursol] = c;
  return (*this);
}
inline
void Screen::some_member() const{
  ++access_ctr;
}
int main(){
/*  Screen A = Screen();
  Screen B = Screen(3, 2, 'a');
  Screen C = Screen(3,2);
  A.print(std::cout) << std::endl;
  B.print(std::cout) << "<-- ex7_24, 3 arguments" << std::endl;
  C.print(std::cout) << "<-- ex7_24, 2 arguments" << std::endl;
  // move and set and display
  A.display(std::cout).set('*');
  A.display(std::cout).set('%');
  A.display(std::cout).set('&');
  std::cout << "Screen() - contents: " ;
  A.display(std::cout);
  std::cout << std::endl;
  std::cout << "Screen(3,2,'a') - contents: " ;
  B.display(std::cout);
  std::cout << std::endl;
  std::cout << "Screen(3,2) - contents: " ;
  C.display(std::cout);
  std::cout << std::endl;
 */ Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(std::cout);
  std::cout << "\n";
  myScreen.display(std::cout);
  std::cout << "\n";
}
