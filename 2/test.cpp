#include <iostream>
int main(){
	bool b = 1;
	bool a = "aaa";
	bool c = 0;	
	double d = 3.14e1L;
	float e = 10;
	double g = 10E-3F;
	extern int i;
	extern int i;
	extern int i;
	extern int i;
	extern int i;
	double dval = 3.14;
	const int &ri = dval;

//	int double = 3.14; <-- error
	int _;
//	int catch-22; <-- error
//	int 1_or_2 = 1; <- error
	double Double = 3.14; // pass because its not double
//	extern double pi = 3.1416;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << "Who goes with F\145rgus?\012" << std::endl;
	std::cout << 3.14e1L << std::endl;
	std::cout << .1024F << std::endl;
	std::cout << 1024.F << std::endl;
	std::cout << 3.14L << std::endl;
	std::cout << 10 << std::endl;
	std::cout << 10. << std::endl;
	std::cout << 10u << std::endl;
	std::cout << 10e-2  << std::endl;
	std::cout << sizeof(g)  << std::endl;
	std::cout << "sieze of 10u: "<< sizeof(10u)  << " 10: " <<  sizeof(10) << " 10.: " << sizeof(10.) << " 10e-2: " << sizeof(10e-2) <<  " 3.14: " <<  sizeof(3.14) << " 3.14f: " << sizeof(3.14f) << " 3.14L: " << sizeof(3.14L) << std::endl;
	std::cout << dval  << std::endl;
	std::cout << ri  << std::endl;
	dval = 3.1415;
	std::cout << dval  << std::endl;
	std::cout << ri  << std::endl;
	return 0;
}
