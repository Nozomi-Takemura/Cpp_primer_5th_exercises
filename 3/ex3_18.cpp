#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;
/*
int main() {
	vector<int> ivec;
	ivec[0] = 42;
	cout << ivec[0] << endl;
	cout << ivec.size() << endl;
}
*/

/*
This is illegal/disastrous since ivec has size 0 becuase of uninitialization; neverthelss, its index 0 is specified... 
--Error message (compile has passed but execution failed)
Segmentation fault (core dumped)
*/

int main(){
	vector<int> ivec;
	ivec.push_back(42);
	cout << ivec[0] << endl;
	cout << ivec.size() << endl;
}
