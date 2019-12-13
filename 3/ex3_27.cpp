int txt_size() {
	return 4;
}

int main() {

	unsigned buf_size = 1024;
//	int ia[buf_size]; //(a) 
//	int ia[4 * 7 - 14]; //(b) 
//	int ia[txt_size()];//(c) 
	char st[11] = "fundamental";//(d) 
}
/*
Predicitons:
-(a)-
Legal. buf_size has unsigned type. 
-(b)-
Legal.
-(c)-
Legal.
-(d)-
Illegal. a string "fu nd am en ta l" requires actually an array of the size 12 because of '\n' at the end.

Solutions:
-(a)-
okay 
-(b)-
okay
-(c)-
okay
-(d)-
----Error---- 
ex3_27.cpp: In function ‘int main()’:
ex3_27.cpp:11:16: error: initializer-string for array of chars is too long [-fpermissive]
  char st[11] = "fundamental";//(d)
*/
