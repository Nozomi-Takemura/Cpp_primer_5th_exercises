#include <iostream>
/*
int main()
{
	int *p;
	if(p)
		std::cout << "if(p) passed" << std::endl;
	if(*p)
		std::cout << "if(*p) passed" << std::endl;
}
*/
// output - Segmentation fault (core dumped)
int main()
{
	int *p;
	int a = 10;	
	std::cout << p << std::endl;
	p = nullptr;	
	std::cout << p << std::endl;
	p = &a;
	std::cout << p << std::endl;
	if(p){
		std::cout << "if(p) passed" << std::endl;
	}
//	if(*p) {
//		std::cout << "if(*p) passed" << std::endl;
//	}
}

/*
if pointer is not initilized with an object, if(*p) produces seqmentation fault because it tries to get the value from the region of the memory where is originally allocated for pointer.
On the other hand, if(p) corrctly works, although it returns false.

Once some object is assigned to p, both conditions are satisfied.
*/

