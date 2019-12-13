#include <iostream>
#include <string>
#include <vector>
using std::string; using std::cin; using std::endl;using std::cout;
int main() {
	string input;
//	std::cout << endl;
	std::vector<string> para;
	//getline(cin, input)	
	while(getline(cin, input)) {
		para.push_back(input);		
		//std::cout << endl;	
		//std::cout << input;
	}

	for (auto &c : para[0]) {
		c = toupper(c);
	}
	for (auto it = para.begin(); it != para.end(); ++it) {
		cout << *it;
		cout << endl;
	}			
	//std::cout << std::endl;
}		

/*

	The Nobel peace prize laureate Aung San Suu Kyi has defended Myanmar’s government against accusations of genocide at the International Court of justice, calling the allegations “factually misleading”.

	Addressing a bench of 17 judges from around the world, the 74-year-old leader dismissed reports of state violence against Rohingya Muslims and blamed the conflict on an uprising by separatist insurgents.

	The attacks were initiated by members of Arakan Rohingya Salvation Army, Aung San Suu Kyi told the court as she displayed detailed maps of Rakhine state showing, she claimed, where the first assaults began in late 2016. Myanamar’s security forces responded to that violence, she said

*/
