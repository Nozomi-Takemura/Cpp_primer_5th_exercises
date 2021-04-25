# 5_1:
- [x] 'Null statement' is the empty statement and is a single semicolon  It can be used when a program requires a statement but its logic does not require a statement such as 'while'

# 5_2:
- [x] 'block' is a sequence of statements and declarations that are surrounded by a pair of curly braces. It defines a 'scope'. 'block' is useful when a program requires a statement but its logic requires more than one statements.

# 5_3:
- [ ]

# 5_4:
- [ ] a. tried to go through all of the 'char' of an input 'string' s. 
- [ ] b. tried to check if a word ('char'?) exists given 'string', and to give the script when it is not found.

# 5_5:
- [x]

# 5_6:
- [x]

# 5_7:
- [x] a.
- [ ] b.
- [x] c.
- [ ] d.

# 5_8:
- [ ] 'Dangling else' is the problem to find which 'if' statement a given 'else' statement belongs.
- [x] C++ resolves 'Dangling else' problem by matching 'else' with the closest preceding unmatched 'if'.

# 5_9:
- [x]

# 5_10:
- [ ] : hint: use `case 'A': case 'a'`

# 5_11:
- [ ] : hint: use `std::cin.get()` because `<<` operator ignore some input elements 

# 5_12:
- [ ] :

# 5_13:
- [X] a. `break` is missing.
- [X] b. key: - with `switch`, it is illegal to jump from one label where a variable with initializer exists to another label. (Note string is automatically initialized with null string.)  
- [X] c. Misuse of case; when you want to perform the same operation for multiple cases, `:` needs to be used not `,` to list those cases. 
- [ ] d. `default` is missing. <-- wrong: hint 'case labels must be integral constant expressions'
- [X] a. (My sol)
> ```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a':
        aCnt++; 
        break;
    case 'e':
        eCnt++;
        break;
    default:
        iouCnt++;
        break;
}
```
- [X] b. (My sol)
> ```cpp
unsigned index = some_value();
int ix;
switch (index) {
    case 1:
        ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
        break;
}
```
- [X] c. (My sol)
> ```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1: case 3: case 5: case 7: case 9:
        oddcnt++;
        break;
    case 2: case 4: case 6: case 8: case 10:
        evencnt++;
        break;
}
```
- [ ] d. (My sol)
> ```cpp
unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
    default:
        break;
}
```
- d. (Example Solution)
> ```cpp
constexpr unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
    default:
        break;
}
```
# 5_14:
- [X] (My sol)
> ```cpp
#include <iostream>
#include <string>
#include <vector>
int main() {
using namespace std;
string inp;
vector<string> vec;
int ifreapp = 0;
int maxrep = 1;
string word;
string cinpre;
cout << "Type" << endl;
while (cin >> inp){
  cout << inp << " ";
  if (inp.compare(cinpre)==0){
    ++ifreapp;
  } else {
    if (maxrep < ifreapp){
      maxrep = ifreapp;
      word = cinpre;
    } 
    ifreapp = 1;
  }
    vec.push_back(inp);
  cinpre = inp;
}
cout << "Maximum repetition is the word " << word << ", and occurred " << maxrep  << "times." << endl;
cout << "help" << endl;
}
```

# 5_15:
- [] a. The iteration repeats `sz` times. Since `if` statement fails because `ix` is not defined outside of `for` loop.
- [] b. The `init-statement` of a `for` header is missing.
- [] c. Misuse of `++ sz`. It should have been `++sz`. The idea is to use multiple expressions in the for header; however, this is infinite loop.

# 5_16:
- [] a. For both idiomatic use-cases of `while` and `for` loops, I would use the original loop construct. The main reason is the simplicity of the hearder statement: i.e. init-statement, condition, expression for `for` and condtion for `for`.

# 5_17:

# 5_18:
- [] a. The loop tries to keep reading two integers from stdin and show the sum. The condition checks if there are still inputs from stdin, and if so, it goes next iteration. The problem is `while(cin)`. It should be`while(!cin.eof())`.
- [] b. The loop executes the block statement logic at first, and keep reating the same logic as long as getting a response.The variable definition `int ival = ` is not allowed inside `while()` condition because it is evaluated at the first time after the statement block is executed.
- [] c. The loop first gets a response, and continues to the next loop as long as the response exists. The problem is that the usage of `ival` inside the conditional statement is not allowed because it is defined inside block statement.

# 5_19:
- []

# 5_23:
- []
> ```cpp
#include <iostream>
#include <string>
using namespace std;
int main(){
  int intone;
  int inttwo;
  cout << "please type tow integers: " << endl;
  cin >> intone >> inttwo;
  cout << "input1 divided by input2 is " << intone/inttwo << endl;
```

# 5_24:
- []
The below is the output when a zero input has passed for denominator without catching exceptions.
> ```
please type tow integers: 
8 0
Floating point exception (core dumped)
```
The updated script in the below:
> ```cpp
#include <iostream>
#include <string>
using namespace std;
int main(){
  int intone;
  int inttwo;
  cout << "please type tow integers: " << endl;
  cin >> intone >> inttwo;
  if (inttwo == 0)
    throw runtime_error("the denominator for devision must not be zero.");
  cout << "input1 divided by input2 is " << intone/inttwo << endl;
}
```
will through error when 0 is fed:
>```
please type tow integers: 
10 0
terminate called after throwing an instance of 'std::runtime_error'
  what():  the denominator for devision must not be zero.
Aborted (core dumped)
```

# 5_25:
-[]
There is no 0-devision exception handling for C++. The message "floating point exception" is not a C++ exception. Here it is more appropriate to use simple > ```if-else``` statement.
> ```cpp
#include <iostream>
#include <string>
using namespace std;
int main(){
  int intone;
  int inttwo;
  cout << "please type tow integers: " << endl;
  while(cin >> intone >> inttwo){
    try{
      cout << "input1 divided by input2 is " << intone/inttwo << endl;
      break;
    }
    catch (runtime_error err){
      //runtime_error("Data must not be 0.");
      cout << err.what() << endl;
      cout << "Devision by 0 is not allowed. Please type the correct tow integers " << endl;
      cout << "Try Again? Enter y or n" << endl;
      char c;
      if(!cin||c =='y'){
    //     cout << "input1 divided by input2 is " << intone/inttwo << endl;
         break;
      }
    }
  }
}
```
