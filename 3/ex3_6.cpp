#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
//	string input("Koreshika Muri.");
	string input;
	cin >> input;	
/*
	for (decltype(input.size()) index = 0; index != input.size(); index++) {
		input[index] = "X";
	}
	cout << input;
*/
	for (auto &C : input) {
//		C = "X"; // this is wrong bc " " implies the type char*
		C = 'X';
	}
	cout << input << endl;
/*
for (auto c : input) {
		c = "X";
	}
	cout << input;
*/


} 
