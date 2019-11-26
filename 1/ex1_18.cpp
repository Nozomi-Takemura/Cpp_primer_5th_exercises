#include <iostream>
int main(){
	std::cout << "Enter a set of integers: " << std::endl;
	int curval = 0, val=0, cnt = 0;
	if (std::cin >> curval){
		cnt = 1;
		while (std::cin >> val){
			if (val == curval)
				++cnt;
			else{
				std::cout << curval << " occurs " << cnt << " times " << std::endl;
				curval = val;
				cnt = 1;
			}
		}
		std::cout << curval << " occurs " << cnt << " times " << std::endl;
	}
	return 0;
}
