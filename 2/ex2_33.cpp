/*typedef double wages;  
typedef wages base, *p;

wages hourly, weekly;    
SI item;

typedef char *pstring;
const pstring cstr = 0; 
const pstring *ps; 

const char *cstr = 0;	

auto item = val1 + val2;

auto i = 0, *p = &i;    
auto sz = 0, pi = 3.14;
*/
#include <iostream>
int main()
{

	int i = 0, &r = i;
	auto a = r;  


	const int ci = i, &cr = ci;
	auto b = ci; // this is top-level consts --> it's ignored.
	auto c = cr; 
	auto d = &i; 
	auto e = &ci; // address(&) of a consts object is low-level consts --> it's kept.

	const auto f = ci;

	auto &g = ci;
	/*
	auto &h = 42;
	const auto &j = 42


	auto k = ci, &l = i;  
	auto &m = ci, *p = &ci;

	auto &n = i, *p2 = &ci;
	*/
	std::cout << "a, b, c: " << a << ", " << b << ", " << c << std::endl;
	// prediction = a:0, b:0, c:0
	a = 42; // 1.
	std::cout << "a, b, c: " << a << ", " << b << ", " << c << std::endl;
	// prediction = a:42, b:0, c:0
	b = 42; // 2.
	std::cout << "a, b, c: " << a << ", " << b << ", " << c << std::endl;
	// prediction = a:42, b:42, c:0
	c = 42; // 3.
	std::cout << "a, b, c: " << a << ", " << b << ", " << c << std::endl;
	// prediction = a:42, b:42, c:42
	//d = 42; // 4.
	//e = 42; // 5.
	//g = 42; // 6.

}

/*
Ans:
	--1.--
This is legal and a = 42. 
	--2.--
This is legal and b = 42.
	--3.--
This is legal and c = 42.
	--4.--
This is illegal because int into int*(auto) is not legal. 
	--5.--
This is illegal because int into int*(auto) is not legal. <-- WRONG EXPLANATION
--> A INT OBJECT CANNOT BE CONVERTED INTO POINTER OF CONSTANT INT

	--6.--
This is illegal. When a reference to auto-deduced type, top-level consts in the initializer(ci) is not ignored; namely, type of g is const int&; hence the value cannot be changed.

------- Solutions --------------
	--1.--
	okay
	--2.--
	okay
	--3.--
	okay
	--4.--
	ex2_33.cpp:47:5: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
	 d = 42; // 4.
	     ^~
	--5.--
	ex2_33.cpp: In function ‘int main()’:
	ex2_33.cpp:48:5: error: invalid conversion from ‘int’ to ‘const int*’ [-fpermissive]
	 e = 42; // 5.
	     ^~
	--6.--
	ex2_33.cpp: In function ‘int main()’:
	ex2_33.cpp:49:5: error: assignment of read-only reference ‘g’
	 g = 42; // 6.
	     ^~

*/ 


