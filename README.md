# This repository consists of my solutions to the exercises in the 5th edition of C++ Primer (5th edition.)

### Ex3_39: C-style char string vs char string
### Ex3_40: C-style char string concatenation (strcpy, strcat)
### Ex3_41: Inialization of a vector using an array
### Ex3_42: Inialization of a vector using an array
#### Key: Vectors can be initilized by arrays but not vice versa
### Ex3_43: Access to elements of multidimensional arrays - pointers - subscripts - range for
#### Key: Given arr of arr (2D arr) (= ptr to 1st arr in 1D), *(arr of arr) --> ptr to 1st arr in 2D --> *(ptr to 1st arr in 2D) --> 1st arr in 2D --auto-decay--> ptr to 1st arr in 2D.
#### arr of arr of int --> e.g. int (*ptr)[] / int[] ---> *(int (*ptr)[]) = int[] 
### Ex3_44: Access to elements of multidimensional arrays - type alias
### Ex3_45: Access to elements of multidimensional arrays - type auto
## Chap.4
### Ex4_1: Precedence Matter
### Ex4_2: Precedence Matter - order
### Ex4_3: Order of evaluation
### Ex4_4: Arismetic operator - precedence
### Ex4_5: Arismetic operator - precedence
### Ex4_6: Arismetic operator - modulus(%)
### Ex4_7: Overflow

### Ex4_15:
#### Illegal; int* canot be assigned to int.
#### dval = ival = 0;
#### pi = 0;

### Ex4_16:
#### Because either TRUE or FALSE is assigned to p.
#### Correction: (p = getPtr()) != 0 
#### Because this condition is always TRUE.
#### Correction: if ( i == 1024)

### Ex4_17:

#### The differences  between prefix and postfix are shown below:
#### prefix increments/decrements the operand and returns the changed object as an lvalue.
#### postfix increments/decrements the operand but returns a copy of the original unchanged value as an rvalue.

### #x4_18:
### while (pbeg != v.end() && *beg >= 0)
###     cout << *++pbeg << endl;
### for each iteration, increment the pointer pbeg and print the value to which the incremented pointer points.

### #4_19:
#### ptr != 0 && *ptr++: return 1 when ptr is not a null pointer and the value to which the non-incremented ptr points is not 0; return 0 otherwise.
#### ival++ && ival: return 0 when ival is either -1 or 0; otherwise return 1. 
#### vec[ival++] <= vec[ival]: This is likely to be incorrect because the result is undefined. The compiler might evaluate this expression as either vec[ival] <= vec[ival+1] or vec[ival] <= vec[ival]. This might be corrected with vec[ival+1] <= vec[ival]

### 4_20:
#### *ite++ : legal. The expression increments iter and return the string to which the previous iter points.
#### (*iter)++ : not legal. (*iter) is a string, which does not have ++ operation.
#### *iter.empty() : not legal. Because the precedence of . is higher than the one of *, this expression tries to fetch a member from iterator that does not exist. Hence this causes an error.
#### iter->empty(): legal. The expression returns 0 if the string to which iter points is empty, otherwise return 1.
#### ++*iter: not legal. Because the precedence of prefix++ and * is same, ++(*iter) is tied following the associativity, which is illegal since *iter is a string and does not have ++ operation.
#### iter++->empty() : legal. This expression increments iter and return the 0/1 depending on if the string to which the previous iter points is empty or not.
### 4__22:
#### if-else allows us to read the conditions much easily than cond ? pass : fail

### 4__23:
#### string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
#### precedence: []  . > - +  > ==  > ?: > =
#### It fails because the precedence of + is higher than the one of ==, and s is a string.
---
string pl = s + (s[s.size() - 1]_=='s'    >)


# 4_24:
---

finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";

---

If the operator is left associative, this expression returns "pass" when 60<= grade<=90; returns "fail" otherwise, which is apparently incorrect.

---

(grade > 90) ? "high pass" : (grade < 60) // return "high pass" or TRUE/FALSE
"high pass"/TRUE/FALSE ? "fail" : "pass" //

---

# 4_25: sol

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

# ****Soultions after ex4_28 are inside each folder.

# 4_29:
> Predict the output of ...