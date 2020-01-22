/*
(a): i = 3, d = 3.0 
b: i = 3, d = 3.5
*/

#include <iostream>
int main(){
	int i; double d;
	d = i = 3.5;
	std::cout << d << " <--d, i--> " << i << std::endl;
	i = d = 3.5;
	std::cout << d << " <--d, i--> " << i << std::endl;
	
}

/*
3 <--d, i--> 3
3.5 <--d, i--> 3
*/
