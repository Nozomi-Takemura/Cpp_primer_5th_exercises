#include <iostream>
int main(){
	std::cout << "Enter two integers" << std::endl;
	int v1 = 0, v2 = 0, val = 0;	
	std::cin >> v1 >> v2;
	if (v1 < v2){
		val = v2;
		while (v1 <= val){
			std::cout << val << std::endl;
			--val;
		}
	}
	return 0;
}

