#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::iterator; using std::begin; using std::end;
/*
template <typename iterator>
void fun(iterator begin, iterator end)
{
	for (auto i = begin; i != end; ++i) {
		cout << *i << " ";
	}
	cout << endl;
}
*/
int f(vector<int> a, vector<int> b) {
	cout << "a.size = " << a.size() << ", b.size = " << b.size() << endl;
	if (a.size() != b.size()) {
		std::cerr << "The sizes of two vectors are different." << endl;
		return -1;
	}
	else {
		auto a_b = a.begin();
		auto a_e = a.end();
		auto b_b = b.begin();
		auto b_e = b.end();
		for (; a_b != a_e && b_b != b_e; ++a_b, ++b_b) {
			cout << "vec: " << *a_b << ", vec2: " << *b_b << endl;
			if (*a_b != *b_b) {
				std::cerr << "Two vectors are different: at least one element between 2 vectos does not match." << endl;
				return -1;
			}
		}
		cout << "Two vectors are the same" << endl;
	}
	return 0;
}
int main() {
	vector<int> vec{1,2,3,4,5,6,7,8,9,10};
	vector<int> vec2{1,2,3,4,5,6,7,8,9,10};
	vector<int> vec3{1,2,3,4,5,6,7,8,9,11};
	vector<int> vec4{1,2,3,4,5,6};
	f(vec, vec2);
	f(vec, vec3);
	f(vec, vec4);

}
