#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

int main() {
	vector<int> v1; // 1.
	vector<int> v2(10); // 2.
	vector<int> v3(10,42); // 3.
	vector<int> v4{10}; // 4.
	vector<int> v5{10, 42}; // 5.
	vector<string> v6{10}; // 6.
	vector<string> v7{10, "hi"}; // 7.
	
	for (auto i : v1)
		std::cout << i << " " ; 
	std::cout << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << std::endl;
	for (auto i : v2)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << std::endl;
	for (auto i : v3)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v3.size() << std::endl;
	std::cout << std::endl;
	for (auto i : v4)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v4.size() << std::endl;
	std::cout << std::endl;
	for (auto i : v5)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v5.size() << std::endl;	
	std::cout << std::endl;
	for (auto i : v6)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v6.size() << std::endl;
	std::cout << std::endl;
	//std::cout << v6.size() << std::endl;
	for (auto i : v7)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << v7.size() << std::endl;	
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

