#include <iostream>
int main(){
	int value = 0, sum = 0;
	std::cout << "Enter a set of integers you want to sum up." << std::endl;
	while (std::cin >> value)
		sum += value;
	std::cout << "Sum is : " << sum << std::endl;
	return 0;
}

