int main() {
	constexpr unsigned array_size = 10; 
	int ia[array_size];
	for (unsigned ix = 1; ix <= array_size; ++ix)
	      ia[ix] = ix;
}

/*
---Prediction:
For loop shall make an error becuase ix reaches 10, although only the indexeis between 0 and 9 are acceptable for ia.

---Solutions:
"ix <= array_size ---> ix < array_size" will solve one error.
"size_t ---> unsigned" will solve another error
*/
