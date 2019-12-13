/*
This solution is inspired by https://stackoverflow.com/questions/26764617/c-primer-5th-edition-exercise-3-24-iterators-in-vectors
*/

#include <iostream>
#include <vector>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main() {
	vector<int> VeIn;
	vector<int> VeSum;	
	int In;
	while(cin >> In) {
		VeIn.push_back(In);
	}
/*
// 1st part
	for(auto it = VeIn.begin(); it < VeIn.end(); it=it+2) {
		if (it + 1 != VeIn.end()) {
			cout << *it + *(it+1) << " ";
		}
		else {
			cout << *it;
		}
	}
	cout << endl;
*/
// 2nd part
	auto front = VeIn.begin();
	decltype(VeIn.end()) back = VeIn.end() - 1;
	for (; front <= back; ++front, --back) {
		if (front == back) {
			cout << *front << " ";
		}
		else {
			cout << *front + *back << " "; 	
		}		
	}
/*	
	auto ind = VeIn.size();
	for(auto it = VeIn.begin(); it != VeIn.end(); ++it) {
		--ind;		 
		VeSum.push_back(VeIn[ind] + *it);

	}


	for(auto it = VeIn.begin(); it != VeIn.end(); ++it) {
		VeSum.push_back(*it);
	}
	for(auto it = VeIn.end() - 1; it < VeIn.begin(); --it) {
		VeIn[ind] + *it;
	}
	for(auto  

	for(auto it = VeSum.begin(); it != VeSum.end()/2; it++) {
		cout << *it;

	}
*/
}


