/*
Difference between decltype & auto
--Prediction--
Type deduction is auto requires the initilization with the varialbe that is used for type deduction.
On the other hand, the type deduction in decltype will allow other vairalbe to be useed for initialization.
*/

int main()
{
	// an example of an expression where auto&decltype will deduce the same type
	int i = 10, &ri = i;
	auto aut_i = i;
	decltype(i) dec_i = i; 
	// if both have the same type, this should pass <-- okay
	aut_i = 100;
	dec_i = 100;
	//  an example of an expression where auto&decltype will deduce the different type
	const int ci = 10, &rci = ci;
	auto aut_rci = rci;
	decltype(rci) dec_rci = rci; // this is maybe rvalue reference so it'd not be precise..
	// this should make an error
	aut_rci = 100; //<-- this should be okay since type(aut_rci) = int
	// dec_rci = 100; // <-- this should not pass because type(dec_rci)=&const int

	// better ex	
	auto aut_ci = ci; // int
	decltype (ci) dec_ci = ci; // const int;
	aut_ci = 100; // should be okay
	dec_ci = 100; // should make an error
}



