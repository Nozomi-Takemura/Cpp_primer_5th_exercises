/*
int i = 0;
(a) double* dp = &i;
--> assigne int i's address into pointer to type double, which is illegal becuase of unmatched types
(b) int *ip = i;
--> assign int into pointer to int, which is illegal because of unmatched types
(c) int *p = &i;
--->assign the address of int i into the pointer to the int p, which is legal
*/

// check answer:
#include <iostream>
int main()
{
	int i = 0;
	double* dp = &i;
	int *ip = i;
	int *p = &i;

}
/*
Error message:
---
ex2_21.cpp: In function ‘int main()’:
ex2_21.cpp:16:16: error: cannot convert ‘int*’ to ‘double*’ in initialization
  double* dp = &i;
                ^
ex2_21.cpp:17:12: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
  int *ip = i;
            ^

---
*/
