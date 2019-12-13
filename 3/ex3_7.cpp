// input is a string.
/*
for (auto &C : input) {
	C = 'X';
} 
VS
for (auto C : input) {
	C = 'X';
} 

--> for each iteration, "char& C = input[i-1]" is done. Since &C is another name of the object input[i-1], the operation "C = 'X'" results in input[i-1] = 'X'.
On the other hand, when "char C = input[i-1]" is done for each iteration, the value of input[i-1] is just copied to C. Hence, even tough 'X' is assigned to C, this does no effect on the input[i-1]. Thus, With the use of char C, we cannot change the input string. 
*/
