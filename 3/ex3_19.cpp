#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

int main() {
	vector<int> vec(10,42); // CANNOT USE = OPERATOR
	vector<int> vec2{42,42,42,42,42,42,42,42,42,42}; // CANNOT USE = OPERATOR
	vector<int> vec3;
	for (int i = 0; i < 10; ++i) {
		vec3.push_back(42);
	}
	cout << vec.size() << endl;
	for (auto c : vec)
		cout << c << " ";
	cout << endl;

	cout << vec2.size() << endl;
	for (auto c : vec2)
		cout << c << " ";
	cout << endl;
	cout << vec3.size() << endl;
	for (auto c : vec3)
		cout << c << " ";
	cout << endl;

}

/*
In the given case, I prefer the initialization method used in "vec". for the number of elements is limited, and the direct initialization is feasible.

However, generally, the initialization method applied for "vec3" is the most preferable for me. This is because it is cumbersome to specify all the initialization values when the direct initialization method is used.

Another reason why the initialization procedure for "vec3" is attractive is that the number of elements of vector does not be determined beforehand. If the required size of a vector cannot be determined until, for example, user input in the stream is given, it is impossible to determine the appropriate size of a vector. I 


--- Possible solution --- 
"The exception to this rule is if all the elements actually need the
same value. If differing element values are needed, it is usually more efficient
to define an empty vector and add elements as the values we need become
known at run time."
P. 148
*/
