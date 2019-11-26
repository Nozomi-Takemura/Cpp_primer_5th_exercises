int main()
{
	const int buf; // <-- error becasue const type needs to be initialized. 
	int cnt = 0;  // ok
	const int sz = cnt; // ok 
	++cnt; ++sz; // <-- sz has const type; hence it couldn't be modified.
}
