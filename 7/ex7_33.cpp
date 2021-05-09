#include <iostream>
#include <string>
#include <vector>
class Screen{
  public:
    friend class Window_mgr;//::clear(ScreenIndex);
    typedef std::string::size_type pos;
    // constructor;
    Screen() = default;
    Screen(pos ht, pos wt): contents(ht*wt, ' ') {}
    Screen(pos ht, pos wd, char c): cursol(wd*h), h(ht), w(wd), contents(ht*wd,c) {}
    // member functions
    inline char get() const {
      return contents[cursol];}
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    Screen& set(pos r, pos col, char c);
    Screen& set(char c);
    Screen& display(std::ostream& io) {
      do_display(io);
      return *this;
    }
    const Screen& display(std::ostream& io) const {
      do_display(io);
      return *this;
    }
    void some_member() const;
    std::ostream& print(std::ostream& io){
      io << "h="<<(*this).h << ", contents=" << (*this).contents;
    }
    //ex7_33
    inline pos size() const;
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
//definitions for Window_mgr classes
class Window_mgr{
  public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex i){
      Screen& s = screens[i];
      s.contents = std::string(s.h*s.w, ' ');
    }
    // constructor
    // default
    Window_mgr() = default;
    Window_mgr(Screen& rsc) {
      (*this).screens.push_back(rsc);
    }
    // member functions
    Window_mgr& addscreen(Screen&); 
    Screen& popscreen(ScreenIndex);
    //const Screen& popscreen(ScreenIndex);
    //ex7_33
    ScreenIndex addScreen(const Screen&);
  private:
    std::vector<Screen> screens{Screen(1,0, '$')};
};
/*void Window_mgr::clear(ScreenIndex i){
  Screen& s = screens[i];
  s.contents = std::string(s.h*s.w, ' ');
}
*/
//until here
inline char Screen::get(pos r, pos c) const {
  pos row = r*(*this).w;
  return (*this).contents[row+c];}
inline
Screen& Screen::move(pos r, pos c){
  pos row = r*((*this).w);
  (*this).cursol = row + c;
  return *this;
}
inline
Screen& Screen::set(pos r, pos col, char c){
  (*this).contents[r*(*this).w+col] = c;
  return (*this);
}
inline
Screen& Screen::set(char c){
  (*this).contents[(*this).cursol] = c;
  return (*this);
}
inline
void Screen::some_member() const{
  ++access_ctr;
}
//ex7_33
inline
Screen::pos Screen::size() const{
  return (*this).w * (*this).h;
}
//member functions for Window_mgr
inline
Window_mgr& Window_mgr::addscreen(Screen& rsc){
  (*this).screens.push_back(rsc);
  return (*this);
}
inline
/*const Screen& Window_mgr::popscreen(ScreenIndex i){
  return  (*this).screens[i];
}*/
Screen& Window_mgr::popscreen(ScreenIndex i){
  return  (*this).screens[i];
}
//ex7_33
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s){
  screens.push_back(s);
  return screens.size() - 1;
}
//until here
int main(){
  Screen A = Screen();
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
  Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(std::cout);
  std::cout << "\n";
  myScreen.display(std::cout);
  std::cout << "\n";
  Window_mgr myWindow_mgr(B);
  myWindow_mgr.addscreen(C);
  myWindow_mgr.popscreen(0).display(std::cout);
  std::cout << " <-- 0" << "\n";
  myWindow_mgr.popscreen(1).display(std::cout);
  std::cout << " <-- 1" << "\n";
  myWindow_mgr.popscreen(2).display(std::cout);
  std::cout << " <-- 2" << "\n";
  //ex7_33
  Window_mgr::ScreenIndex si = myWindow_mgr.addScreen(Screen(2,2,'N'));
  myWindow_mgr.popscreen(si).display(std::cout);
  std::cout << " <-- ex7_33" << "\n";
  std::cout << "ex7_33 - size of Screen(3,2,'a'): " << B.size() << std::endl;  
}
