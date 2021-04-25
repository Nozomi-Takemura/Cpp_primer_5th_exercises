#include <iostream>
#include <string>
using namespace std;
int main() {
  string str1;
  string str2;
  do {
    cout << "Please type two strings:" << endl;
    cin >> str1 >> str2;
    if(str1.size() > str2.size()){
      cout << "String " << str1 << " is longer than " << str2 << endl;
    }
    else if (str1.size() == str2.size()){
      cout << "String " << str1 << " is same to " << str2 << endl;
    }
    else {
      cout << "String " << str2 << " is loger than " << str1 << endl;
    }
  } while (cin >> str1 >> str2);
}
