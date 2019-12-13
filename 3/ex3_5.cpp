#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;
int main() {
// task1

	string word1, concateword;
	while (cin >> word1) {
		concateword += word1;
	}
	cout << concateword << endl;
//	string word1, word2, concatedword;
//	cin >> word1 >> word2;
//	concatedword = word1+word2;
//	cout << concatedword << endl;

// task2
/*
	string word1, concateword;
	while (cin >> word1) {
		concateword = concateword + word1 + " ";
	}
	cout << concateword << endl;
*/	
}
