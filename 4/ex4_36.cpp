#include <iostream>
using std::cout; using std::endl;

int main(){
	int i = 10; double d= 5.5;
	i *= static_cast<int>(d);
	cout << i << endl;
}
