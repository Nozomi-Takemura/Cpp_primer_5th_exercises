#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl;
using std::string;
using std::vector;
int main(){
	int c = 1;
	string a = "aaaaaa";
	string b = "bbbbbb";
	string e = "1";
	string f = "2";
	string g = "3";
	string D;	
	vector<string>	vec{a,b,e,f,g, D};

	cout << a.empty() << endl;
	cout << D.empty() << endl;
	cout << c++ << endl;
	/* error 
	for(auto i = vec.begin(); i != vec.end(); i++){
		cout << i.empty() << endl;
	}
	*/
	// okay	
	for(auto i = vec.begin(); i != vec.end(); i++){
		cout << i->empty() << endl;
	}
	/* error
	for(auto i = vec.begin(); i != vec.end();){
		cout << ++*i << endl;
	}
	*/
	for(auto iter = vec.begin(); iter != vec.end();){
		cout << *iter << " " << iter++->empty() << endl;
	}
	vec = {a,b,e,f,g};

	for(auto i : vec)
		cout << i << endl;
}
