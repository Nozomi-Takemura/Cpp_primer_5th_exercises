#include <iostream>
using namespace std;
int fact(int &inp){
	int prod = 1;
	while(inp!=0){
		prod *= inp;
		--inp;
	}
	return prod;
}
int main(){
	int input = 5;
	cout << fact(input) << "is the factorial of " << input << endl;
}
