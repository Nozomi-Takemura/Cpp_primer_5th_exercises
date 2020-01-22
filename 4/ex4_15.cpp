#include <iostream>
int main(){
	double dval; int ival; int *pi;
	dval = ival = 0;
	pi = 0;
}

/*
ex4_15.cpp: In function ‘int main()’:
ex4_15.cpp:4:19: error: invalid conversion from ‘int*’ to ‘int’ [-fpermissive]
  dval = ival = pi = 0;
                ~~~^~~

*/
