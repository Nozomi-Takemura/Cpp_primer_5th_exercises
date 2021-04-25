# include<iostream>
# include<string>
using std::string; 
using std::cout;
using std::endl;
int main() {
//while (string::iterator iter != s.end()) { /* . . . */ }
string s = "nozomi";
string::iterator iter = s.begin();
while (iter != s.end()) {
	cout << *iter << endl;
	++ iter; 
	}
}
