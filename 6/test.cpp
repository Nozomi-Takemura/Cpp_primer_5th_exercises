#include <iostream>
#include <vector>
using namespace std;
double calc(double db){ return db*db;}
int summatiom(vector<int>::iterator i1, vector<int>::iterator i2, int i){
  int summ=0;
  cout << "vec(10)={";
  for (auto ind = i1; ind!= i2; ++ind){
  cout << "ind-"<<(*ind) << ","<<"sum-"<<summ<<","<< "i-"<<i<<",";
    summ += i*(*ind);
  }
  cout << endl;
  return summ;
}
int main(){
  int i = 10;
  double db;
  db = i;
  std::cout << db << std::endl;
  std::cout << "2x2="<< calc(2) << ", 2.5x2.5=" << calc(2.5) <<std::endl; 
  vector<int> vec(10);
  std::cout << "sum of vec(10) * 3.8 = " << summatiom(vec.begin(), vec.end(), 3.8) << endl;
  }
