int main()
{
	int i2 = 0;
	int i = -1;
	const int &r = 0; // const must be there bc a literal has a const type
	int &k = i; // this is okay since i doesn't have type const
//	int *const p2 = &i2; // legal since p2 is a constant pointer to int
//	const int i = -1, &r = 0; // legal since i is constant int and r is reference to constant int.
//	const int *const p3 = &i2; // legal since p3 is a constant pointer to constant int
//	int *p1 = &i2; // legal since p1 is a normal pointer to int where i2 is int.
//	int &const r2;// illegal bc there is no way of usage of r2 like this.
//	const int i2 = i, &r = i; // legal since i2 is a constant int and compiler creats a temporary const variable which let i not be const int. It's the same story for i2.
}

