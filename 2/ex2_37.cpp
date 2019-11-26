/*
a: int
b: int
c: int
c: int&
*/
int main()
{
	int a = 3, b = 4;
	decltype(a) c; // if type(c)=type, this should be legal
	decltype(a = b) d; // if type(c)=type, this should be legal --> ERROR
}

/*
ex2_37.cpp: In function ‘int main()’:
ex2_37.cpp:11:18: error: ‘d’ declared as reference but not initialized
  decltype(a = b) d; // if type(c)=type, this should be legal
                  ^

*/
