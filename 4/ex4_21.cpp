#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl; using std::cin;
using std::string;
using std::vector;
int main(){
	vector<int> vec;
	int input;
	cout << "Enter Integers: " << endl;	
	while(cin >> input){
		vec.push_back(input);
	}
	cout << "The original vector: " ;
	for(auto &i : vec)
		cout << i << " ";
	cout << endl;
	for(auto &i : vec){
		i = i%2 == 1 ? 2*i:i;
	}
	cout << "The new vector: " ;
	for(auto &i : vec)
		cout << i << " ";
	cout << endl;
}
