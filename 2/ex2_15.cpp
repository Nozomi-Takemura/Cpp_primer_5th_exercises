#include <iostream>
int main()
{
	int ival = 1.01;// pre: invalid bc trancation will occur 
//	int &rval1 = 1.01;//pre: invalid bc 1.01 is not an object - So: &int vs int
	int &rval2 = ival; //pre valid bc ival is an object & its type = int
//	int &rval3;// pre reference requires the initilization.
}
