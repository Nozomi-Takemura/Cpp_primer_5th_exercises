#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

int main ()
{
	string input;
	cin >> input;
// task1
/*
	decltype(input.size()) index = 0;
	while(index < input.size()) {
		char &C = input[index];
		C = 'X';
		index++;
	}
	cout << input << endl;
*/
// task2

	for(decltype(input.size()) index = 0; index != input.size(); index++) 	{
		auto &C = input[index];
		C = 'X';
		cout << "C=" << C << " : inputp=" << input[index] << endl;
	}
	cout << input << endl;
}

/* I prefer the program used in ex3_6, for it is very simple, and ther is little chances to cause bugs compared to the other two. */
