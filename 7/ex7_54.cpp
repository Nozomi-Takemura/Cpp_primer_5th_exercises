class Debug{
  public:
    constexpr Debug(bool b = true): is(b), hw(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o):is(h), hw(i), other(o) {}
    constexpr bool any() {return hw || is || other;}
    constexpr void set_is(bool b){ is = b;}
    void set_hw(bool b){ hw = b;}
    void set_other(bool b){other = b;}
  private:  
    bool is;
    bool hw;
    bool other;
};
int main() {
}
