/*
const char *cp = "Hello World";
if (cp && *cp)

The program following if is proceeded only if pointer to "Hello World" is not nullptr and dereferenced const char is not a null char.

*/
#include <iostream>
int main() {
	const char *cp = "Hello World";
/*
	// This results in segmentation fault.
	while (cp) {
		std::cout << *cp << std::endl;
		cp++;
	}
	// This works as expected.
	while (*cp) {
		std::cout << *cp << std::endl;
		cp++;
	}
*/
	// This works as expected.
	while (cp && *cp) {
		std::cout << *cp << std::endl;
		cp++;
	}

	
	
/*
	if (cp && *cp)
		std::cout << *cp << std::endl;
*/
}
