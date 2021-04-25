# 6_1:
- []
- - parameters: the variables used in a function.
- - arguments: the values to be used for initializing the paramters of a function upon a function call.

# 6_2:
(a), (b), (c), (d) are all in error. The reasons are as follows:
- [] (a). The return type `int` in the function defintion does not match with the one `string` in the body.
- [] (b). The return type is missing. 
- [] (c). One of the bracket `{` specifying the body is missing. The same parameter name is used twice.
- [] (d). The bracket is missing to specify the body.

# 6_3:
```cpp
#include <iostream>
using namespace std;
int fact(int n){
  int prod = 1;
  while(n > 0){
    //cout << n << " ";
    prod *= n;
    --n;
  }
  return prod;
}

int main(){
  int inp;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  cout << "factorial of "<< inp << " is " << fact(inp) << endl;
}
```

# 6_4:
```cpp
#include <iostream>
using namespace std;
int* fact(int results [2]){
  int prod = 1;
  int inp;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  results[0] = inp;
  while(inp > 0){
    //cout << n << " ";
    prod *= inp;
    cout << "current prod = " << prod << " ";
    --inp;
  }
  results[1] = prod;
  cout << endl;
  return results;  
}

int main(){
  int* outputs;
  outputs = fact(outputs);
  cout << "factorial of "<< *(outputs) << " is " << *(outputs+1) << endl;
}
```

# 6_5:
```cpp
#include <iostream>
using namespace std;
unsigned int abso(int inp){
  int oup;
  if(inp<0){
    oup = -1*inp;
  }
  else {
    oup = inp;
  }
  return oup;
}
int main(){
  int ui;
  cout << "Type any integer value for which the absolute value needs to be returned : " << endl;
  cin >> ui;
  cout << "abosolute(" << ui <<")=" << abso(ui) << endl;
}
```
# 6_6:
- [] parameter: a variable whose value is determined at run-time used in the function body. It is a part of function definition. In the below, the logic to return the absolute value of given user input is implemented via parameter. 
```cpp
#include <iostream>
using namespace std;
unsigned int abso(int inp){
  int oup;
  if(inp<0){
    oup = -1*inp;
  }
  else {
    oup = inp;
  }
  return oup;
}
int main(){
  int ui;
  cout << "Type any integer value for which the absolute value needs to be returned : " << endl;
  cin >> ui;
  cout << "abosolute(" << ui <<")=" << abso(ui) << endl;
}
```
- [] local variable: a variable that is only visible in a certain scope or , in this case, function definition. It is automatically removed after function exits.
In the example shown below, `oup` is a local variable that is used only in the function and is removed after the function call. It is nothing to do with external user input like `parameter`.
```cpp
#include <iostream>
using namespace std;
int pot(){
  int oup;
  cout << "Type any integer value for which you want to see its power of two" << endl;
  cin >> oup;
  return oup*oup;
}
int main(){
  cout << pot(2) << endl;
}
```
- a local static variable: a variable that is visible and exists across scope or, in this case, function body. The example below keeps the logical multiplication across different function calls. This enables to check if all of the integers fed to the iostream are positive not.
```cpp
#include <iostream>
using namespace std;
int conditionand(int inp){
  static int conand = 1;
  if(inp>0){
    conand *= 1;}
  else {
    conand *= 0;
  }
  return conand;
}
int main(){
  int input;
  int finalinput;
  cout << "Type multiple pos and neg int. The program should return 1 if all ints are pos, while return 0 otherwise." << endl;
  while(cin >> input){
    conditionand(input);
  }
  cout << "final result = " << conditionand(1) << endl;
}

# 6_7:
> ```cpp
#include <iostream>
using namespace std;
int gen(){
  static int seq;
    return seq++;
}
int main(){
  int tem;
  for (size_t i=0; i!=10;++i){
    tem = gen(); 
    while(tem >=  0){
      cout << tem << " ";
      --tem;
    }
    cout << endl;
  }
}
```

# 6_8:
`ex68header.h`
```cpp
#include <iostream>
using namespace std;
#ifndef FACT_6_3
#define FACT_6_3
int fact_6_3(int n);
int fact_6_3(int n){
  int prod = 1;
  while(n > 0){
    //cout << n << " ";
    prod *= n;
    --n;
  }
  return prod;
}
#endif
#ifndef FACT_6_4
#define FACT_6_4
int* fact_6_4(int results [2]){
  int prod = 1;
  int inp;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  results[0] = inp;
  while(inp > 0){
    //cout << n << " ";
    prod *= inp;
    cout << "current prod = " << prod << " ";
    --inp;
  }
  results[1] = prod;
  cout << endl;
  return results;
}
#endif
#ifndef ABSO_6_5
#define ABSO_6_5
unsigned int abso_6_5(int inp){
  int oup;
  if(inp<0){
    oup = -1*inp;
  }
  else {
    oup = inp;
  }
  return oup;
}
#endif
```
`ex6_8_test.cpp`
```cpp
#include <iostream>
#include "exheader.h"
using namespace std;
int main(){
  int inp;
  int outputs [2];
  int ui;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  cout << "factorial of "<< inp << " is " << fact_6_3(inp) << endl;
  cin.clear();
  fact_6_4(outputs);
  cout << "factorial of "<< *(outputs) << " is " << *(outputs+1) << endl;
  cout << "Type any integer value for which the absolute value needs to be returned : " << endl;
  cin.clear();
  cin >> ui;
  cout << "abosolute(" << ui <<")=" << abso_6_5(ui) << endl;
  cout << "Type any integer value for which the absolute value needs to be returned : " << endl;
  cin >> ui;
  cout << "abosolute(" << ui <<")=" << abso_6_5(ui) << endl;
}
```
An example of compile and call:
```console
$ g++ -Iex68header ex6_8_test.cpp -o ex6_8_test.o
$ ./ex6_8_test.o
Calculate factorial for integer: 
5
factorial of 5 is 120
Calculate factorial for integer: 
5
current prod = 5 current prod = 20 current prod = 60 current prod = 120 current prod = 120 
factorial of 5 is 120
Type any integer value for which the absolute value needs to be returned : 
-1
abosolute(-1)=1
Type any integer value for which the absolute value needs to be returned : 
-1
abosolute(-1)=1
```
# 6_9:
`ex6_9_factMain.cpp`
```cpp
#include <iostream>
#include "ex6_9header.h"
using namespace std;
int main(){
  int inp;
  cout << "Calculate factorial for integer: " << endl;
  cin >> inp;
  cout << "factorial of "<< inp << " is " << fact_6_3(inp) << endl;
}
```
`ex6_9_fact.cpp`
```cpp
#include <iostream>
using namespace std;
int fact_6_3(int n){
  int prod = 1;
  while(n > 0){
    //cout << n << " ";
    prod *= n;
    --n;
  }
  return prod;
}
```
`ex6_9header.h`
```cpp
#include <iostream>
using namespace std;
#ifndef FACT_6_3
#define FACT_6_3
int fact_6_3(int n);
#endif
```
Example code in bash:
```console
$ g++ -c ex6_9_factMain.cpp ex6_9_fact.cpp
$ g++ -o ex6_9_main ex6_9_factMain.o ex6_9_fact.o
$ ./ex6_9_main 
Calculate factorial for integer: 
5
factorial of 5 is 120
```

# 6_10:
```console
$ g++ -c ex6_10.cpp 
$ g++ ex6_10.o -o ./ex6_10_main
$ ./ex6_10_main
Type integer 1:
3
Type integer 2:
6
after applyting the funciton:
Integer 1: 6, Integer 2: 3
```

# 6_11:
```console
$ g++ ex6_11.cpp -o ex6_11.o
$ ./ex6_11.o 
Original input :100
Initialize input:
input after reset : 0
```

# 6_12:
```console
$ g++ ex6_12.cpp -o ex6_12.o
$ ./ex6_12.o 
Type integer 1:
3
Type integer 2:
9
after applyting the funciton:
Integer 1: 9, Integer 2: 3
```
- `Reference` version is easy to use because we don't have to handle `dereference` or `address` like `pointer`.

# 6_13:
- A function declaired `f(T)` is called by value, meaning that the passed argument will be copied to the paramter T. Hence the changes applied to T in the function does not effect on the argument. On the other hand, the `f(T&)` version is called by reference, which means that the fed argument will be linked to the parameter T; in other word, T is just another name of the argument and thus the changes made on T in the function has an impact on the argument.

# 6_14:
- An example situation when a parameter should be a reference is when a string needs to be passed to a function. This is because a string can be very big. Another instance is when an additional value need to be return besides the return value. On the other hand, an example situation when a parameter should not be a reference is when the argument passed to the parameter should not be changed after the function call. For instance, the following function changes the input value after the function call.
```cpp
#include <iostream>
using namespace std;
int fact(int &inp){
	int prod = 1;
	while(inp!=0){
		prod *= inp;
		--inp;
	}
	return prod;
}
int main(){
	int input = 5;
	cout << fact(input) << "is the factorial of " << input << endl;
}
```
```console
$ ./ex6_14.o
120is the factorial of 0 
```
As seen in the output, the value was changed and it is not correct.

# 6_15:
- Why the string parameter is a reference to const but *occurs* is a plain reference? <-- There are two reasons why the type for a string parameter is a reference to const string. To begin with, it should be reference to string because it is not efficient to copy the potentially big argument to parameter. Additionally, it should be const type because the passed string only needs to be scanned and it is not supposed to be changed.
- Why are these parameters references, but the char parameter *c* is not? <-- the parameter *occurs* is reference because it plays a role to return an additional value from the function via assigning new value to the *occurs*. If it was declared as non-reference value, then the argument value would not be changed after the function call because it is copied to the parameter. On the other hand, the char parameter *c* is not a reference because it is only used in the function and its value does not have to be returned.
- What would happen if we made *s* a plain reference?  <-- The string passed to the string could be potentially overwritten.
- What if we made *occurs* a reference to const? <-- It wouldn't play a role as originally designed because *occurs* wouldn't be allowed to be changed.


# 6_16:  
- Corrected version - no compilation errors:
```cpp
#include <iostream>
#include <string>
using namespace std;
bool is_empty_const(const string& s){ return s.empty();}
int main(){
  cout << "is_empty('AAA'): " << is_empty_const("AAA") << endl;
  cout << "is_empty('')" << is_empty_const("") << endl;
  }
```
```console
$ g++ ex6_16.cpp -o ex6_16.o
$ ./ex6_16.o
is_empty('AAA'): 0
is_empty('')1
```
- Original version - a :compilation error:
```cpp
#include <iostream>
#include <string>
using namespace std;
bool is_empty_original(string& s){ return s.empty();}
int main(){
  cout << "is_empty_original('AAA'): " << is_empty_original("AAA") << endl;
  }
```
```console
$ g++ ex6_16.cpp -o ex6_16.o
ex6_16.cpp: In function ‘int main()’:
ex6_16.cpp:11:68: error: cannot bind non-const lvalue reference of type ‘std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}’ to an rvalue of type ‘std::__cxx11::string {aka std::__cxx11::basic_string<char>}’
  */ cout << "is_empty_original('AAA'): " << is_empty_original("AAA") << endl;
```
# 6_17:
- a function to determine if a string contains any capital letters:
```cpp
#include <iostream>
#include <string>
using namespace std;
bool ex6_18_check(const string& s){
  bool re = false;
  for (auto c : s){
    if (isupper(c)) re = true;
    // cout << c << ' ';
  }
  return re; 
}
int main(){
  bool re;
  re = ex6_18_check("test Subject");
  cout << "for (auto c: s) style - a string, test Subject , contains a capital letter = " << re <<  endl;
  re = ex6_18_check("test subject");
  cout << "for (auto c: s) style - a string, "<< "test subject , contains a capital letter = " << re <<  endl;
  }
```
```console
$ g++ ex6_17.cpp -o ex6_17.o
$ ./ex6_17.o
for (auto c: s) style - a string, test Subject , contains a capital letter = 1
for (auto c: s) style - a string, test subject , contains a capital letter = 0
```
- a function to change a string to all lowercases.
```cpp
#include <iostream>
#include <string>
using namespace std;
void check(string& s){
  for (decltype (s.size()) sz = 0; sz != s.size(); ++sz){
    char c;
    c = std::tolower(s[sz]);
    s[sz] = c;
  }
}
int main(){
  string inp_re = "ABCDE";
  cout << "input : " << inp_re << endl;
  check(inp_re);
  cout << "output : " << inp_re << endl;
}
```
```console
$ ./ex6_17_change.o 
input : ABCDE
output : abcde
```
- The parameter for the first function is a reference to a const string, while the parameter for the second function is a reference to a string. The reference to const string is used for the first one becase the parameter is not be changed inside function. Also, this ensures a more generic usage of this function; for instance, literals can be passed as an argument.
On the other hand, the paramter of the second function takes reference to string because the arguement fed to parameter is changed inside function. If the reference to const string was used, the string could be changed and this function would not work as we want to.


# 6_18:
- Declarations in a header file:
```cpp
#include <vector>
#ifndef COMPARE
#define COMPARE 
bool compare(const matrix&);
#endif
#ifndef CHANGE_VAL
#define CHANGE_VAL
std::vector<int> change_val(int, std::vector<int>::iterator);
#endif:
```

# 6_19:
- [] a. Illegal because too many arguments are passed to a parameter.
- [] b. Legal.
- [] c. Legal.
- [] d. Legal.

# 6_20:
- Usage of reference parameters shoudl be references to const when the arguments should not be chagned or arguments can take too big memory to be efficient. When a plain reference is used when it could be a reference to const, the argument can be overwritten inside function.

# 6_21:
- const pointer to const int is used because:
- - the pointer and integer need not to be changed.
- - the int to which the pointer points to does not have to be changed.
```cpp
int compare(const int cint,const int * const  cptr){
  if(cint > (*cptr)){
    return cint;}
  else {
    return (*cptr);}
}
// this works, but not good. Reference to const int implies that the value can be chagned inside function.
int compare(const int& cint,const int* cptr){
  if(cint > (*cptr)){
    return cint;}
  else {
    return (*cptr);}
}
```
```console
$./ex6_21.o
Type integer 1 for integer
2
Type integer 2 that is the dereferenced int to which the pointer points
4
*cptr4
larger value is 4
```

# 6_22:
```cpp
#include <iostream>
using namespace std;
void switchint(const int*& cptr1, const int*& cptr2){
  const int* tmpcptr;
  tmpcptr = cptr1;
  cptr1 = cptr2;
  cptr2 = tmpcptr;
}
int main(){
  int test1 = 10;
  int test2 = 3;
  const int* cptr1;
  const int* cptr2;
  cout << "original - test1 = 10 & test2 = 3" << endl;
  cptr1 = &test1;
  cptr2 = &test2;
  cout << "bef: *cptr1=test1 = " << *cptr1 << ", *cptr2=test2=" << *cptr2 << endl;
  cout << "bef: cptr1= " << cptr1 << ", cptr2=" << cptr2 << endl;
  switchint(cptr1, cptr2);
  cout << "aef: cptr1= " << cptr1 << ", cptr2=" << cptr2 << endl;
  cout << "aft: *cptr1=test1 = " << *cptr1 << ", *cptr2=test2=" << *cptr2 << endl;
  cout << " shouldn't be valid. It should be switched." << endl;
}
```
```console
$ ./ex6_22.o
original - test1 = 10 & test2 = 3
bef: *cptr1=test1 = 10, *cptr2=test2=3
bef: cptr1= 0x7ffd45d48960, cptr2=0x7ffd45d48964
aef: cptr1= 0x7ffd45d48964, cptr2=0x7ffd45d48960
aft: *cptr1=test1 = 3, *cptr2=test2=10
 shouldn't be valid. It should be switched.
```
# 6_23:
```console
$ ./ex6_23_ptr_to_const_char.o
for i, 10 
for j[2],
$ ./ex6_23_beg_end.o 
for i, for j[2], 0 1 
$ ./ex6_23_size.o
for i, for j[2], 0 1 
$ ./ex6_23_ref.o 
for i, for j[2], 0 1 

```

# 6_24:
- The original function works when an array of size 10 is used as its argument. However, with the original function, only arrays of size 10 can be printed. By passing array and its size separately, any size of arrays can be printed with this function.
```cpp
//Original
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
//After fix
void print(const int ia[], std::size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << endl;
}
```

# 6_25:
```console
$ ./ex6_25.o ArrayOfChar1 ArrayOfChar2
concated arguments = ArrayOfChar1ArrayOfChar2
```

# 6_26:
```console
$ ./ex6_26.o prog -d -o ofile data0
supplied arguments are: 
./ex6_26.o prog -d -o ofile data0 
```

# 6_27:
```console
$ ./ex6_27.o
sum of {1,2,3,4,5,6,7,8,9} = 45
```
# 6_28:
- Reference to const string.

# 6_29:
- Yes. For instance, when the elements of an initializer_list are const strings, it is better to use reference to const string type because string can be very big and copying it is not efficient.

# 6_30:
```console
$ g++ ex6_30.cpp -o ex6_30.o
ex6_30.cpp: In function ‘bool str_subrange(const string&, const string&)’:
ex6_30.cpp:14:13: error: return-statement with no value, in function returning ‘bool’ [-fpermissive]
             return; // error #1: no return value; compiler should detect this
```
# 6_31:

- a reference: reference is lvalue so it is valid to return a reference to nonconst when you need to assign to the returned result from a function that return reference to nonconst. For instance, a function to change a char at certain index with certain new char should take a reference to a string and int.
- a reference to const: it is valid to return this type when you need return a reference but don't want to allow them to be changed. For instance, a function to check which of the inputted two strings is longer the other should take two reference to const string as parameter, and it should return one of them; i.e. reference to const string. The returned string is not expected to be changed so the type should be again reference to const string.

# 6_32:
- [] Legal. It replaces the each element of array with the value from 0 to 10. This is legal because the return type is a reference to int that is defined/initialized outside of function; in other words, it is a reference to no local-variable. Hence, the assignment to such return type is legal.

# 6_33:
```console
$ ./ex6_33.o
input vector = {1,2,3,4,5}
1 2 3 4 5 
```
# 6_34:
- If the stopping condition in factorial were if (val != 0), the recursion would end up with an endless recursion when the argument was a negative integer.

# 6_35:
- `val-1` was passed to the `fact` function to ensure that the recursion correctly works. If `val--` was used, `val` would be decreased only after the function call, implying that its recursivly called `fact` would take the same argument. This would result in an endless loop. To avoid such a issue, `val - 1` is used.   
```console
$ ./ex6_33.o
input vector = {1,2,3,4,5}
1 2 3 4 5 
10 f-9 8 f-7 6 f-5 4 f-3 2 f-1 
f-10 f-8 f-6 f-4 f-2 
```
```cpp
#include <iostream>
#include <vector>
using namespace std;
void vecprint(std::vector<int> vec){
  if (vec.size() >= 1){
    cout << *vec.begin() << " ";
    vec.erase(vec.begin());
    vecprint(vec);
  }
  else
    cout << endl;
}
void priminmin(const int i){
  cout << "f-" << i << " ";
}
int main(){
  std::vector<int> inpvec={1,2,3,4,5};
  cout << "input vector = {1,2,3,4,5}" << endl;
  vecprint(inpvec);
  for (auto i = 10; i!=0; --i){
    cout << i << " ";
    priminmin(--i);
  }
  cout << endl;
  for (auto i = 10; i!=0; --i){
    priminmin(i--);
  }
  cout << endl;
}
```

# 6_36:
```cpp
$ cat ex6_36_ref.cpp 
#include<iostream>
#include <string>
std::string (&f())[10]{
  static std::string staarrstr[10]={"a","a","a","a","a","b","b","b","b","b"};
  return staarrstr;} 
int main(){
  for (auto str : f()){
    std::cout << str << " ";
  }
  std::cout << std::endl;
}
```
```console
$ ./ex6_36_ref.o
a a a a a b b b b b 
```
# 6_37:
```console
$ ./ex6_37.o
type alias:
a a a a a b b b b b 
trailing return:
a a a a a b t r a i 
decltype:
a a a a a b d e c l
```

# 6_38:
```console
$ ./ex6_38.o
input an integer
5
1 3 5 7 9 
$ ./ex6_38.o
input an integer
4
0 2 4 6 8 
```
# 6_39:
- [] a. Redeclaration of the first declaration because the passed arguemtns are copied to the paramter ignoring top-level const. When int type arguments are passed, compilers canot distinguish two functions. This is a kind of illegal; it is just redeclaring the fisrt function.
- [] b. The second function is illegal; during the declaration, an error will be raised. Declaring a function that is different from a previously declared function only with respect to the return type is not allowed.
- [] c.This is legal. The input parameter is differen and return type is also different.

# 6_40:
- [] a. No errors.
- [] b. Erros. The parameters without default values must be located lefter position than those with default values.

# 6_41:
- [] a. Illegal. The number of passed arguments are not sufficient because `ht` does not have an default value nor is assigned any argument.
- [] b. Legal.
- [] c. Legal, but it is unlikely to match the programmer's intent because an implicite conversion from char '*' (unsigned int)to int occurs and this argugment is eventually passed to the wd parameter.

# 6_42:
```console
$ ./ex6_42.o success failure
./ex6_42.os
successs
failures
```

# 6_43
- [] a. This would be put in the header. The inline function is meant to be replaced with its expression by complier. To do so, the compilers needs not only the declarations but also the definitions of inline functions. However, these definitons must match one another exactly. To ensure this requirement, it is reasonable to put the definitions of inline functions in to header files.
- [] b. This would be put in the header. This declaration is quite generic and it looks a good idea to put it in the header to enable multiple source files to call it. 

# 6_44:
```console
 ./ex6_44.o
type first string
abcde
type second string
abcdefg
if first string is shorter than second string: 1
```

# 6_45:
- Assuming that this function is called frequently, it should be defined as inline because
- - it is only a small, single one line function.
- - it makes easier to modify the function later 
- - it makes easier to do debug

# 6_46:
- It is not possible because s1.size() and s2.size() are only evaluated during run-time so it is not possible.s2.size() is not a const expression.

# 6_47:
```console
$ ./ex6_47.o 
bef function call, the vector = {1,2,3,4,5,6,7,8}
size of the vector at current recursion is 8, and the value = 1
size of the vector at current recursion is 7, and the value = 2
size of the vector at current recursion is 6, and the value = 3
size of the vector at current recursion is 5, and the value = 4
size of the vector at current recursion is 4, and the value = 5
size of the vector at current recursion is 3, and the value = 6
size of the vector at current recursion is 2, and the value = 7
size of the vector at current recursion is 1, and the value = 8
size of the vector at current recursion is 0, and the value = 0
$ g++ ex6_47.cpp -o ex6_47.o -D NDEBUG
$ ./ex6_47.o 
bef function call, the vector = {1,2,3,4,5,6,7,8}
, and the value = 1
, and the value = 2
, and the value = 3
, and the value = 4
, and the value = 5
, and the value = 6
, and the value = 7
, and the value = 8
, and the value = 0
```

# 6_48:
- This loop is to keep reading strings from iostream until the target one is found. Then later try to check if the streams are good state or bad state. 
- This is not a good use of assert because this is not something that cannot happen with certain constraint, but more related to run-time error. In such a case, assert is not optimal to be applied.

# 6_49:
- Candidate function: all the overloaded functions visible in the current scope. [A function with the same name as the called function and its declaration is visible at the point of the function call of the called function.]
- Visile function: all the overloaded functions which can be called by the arguments passed during the function call. [A function which has the same number of parameters as the number of arguments passed to the called function and has the parameters whose types must match or can be convertible from the types of the arguments passed to the called function.]

# 6_50:
- [OK] a.
- - viable functions: f(int, int), f(double, double=3.14)
- - The call is ambiguous because the f(double, double=3.14) is better match for the 1st argument, while f(int,int) is better match for the 2nd argument.
- [OK] b.
- - viable function: f(int), f(double,double=3.14)
- - f(int) is the best match because f(double,double=3.14) requires an extra conversion from int to double.
- [OK] c.
- - viable functions: f(int, int), f(double, double=3.14)
- - f(int,int) is best match because the first argument 42 has type int and its conversion to double is not better.
- [OK] d.
- - viable functions: f(int, int), f(double, double=3.14)
- - f(double, double) is the best match. This is because f(int, int) requires extra conversion from double to int for the passed arguments.

# 6_51
- All the answers of mine for 6_50 were correct.

# 6_52:
- [] a. rank 3.
- [] b. rank 4.

# 6_53:
- [] a. In the 2nd declaration, references to const int objects are taken as parameters. This is differentiable than the first declaration because const int can only be passed to the second declaration.
```console
$ ./ex6_53.o
nonconst5
const10
```
- [] b. The effect introduced by the second declaration is that calc can now take pointer to const char as arguments.
```console
$ ./ex6_53_b.o
nonconst5
const10
```
- [] c. Although the 2nd declaration tries to create calc function taking const pointer to char parameters, this is just redeclaration of the 1st one because the top-level const is ignored. (because const argument is copied and then passed to the function.)

# 6_54, 6_55, 6_56
```console
$ ./ex6_55.o
given two integer, 1, 2, the 1. addition, 2.subtraction, 3.multiplication, 4.devision:
3
-1
2
0
```

```cpp
```