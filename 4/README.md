# 4_1:
- Precedence Matter

# 4_2:
- Precedence Matter - order

# 4_3:
- Order of evaluation

# 4_4:
- Arismetic operator - precedence

# 4_5:
- Arismetic operator - precedence

# 4_6:
- Arismetic operator - modulus(%)

# 4_7:
- Overflow

# 4_15:
- Illegal; int* canot be assigned to int.
- dval = ival = 0;
- pi = 0;

# 4_16:
- Because either TRUE or FALSE is assigned to p.
- Correction: (p = getPtr()) != 0 
- Because this condition is always TRUE.
- Correction: if ( i == 1024)

# 4_17:
- The differences  between prefix and postfix are shown below:
- prefix increments/decrements the operand and returns the changed object as an lvalue.
- postfix increments/decrements the operand but returns a copy of the original unchanged value as an rvalue.

# 4_18:
- ```cpp
 while (pbeg != v.end() && *beg >= 0)
     cout << *++pbeg << endl;
     ```
- for each iteration, increment the pointer pbeg and print the value to which the incremented pointer points.

# 4_19:
- ptr != 0 && *ptr++: return 1 when ptr is not a null pointer and the value to which the non-incremented ptr points is not 0; return 0 otherwise.
- ival++ && ival: return 0 when ival is either -1 or 0; otherwise return 1. 
- vec[ival++] <= vec[ival]: This is likely to be incorrect because the result is undefined. The compiler might evaluate this expression as either vec[ival] <= vec[ival+1] or vec[ival] <= vec[ival]. This might be corrected with vec[ival+1] <= vec[ival]

# 4_20:
- *ite++ : legal. The expression increments iter and return the string to which the previous iter points.
- (*iter)++ : not legal. (*iter) is a string, which does not have ++ operation.
- *iter.empty() : not legal. Because the precedence of . is higher than the one of *, this expression tries to fetch a member from iterator that does not exist. Hence this causes an error.
- iter->empty(): legal. The expression returns 0 if the string to which iter points is empty, otherwise return 1.
- ++*iter: not legal. Because the precedence of prefix++ and * is same, ++(*iter) is tied following the associativity, which is illegal since *iter is a string and does not have ++ operation.
- iter++->empty() : legal. This expression increments iter and return the 0/1 depending on if the string to which the previous iter points is empty or not.

# 4_22:
- if-else allows us to read the conditions much easily than cond ? pass : fail

# 4_23:
- string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
- precedence: []  . > - +  > ==  > ?: > =
- It fails because the precedence of + is higher than the one of ==, and s is a string.
```cpp
string pl = s + (s[s.size() - 1]_=='s'    >)
```

# 4_24:
---

- finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";

---

- If the operator is left associative, this expression returns "pass" when 60<= grade<=90; returns "fail" otherwise, which is apparently incorrect.

---
```cpp
(grade > 90) ? "high pass" : (grade < 60) // return "high pass" or TRUE/FALSE
"high pass"/TRUE/FALSE ? "fail" : "pass" //
```
---

# [X]4_25: sol

> What is the value of `~'q' << 6` on a machine with 32-bit
ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the
bit pattern `01110001`?

1. `~` applies first because its precedence is higher than `<<`'s. The operand of `~` is int, so the 8 bit chars `01110001` is promoted to 32 bit ints as `00000000 00000000 00000000 01110001`.

2. NOT operator is applied on 32 bit ints as `11111111 11111111 11111111 10001110`.

3. Move 6 bits left as `11111111 11111111 11100011 10000000`.

4. Convert from 32 bit ints to decimal, the value is `-7296`.

# 4_26:

> In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

The size of int type is determined depending on the execution environments. In fact, A value of int type can be stored in at least 16 bits. In such a case, `quiz1 = quiz1 | 1UL << 27` cannot produce the expected result to fail.

# 4_27:
> What is the result of each of these expressions?
unsigned long ul1 = 3, ul2 = 7;

`ul1` is `000000000 00000000 00000000 00000011`.
`ul2` is `000000000 00000000 00000000 00000111`.

- (a) `ul1 & ul2`: 3
- (b) `ul1 | ul2`: 7
- (c) `ul1 && ul2`: True
- (d) `ul1 || ul2`: True

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
