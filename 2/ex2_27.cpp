int main()
{
	int i2 = 0;
	int i = -1, &r = 0; // 1. legal since i is int and r is reference to int. <- WRONG
	int *const p2 = &i2; // 2. legal since p2 is a constant pointer to int <- ok
	const int i = -1, &r = 0; // 3. legal since i is constant int and r is reference to literal, meaning that i2 must have a "const int" type constant int. <- ok
	const int *const p3 = &i2; // 4. legal since p3 is a constant pointer to constant int <- ok
	int *p1 = &i2; // 5. legal since p1 is a normal pointer to int where i2 is int. <- ok
	int &const r2;// 6. illegal bc there is no way of usage of r2 like this.
	const int i2 = i, &r = i; // 7. legal since i2 is a constant int and compiler creats a temporary const variable which let i not be const int. It's the same story for i2.
*/
}

/*
--Answqer:
1.
Error-- 
ex2_27.cpp:4:19: error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
  int i = -1, &r = 0; // legal since i is int and r is reference to int.
                  ^
--
--> literal is an const object; hence, to create a reference of it, reference to const must be created.
 
6. 
Error--
ex2_27_MODIFIED.cpp:10:13: error: ‘const’ qualifiers cannot be applied to ‘int&’
  int &const r2;// illegal bc there is no way of usage of r2 like this.
             ^~
ex2_27_MODIFIED.cpp:10:13: error: ‘r2’ declared as reference but not initialized
--

*/
