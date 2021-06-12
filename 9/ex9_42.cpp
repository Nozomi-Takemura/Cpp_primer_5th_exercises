#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int main(int argc, char** argv){
  string s;
  const clock_t begin_time = clock();
  time_t start, finish;
  time(&start);
  for (auto i = 1; i != argc; i++){
    // s += **(argv+i);
    s = **(argv+i);
  }
  time(&finish);
	cout << "Time required(via time) = " << difftime(finish, start) << " seconds" << endl;
  cout << "cpu execution time (via clock): " << float(clock() - begin_time) << endl;
  cout << "length of input" << argc << endl;
  cout << "string: " << s << endl;
}
