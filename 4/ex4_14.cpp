/*
if (42 = i)   
--> Error because literals cannot be used as a left operand of assignment operator.
if (i = 42)
--> Since i is nonzero, condition is always TRUE.


// TEST
--a--
ex4_14.cpp: In function ‘int main()’:
ex4_14.cpp:4:10: error: lvalue required as left operand of assignment
  if(42 = i)
          ^

--b--
i = 42 --> TRUE
*/

#include <iostream>

int main(){
	int i;

	// --b--
	if(i = 42)
		std::cout << "i = 42 --> TRUE" << std::endl;
	else {
		std::cout << "i = 42 --> FALSE" << std::endl;
	}
	// --a--
	/*
	if(42 = i)
		std::cout << "help" << std::endl;
	else {
		std::cout << "help" << std::endl;
	}
	*/
}
