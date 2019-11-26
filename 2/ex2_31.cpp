/*
v2: top-level const
v1: does not have neither top-level nor low-level const
p1: does not have neither top-level nor low-level const
r1: have neither top-level nor low-level const
p2: low-level const
p3: top-level and low-level const
r2: low-level const
*/

int main()
{
	int i = 0;
	const int v2 = 0;    int v1 = v2;
	int *p1 = &v1, &r1 = v1;
	const int *p2 = &v2, *const p3 = &i, &r2 = v2;

	r1 = v2; // 1.  
	//p1 = p2; // 2. 
	//p1 = p3; // 3. 
	p2 = p1; // 4. 
	p2 = p3; // 5. 
}

/*
	--1.--
	int& = const int is not legal. <---WRONG!!! --> int& = int is legal
	v2: top-level const, r1: reference to non-const
	--2.--
	int* = const int* is not legal.
	p1: pointer to non-const, p2: low-level const
	--3.--
	int* = const int *const is not legal. 
	p1: pointer to non-const, p3: top-level and low-level const
	--4.--
	const int* = int * is legal (we can convert noncost object into const object.)
	p2: low-level const, p1: pointer to non-const
	--5.--
	const int* = const int *const is legal bacause both have the same low-level const
	p2: low-level const, p3: top-level and low-level const

--- Solutions: ---
	--1.--
	okay
	--2.--
	ex2_31.cpp: In function ‘int main()’:
	ex2_31.cpp:19:7: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
	  p1 = p2; // 2.
	       ^~
	--3.--
	ex2_31.cpp: In function ‘int main()’:
	ex2_31.cpp:20:7: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
	  p1 = p3; // 3.
	       ^~
	--4.--
	okay
	--5.--
	okay
*/
