#include <iostream>
/*
int main()
{
	int i = 3.14;
	std::cout << i << std::endl; //result = 3 <-- truncation is done becuase 3.14:double --> int
	return 0;
}
/*
----
No compile error; however, 3.14 is trancated into 3.
----
// Correction:
*/
int main()
{
	float i = 3.14f;
	std::cout << i << std::endl;
	return 0;
}
