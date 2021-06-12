# 3_39:
- C-style char string vs char string

# 3_40:
- C-style char string concatenation (strcpy, strcat)

# 3_41: 
- Inialization of a vector using an array

# 3_42: 
- Inialization of a vector using an array
- - Key: Vectors can be initilized by arrays but not vice versa

# 3_43: 
- Access to elements of multidimensional arrays - pointers - subscripts - range for
- - Key: Given arr of arr (2D arr) (= ptr to 1st arr in 1D), *(arr of arr) --> ptr to 1st arr in 2D --> *(ptr to 1st arr in 2D) --> 1st arr in 2D --auto-decay--> ptr to 1st arr in 2D.
- - arr of arr of int --> e.g. int (*ptr)[] / int[] ---> *(int (*ptr)[]) = int[] 

# 3_44:
- Access to elements of multidimensional arrays - type alias

# 3_45:
- Access to elements of multidimensional arrays - type auto