int main()
{
	int a = 10;
	const int i = 42;
	auto j = i; const auto &k = i; auto *p = &i;
	const auto j2 = i, &k2 = i;

	j = 10; // pass
	//k = 10; // error
	//p = &a; // okay because the type is not const pointer.
	//*p = a; // error because the type is the pointer to const int
	//j2 = 10;
	k2 = 10;
}

/*
Predicted types:
	j: int, for i is top-level const, and it's ignored.
	k: &int=reference to const int, for const is specifically specified and the const is kept when reference to a const object is declared.	
	p: poiner to const int
	j2; const int
	k2: reference to const int

------------------

TEST:
	j = 10; --> pass

	k = 10 --> error
	ex2_35.cpp: In function ‘int main()’:
	ex2_35.cpp:8:6: error: assignment of read-only reference ‘k’
	  k = 10;
	      ^~

	p = &a --> pass

	*p = a
	ex2_35.cpp: In function ‘int main()’:
	ex2_35.cpp:11:7: error: assignment of read-only location ‘* p’
	  *p = a; // error because the type is the pointer to const int
	       ^

	j2 = 10;
	ex2_35.cpp: In function ‘int main()’:
	ex2_35.cpp:12:7: error: assignment of read-only variable ‘j2’
	  j2 = 10;
	       ^~
	
	k2 = 10;
	ex2_35.cpp: In function ‘int main()’:
	ex2_35.cpp:13:7: error: assignment of read-only reference ‘k2’
	  k2 = 10;
	       ^~


*/
