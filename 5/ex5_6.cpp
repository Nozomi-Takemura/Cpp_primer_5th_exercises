#include<iostream>
#include<vector>
#include<string>
using std::vector; using std::string;
int main(){
vector<string> scoresletter = {"F", "D", "C", "B", "A", "A++"};
vector<int> scores = {10,20,30,40,50,60,70,80,90,100};
vector<int>::iterator iter;
//int test;
string lettergrade;
for (iter=scores.begin(); iter!=scores.end(); ++iter){
//	test = (*iter)/10;	
//	std::cout << *iter << ':' << test << ':' << (*iter) % 10 << std::endl;
	lettergrade = (((*iter)/10) < 6) ?
		scoresletter[0]:
		(*iter==100) ?
			scoresletter[(*iter - 50)/10]:
			((*iter/10) > 7) ?
				scoresletter[(*iter - 50)/10] + '+':		
				scoresletter[(*iter - 50)/10] + '-';
	std::cout << *iter << "-->" << lettergrade << std::endl;
	
}
}

