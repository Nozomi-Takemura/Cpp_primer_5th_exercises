#include <string>
#include <iostream>
using std::string;
using std::cin; using std::cout; using std::endl;
int main()
{
// task 1
/*
	string line1, line2;
//	getline(cin, line1);
//	getline(cin, line2);
	cin >> line1 >> line2;
	if ( line1 == line2) {
		cout << "Two strings are the same" << endl;
	}
	else {
		cout << "The strings are different." <<endl;
		if (line1 > line2) {
			cout << "Note, " << line1 << " is larger." << endl;
		}
		else {
			cout << "Note, " << line2 << " is larger." << endl;
		}
	}
*/
// task 2

	string line1, line2;
	cin >> line1 >> line2;
	if (line1.size() == line2.size())
		cout << "Two input strings are the same" << endl	;
	else {
		if (line1.size() > line2.size())
			cout << line1 << " is logner than " << line2 << endl;
		else {
			cout << line2 << " is longer than " << line1 << endl;
		}
	}
	

	
}
