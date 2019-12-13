#include <string>
#include <vector>
using std::vector;
using std::string;
int main() {
vector<vector<int>> ivec; // 1.
//vector<string> svec = ivec; // 2.
vector<string> svec(10, "null"); //3.
}

/*
1.
This is legal. This creates an object with the type vecot of vecors of integers. It's empty.

2.
This is illegal because the types of svec and ivec do not match.
-----
ex3_12.cpp: In function ‘int main()’:
ex3_12.cpp:7:23: error: conversion from ‘std::vector<std::vector<int> >’ to non-scalar type ‘std::vector<std::__cxx11::basic_string<char> >’ requested
 vector<string> svec = ivec;
                       ^~~~
-----
3.
This is legal since the given initialization is 10 of "null", which fits into a vector of strings.

*/
