#include <iostream>
#include <vector>
int main(){
	int *ptr = nullptr;
	std::vector<int> vec{1,2,3,4,5};
 	int ival = 4;
	std::cout << (ptr != 0 && *ptr++) << std::endl;
	std::cout << (ival++ && ival) << std::endl;
	ival = 3;
	std::cout << vec[ival++] << " " << vec[ival] << " " << std::endl;
	ival = 3;
	std::cout << (vec[ival++] <= vec[ival]) << std::endl;
}
