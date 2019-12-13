#include <iostream>
#include <string>
#include <cstring>
#include <iterator>
using std::cin; using std::cout; using std::endl; using std::string;
using std::strcmp;
using std::begin; using std::end;
int main() {
	char charstr1[] = "Takeo Kikuchi";
	char charstr2[] = "Takeo Kikukikuchi";
	cout << end(charstr2) - begin(charstr2)<< endl;
	for (size_t i = 0; i != end(charstr2) - begin(charstr2); ++i) {
		cout << *(charstr2 + i) << " ";
	}
	cout << endl;

	size_t size = end(charstr2) - begin(charstr2) + end(charstr1) - begin(charstr1) + 1;
	char charstr3[size];

	strcpy(charstr3, charstr1);
	strcat(charstr3, " ");
	strcat(charstr3, charstr2);
	cout << charstr3 << endl;
}
