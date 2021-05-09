class Debug{
  public:
    constexpr Debug(bool b = true) hw(b), is(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) hw(h), is(i), other(o) {}
    constexpr bool any() {return hw || is || other;}
    void set_is(bool b){ is = b;}
    void set_hw(bool b){ hw = b;}
    void set_other(bool b){other = b;}
  private:  
    bool is;
    bool hw;
    bool other;
};
