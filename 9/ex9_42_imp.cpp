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
  s.reserve(10000);
  // first request required memory size;
  vector<char> cvec(10000, 'a');
  s.reserve(124);
  for(const auto c : cvec){
     s += c; 
  }
  time(&finish);
	cout << "Time required(via time/sec) with string.reserve(10000): " << difftime(finish, start) << " seconds" << endl;
  cout << "cpu execution time (via clock/msec) string.reserve(10000): " << float(clock() - begin_time) << endl;
}
