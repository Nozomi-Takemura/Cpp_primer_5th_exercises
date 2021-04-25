# 4_28

```
char: 1
bool1
int: 4
short: 2
long : 8
longo long: 8
wchar_t: 4
double: 8
float: 4
long double: 16
```
# 4_29

> Predict the output, explain your reasoning, run the program, and check if it's correct.



```cpp
int x[10];   int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

- Predicted outputs:
```cpp
// 10
// 2
```
- Explanation:
    - `sizeof(x) = 4bytes*10`, `sizeof(*x)= 4bytes` --> 4*10/4 = 10
    - `sizeof(p) = 8bytes`, `sizeof(*p)= 4bytes` --> 8/4 = 2

- Outputs:
```terminal
:~/Cpp_primer_5th_exercises/4$ g++ -o ./obj_files/ex4_29.o ex4_29.cpp
:~/Cpp_primer_5th_exercises/4$ ./obj_files/ex4_29.o
10
2
```

# 4_30
> parenthesize the following expressions to match the default evaluation:
- `sizeof x + y`
- `sizeof p->mem[i]`
- `sizeof a < b`
- `sizeof f()`

- `sizeof x + y`
    ```cpp
    sizeof(x)+y
    ```
    - Reason: the precedence of `size of` is higher than the one of `+`.
- `sizeof p->mem[i]`
    ```cpp
    sizeof(p->mem[i])
    ```
    - Reason: the precedences of member access `->` and subscript `[]` are higher than the one of `size of`.

- `sizeof a < b`
    ```cpp
    sizeof(a) < b
    ```
    - Reason: the precedences of `size of` is higher than the one of `<`.

- `sizeof f()`
    ```cpp
    sizeof(f())
    ```
    - Reason: the precedences of function call `()` is higher than the one of `size of`.
# 4_31:

>The program in this section....

## Predicition

- ~~Reason: We used prefix, not postfix, because prefix is slightly faster than postfix since the copy of original value is not created when prefix is used.~~ **<-- read Solution**
- What if postfix was used?: Nothing wouldn't be changed as explained in the following example:

    ```cpp
    #include <iostream>
    using std::cout; using std::endl;
    int main (){

      for (int i=0; i!=10;i++)
        cout << i << endl;
      for (int j = 0; j !=10; ++j)
        cout << j << endl;
    }
```
    These result in the same result because for loops shown above can be rewritten with while as:
    ```cpp
    int i=0; // j=0
    while(i!=10){ // j!=10
      cout << i << endl;// cout << j << endl;
      i++; // ++j
    }
    ```
    In both senarios, new loop begins with the incremented i/j.
    
    In the given problems,
    ```cpp
    vector<int>::size_type cnt = ivec.size();
    for(vector<int>::size_type ix = 0;
                ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;
  ```  
  can be rewritten as
    ```cpp
    vector<int>::size_type ix = 0
    while(ix != ivec.size()){
      --cnt
      ivec[ix] = cnt;
      ++ix
    }
    ```
  so nothing changes neither.
## Solution:
> Advice: Use Postfix Operators only When Necessary on §4.5. Increment and Decrement Operators.
(copied from: <https://github.com/Mooophy/Cpp-Primer/tree/master/ch04>, <https://stackoverflow.com/questions/22591387/usage-of-prefix-or-postfix-increment-or-decrement>)

# 4_32:
## Question:
> Explain ...
## Prediciton:

>```cpp
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0;
     ix != size && ptr != ia+size;
     ++ix, ++ptr)   { /* ...   */ }
int* ptr
```

The loop says following:
1. 'ptr' is initialized with the pointer to the first element of `ia[5]`, and then ix is initialized with 0.
2. check if `ix` dose not exceed the size of array. If `ix` exceeds, break from the loop.
3. check if `ptr` does not exceed the pointer which points to the last value of `ia`. If `ptr` exceeds, break from the loop.
4. perform operation inside loop.
5. increments `ix`, and return incremented `ix`.
6. increments `ptr`, and return incremented `ptr`.
7. repeat 2~6.

# 4_33:
### Q
> someValue ? ++x, ++y : --x, --y
### ~Pred~ <span style="color:red">**<-- This is wrong; look at Sol**</span>
The expression always returns `x`.
According to
```cpp
(someValue ? (++x), (++y) : ((--x), (--y)))
```
1. `++x`
2. `++y`
3. `--x`
4. `--y` // now x is x and y is y.
5. `someValue ? x : x` // because ++x and --x is x.
6. ``
6. `(x, x)` // because --x is x, returning x.
7. `somevalue ? x : x`. // always return x.

### Sol:
> ↑ The expression in the middle of the conditional operator (between ? and :) is parsed as if parenthesized: its precedence relative to ?: is ignored. (copied from <https://en.cppreference.com/w/c/language/operator_precedence> )

Based on this,

>```cpp
(someValue ? (++x), (++y) : ((--x), (--y)))
 ```

 is as same as
 ```cpp
(someValue ?( ++x, ++y ): --x), --y //  ```
 This expression has 2 steps:
 1. Increments `x` and `y` if True, decrements `x` if False,
 2. decrements and returns `y`.

 , meaning that it returns decremented `y` when it is `0` and  returns the original `y` otherwise.

 # 4_34:
> Given...
`float fval;`
  ### Pred:
- a. conversion from `float` into `bool` takes place.
- b. the following conversions take place:
    - from `int` into `float`,
    - from `float` into `double`.
- c. the following conversions take places:
    - from `char` into `int`
    - from `int` into `long`

 # 4_34:
> Given...
`float fval;`
  ### Pred:
- a. conversion from `float` into `bool` takes place.
- b. the following conversions take place:
    - from `int` into `float`,
    - from `float` into `double`.
- c. the following conversions take places:
    - from `char` into `int`
    - from `int` into `long`

# 4_35:
- [x] a. 'a' is promoted into 'int', then added 3, then converted/truncated into char
- [ ] b. 'ival' is promoted into 'float', and then promoted into unsigned int, and then the result is promoted into 'loat' <-- wrong: 'ival' is promoted into double
- [x] c. depends on the machine
- [x] d. 'ival' is promoted into 'float', then 'ival + fval' is promoted into 'double', and the result is converted into 'char'

# 4_38:
> int i, j;
> double slope = static_cast<double>(j/i)
  
- [ ] j and i are promoted into 'double', then 'j/i' is calculaed. After this, it is converted into 'int', then this result is converted into double.
