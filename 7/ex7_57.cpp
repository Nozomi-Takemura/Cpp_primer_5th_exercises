#include<string>
class Accout {
  public:
    static double rate() {return interestRate;}
    static void rate(double);
  private:
    static double interestRate;
    static constexpr int period = 30;
    double daily_tbl[period];
    std::string AccoutName;
    double Saving;

};
int main(){
}
