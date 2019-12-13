/*
Sol.

We need to use
	"mid = beg + (end - beg)/2" not "mid = (end - beg)/2
becuase the fomer one just gives the distance between two iterators. In order to specify a midpoint, we need to give an origine, in this case "beg", with the distance. 

*/

#include <iostream>
#include <string>
#include <vector>
using std::string; using std::cin; using std::endl;using std::cout;
using std::vector;

int main() {
	//vector<int> text{0,1,2,3,4,5,6,7,8,9};
	vector<int> text;
	for(decltype(text.size()) index = 0; index != 15; ++index) {
		text.push_back(index);
	}
	auto beg = text.begin(), end = text.end();
	auto mid = text.begin() + (end - beg)/2;
	int sought;
	cout << "mid = " << *mid << endl;
	cout << "type an int value between 0 and 9." << endl;
	cin >> sought;
	while (mid != text.end() && *mid != sought ) {
		if (*mid > sought) {
			end = mid;			
			//mid = beg + (end-beg)/2;
		}
		else {
			beg = mid;
			//mid = (end - beg)/2;
		}
		mid = beg + (end - beg)/2;
	}
	cout << "this is found: " << *mid << endl;
						
}  
