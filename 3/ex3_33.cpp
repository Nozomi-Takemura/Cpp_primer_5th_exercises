#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;

int main() {

	unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
	unsigned scores2[11];	
	unsigned grade;
	while (cin >> grade) {
	    if (grade <= 100)
		++scores[grade/10]; // increment the counter for the current cluster
		++scores2[grade/10];
	}	
	for (auto i : scores) {
		cout << i << " ";
	}
	cout << endl;
	
	for (auto i : scores2) {
		cout << i << " ";
	}
	cout << endl;
		
}

/*
--Prediciton--
Q.	What would happen if we did not initialize the scores array?
A.	Unexpected result would be returned bacause the default initialization value of an array declared inside a function call is not a value but a garbage value. 

--Result--
Input:
11 22 33 44 55 66 70 90 80 100 
Output:
0 1 1 1 1 1 1 1 1 1 1 
2 1 3327819054 21938 3592911265 32654 1 1 3327818977 21938 3327818113 

*/
