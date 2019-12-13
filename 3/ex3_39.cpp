#include <iostream>
#include <string>
//#include <vector>
//#include <iterator>
#include <cstring>
using std::cin; using std::cout; using std::endl; using std::string;
//using std::vector; using std::iterator; using std::begin; using std::end;
using std::strcmp;

void f(char str1[], char str2[]) {
	if (strcmp(str1, str2) == 0)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}
/*
void f(char *str1, char *str2) {
	if (strcmp(str1, str2) == 0)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}
*/
void g(string str1, string str2) {
	if (str1 == str2)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}
int main() {
	string str1 = "Takeo Kikuchi";
	string str2 = "Takeo Kikukikuchi";
	string str3 = "Takeo Kikuchi";
	
	char charstr1[] = "Takeo Kikuchi";
	char charstr2[] = "Takeo Kikukikuchi";
	char charstr4[] = {'T','a','k','e','o',' ', 'K','i','k','u','c','h','i','\0'};
	char charstr3[] = {'T','a','k','e','o',' ', 'K','i','k','u','c','h','i'};//"Takeo Kikuchi";
	char *cp3 = charstr3;
	char *cp4 = charstr4;
/*
	while(*cp4) {
		cout << *cp4 << " ";
		++cp4;
	}
	cout << endl;

	while(*cp3) {
		cout << *cp3 << " ";
		++cp3;
	}	
*/

	cout << "str1 = " << str1 << endl << "str2 = " << str2 << endl << "str3 = " << str3 << endl;
	cout << "A part to compare two strings: " << endl;	
	cout << "str1 vs str2 : " << endl;
	g(str1, str2);
	cout << "str1 vs str3 : " << endl;
	g(str1, str3);
	cout << "A part to compare two C-style char strings: " << endl;
	cout << "char[]1 vs char[]2 : " << endl;
	cout << strcmp(charstr1, charstr2) << endl;
	f(charstr1, charstr2);
	cout << "char[]1 vs char[]3 : " << endl;
	cout << strcmp(charstr1, charstr3) << endl;
	f(charstr1, charstr3);
	cout << "char[]1 vs char[]4 : " << endl;
	cout << strcmp(charstr1, charstr4) << endl;
	f(charstr1, charstr4);
	cout << "char[]3 vs char[]4 : " << endl;
	cout << strcmp(charstr3, charstr4) << endl;
	f(charstr3, charstr4);		
}
