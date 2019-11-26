int main()
{
//	int i, *const cp; // 1.
//	int *p1, *const p2;// 2.
//	const int ic, &r = ic; // 3.
//	const int *const p3; // 4.
	const int *p; // 5.
}

/* EXPLANATION
1.--
define i=0 with type int, and (try to) define cp of the type constant pointer to int.
2.--
declare a pointer to int, p1.  (Try to) define constant pointer to int, p2
3.--
(Try to) define constant int, ic. (Try to) define a reference to constant int, initilized by ic.
4.--
(Try to) define constant pointer to constant int, p3.
5.--
(Try to) define a pointer to constant int, p
*/

/* Wheather or not illegal
1.--
illegal since cp needs to be initilized.
--Error
ex2_28.cpp: In function ‘int main()’:
ex2_28.cpp:3:16: error: uninitialized const ‘cp’ [-fpermissive]
  int i, *const cp; // 1.
                ^~
--
2.--
This is illegal bc p2 is not initilized.
--Error
ex2_28.cpp: In function ‘int main()’:
ex2_28.cpp:4:18: error: uninitialized const ‘p2’ [-fpermissive]
  int *p1, *const p2;// 2.
                  ^~
--
3.--
This is illegal bc ic is not initilized.
--Error
ex2_28.cpp: In function ‘int main()’:
ex2_28.cpp:5:12: error: uninitialized const ‘ic’ [-fpermissive]
  const int ic, &r = ic; // 3.
            ^~
--
4.--
This is illegal bc p3 is not initilized.
--Error.
ex2_28.cpp: In function ‘int main()’:
ex2_28.cpp:6:19: error: uninitialized const ‘p3’ [-fpermissive]
  const int *const p3; // 4.
                   ^~
--
5.--
This is legall since "pointers are not initialized when they are instantiated. Unless a value is assigned, a pointer will point to some garbage address by default."  
*/
