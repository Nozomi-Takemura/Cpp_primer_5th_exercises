#include<iostream>
#include<string>
using std::string;
string sa[3]; //= {"a","b","c"};
int ia[3]; //= {1,2,3};
int main() {
    string sa2[10];
    int    ia2[10];

    for (auto i : sa) {
	std::cout << i << " ";
    }
    std::cout << "<-- sa" << std::endl;

    for (auto i : ia) {
	std::cout << i << " ";
    }
    std::cout <<  "<-- ia" << std::endl;

    for (auto i : sa2) {
	std::cout << i << " ";
    }
    std::cout <<  "<-- sa2" << std::endl;

    for (auto i : ia2) {
	std::cout << i << " ";
    }
    std::cout <<  "<-- ia2" << std::endl;
}

/*
Solutions:
--Error--
   <-- sa
0 0 0 <-- ia
          <-- sa2
156217552 32767 0 0 -550046208 32657 -550004832 32657 -550024792 32657 <-- ia2


--Explanation--
"In principle, a variable defined outside any function (that is, global, namespace, and class static variables) is initialized before main() is invoked. Such nonlocal variables in a translation unit are initialized in their declaration order (§10.4.9). If such a variable has no explicit initializer, it is by default initialized to the default for its type (§10.4.2). The default initializer value for built-in types and enumerations is 0. [...] There is no guaranteed order of initialization of global variables in different translation units. Consequently, it is unwise to create order dependencies between initializers of global variables in different compilation units. In addition, it is not possible to catch an exception thrown by the initializer of a global variable (§14.7). It is generally best to minimize the use of global variables and in particular to limit the use of global variables requiring complicated initialization."


-Bjarne Stroutrup, The C++ Programming Language


If an object that has automatic storage duration is not initialized explicitly, its value is indeterminate. If an object that has static storage duration is not initialized explicitly, then:
— if it has pointer type, it is initialized to a null pointer;
— if it has arithmetic type, it is initialized to (positive or unsigned) zero;
— if it is an aggregate, every member is initialized (recursively) according to these rules;
— if it is a union, the first named member is initialized (recursively) according to these rules.
-C Standard

*/
