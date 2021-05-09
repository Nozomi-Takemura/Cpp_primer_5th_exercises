// forward declare of class Y is mandatory
// otherwise, the compiler does not know how
// much storage a Y object needs
class Y;
class X {
	Y* y;
};
class Y {
	X x;
};
