#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

int main() {
	const string s = "Keep out!";
	for (auto &c : s) { /* ...  */ } // auto --> const char &
}

// This is leagal. The type of C is const char &
