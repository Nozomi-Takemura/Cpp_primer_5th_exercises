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
	if (((*iter)/10) < 6){
		lettergrade = scoresletter[0];
	}
	else{
		lettergrade = scoresletter[(*iter - 50)/10];
		if (*iter!=100){		
			if ((*iter/10) > 7){
				lettergrade += '+';		
			}
			else{
				lettergrade += '-';
			}
		}
	}
	std::cout << *iter << "-->" << lettergrade << std::endl;
	
}
}

