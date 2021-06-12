#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int main(){
  string s;
  const clock_t begin_time = clock();
  time_t start, finish;
  time(&start);
  vector<char> cvec(10000, 'a');
  s.reserve(124);
  for(const auto c : cvec){
     s += c; 
  }
  time(&finish);
	cout << "Time required(via time/sec): " << difftime(finish, start) << " seconds" << endl;
  cout << "cpu execution time (via clock/msec): " << float(clock() - begin_time) << endl;
}
