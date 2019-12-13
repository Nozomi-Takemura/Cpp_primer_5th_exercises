#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

int main() {
	vector<int> v1; // 1.
	vector<int> v2(10); // 2.
	vector<int> v3(10,42); // 3.
	vector<int> v4{10}; // 4.
	vector<int> v5{10, 42}; // 5.
	vector<string> v6{10}; // 6.
	vector<string> v7{10, "hi"}; // 7.
	for (auto i : v1)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v1.size() << std::endl;
	for (auto i : v2)
		std::cout << i << " ";
	std::cout << std::endl;
	for (auto i : v3)
		std::cout << i << " ";
	std::cout << std::endl;
	for (auto i : v4)
		std::cout << i << " ";
	std::cout << std::endl;
	for (auto i : v5)
		std::cout << i << " ";
	std::cout << std::endl;
	for (auto i : v6)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v6.size() << std::endl;
	for (auto i : v7)
		std::cout << i << " ";
	std::cout << std::endl;
	/*
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << v4 << std::endl;
	std::cout << v5 << std::endl;
	std::cout << v6 << std::endl;
	std::cout << v7 << std::endl;
	*/
}

/*
PREDICTION -- 
1.
#elements = 1, value = 0 --> v1.size() == 0
2.
#elements = 10, value = 0
3.
#elements = 10, value = 42
4.
#elements = 1, value = 10
5.
#elements = 2, value = 10, 42
6.
#elements = 10, value = "null" <-- wrong nothing is outputted, although v6.size() = 0.
7.
#elements = 10, value = "hi"
--

ANSWER --
1.
initially empty --> size 0 vector with the size of each element being int.
2.


-OUTPUT-
1.
2.0 0 0 0 0 0 0 0 0 0 
3.42 42 42 42 42 42 42 42 42 42 
4.10 
5.10 42 
6.          
7.hi hi hi hi hi hi hi hi hi hi 
 
*/
