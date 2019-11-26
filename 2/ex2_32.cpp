/*
int null = 0, *p = null;
-- This is --
*/

int main()
{
	int null = 0, *p = null;
}

/*
	--1.--
	p: int*
	null: int
	--> type error
	nullptr: int *
	This is illegal because the type of p and null is different. Using nullptr instead of null will solve this problem.

--- Solutions: ---
	--1.--
	ex2_32.cpp: In function ‘int main()’:
	ex2_32.cpp:8:21: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
	  int null = 0, *p = null;
		             ^~~~

*/
