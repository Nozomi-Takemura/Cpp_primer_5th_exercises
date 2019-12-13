#include <iostream>
#include <cstring>
using std::cout; using std::cin; using std::endl;// using std::cstring;
int main() {
	const char ca[] = {'h', 'e' ,'l', 'l', 'o'};
	cout << strlen(ca) << endl;
	const char *cp = ca;
	while (*cp)  {
//	for (; cp != ca + 10; ++cp)
	    cout << *cp << endl;
	    ++cp;
	}
}

/*
This program is for printing "hello". However, since this char array is not terminated with '\0', while loop is most likely to lasts infenitely. 
*/
