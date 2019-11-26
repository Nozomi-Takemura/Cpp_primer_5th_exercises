#include <iostream>
using std::cout; using std::endl;
int main()
{
	int sum = 0;
	int cur = 50;
	while ( cur <= 100) {
		sum += cur;
		cur++;	
	}
	cout << cur << ", sum: " << sum << endl; 
}

// 25*150 = 750 + 3000 + 75 + 51+99
