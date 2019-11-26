# include <iostream>
int main()
{
	int a = 100;
	int i;
	const int ic = 10;
	int *p1;
	const int *const p3 = nullptr;
	int *const p2 = &a;
	const int *test = nullptr;
	std::cout << "i: " << i << " ic: " << ic << " p1: " << p1 << " p3: " << p3 << " p2: " << p2 << std::endl; 
	i = ic; // 1. 
	std::cout << "after i = ic, i: " << i << std::endl;
	p1 = p3; // 2.
	p1 = &ic; // 3.
	// However, this works:
	test = &ic;
	p3 = &ic; // 4.
	p2 = p1; // 5.
	ic = *p3; // 6.
}

/* Wheather or not illegal
1. It's legal since i is type int to which a copy of the value of constant integer ic is assigned.

2. It's illegal:
	-- Error --
ex2_29.cpp: In function ‘int main()’:
ex2_29.cpp:13:7: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
  p1 = p3; // 2.
	-----------
As shown in the error message, the type error is given. A bit more intuitively, if you can assign an address which stored in constant pointer type to normal pointer type, the constant constraint is no longer held; which shouldn't be allowed. 

3. It's illegal bc of the type mismatch.
	--Error--
ex2_29.cpp: In function ‘int main()’:
ex2_29.cpp:14:7: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
  p1 = &ic; // 3.
       ^~~
	--------- 

4. It's illegal bc p3 is constant pointer so it cannot be modified.
	-- Error --
ex2_29.cpp: In function ‘int main()’:
ex2_29.cpp:18:8: error: assignment of read-only variable ‘p3’
  p3 = &ic; // 4.
        ^~
5. It's illegal bc p2 is a constant pointer so it cannot be modified.
	--Error--
ex2_29.cpp: In function ‘int main()’:
ex2_29.cpp:19:7: error: assignment of read-only variable ‘p2’
  p2 = p1; // 5.
       ^~

6. It's illegal since ic is constant integer so its value cannot be changed.
	--Error-
ex2_29.cpp: In function ‘int main()’:
ex2_29.cpp:20:8: error: assignment of read-only variable ‘ic’
  ic = *p3; // 6.
        ^~

*/
