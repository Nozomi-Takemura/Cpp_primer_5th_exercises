#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl; using std::cin;
using std::string;
using std::vector;
int main(){
	int grade;
	cout << "Enter gade: ";
	cin >> grade;
	string finalgrade = (grade < 60) ? "fail" : ((grade > 90) ? "high pass" : ((grade <= 75) ? "lower pass" : "pass"));
	cout << "finalgrade: " << finalgrade << endl;
  // if-else
  if (grade < 60){
    finalgrade = "fail";
  }
  else if (grade <= 75){
    finalgrade = "low pass";
  }
  else if (grade <90){
    finalgrade = "pass pass";
  }
  else if (grade <=100){
    finalgrade = "high pass";
	cout << "finalgrade: " << finalgrade << endl;
  }
}
