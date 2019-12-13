#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;


int main() {
	vector<int> VecInt;
	int sum;
	int input;
	while(cin >> input) {
		VecInt.push_back(input);
	}
	vector<int> VecSum((VecInt.size()+1)/2);
	cout << "size of VecSum = " << VecSum.size() << endl;
	decltype(VecSum.size()) PreInd = 0;
/*
	for( decltype(VecInt.size()) index = 0; index != VecInt.size(); ++index) {
		if (PreInd == index/2) {
			VecSum[PreInd] += VecInt[index];
			//VecSum[PreInd] = VecInt[index]
			//VecSum[PreInd] = 0;
			cout << "Hola" << endl;
			
		}
		else {
			VecSum[PreInd+1] += VecInt[index];
			//VecSum[PreInd] = 1;
			cout << "Hola-Nah" << endl;
		}
		PreInd = index/2;
	}
*/
/* WRONG MODIFICATION NEEDS TO BE DONE
	for( decltype(VecInt.size()) index = 0; index != VecInt.size(); ++index) {
		if (VecInt.size() 
		if (index < (VecInt.size()+1)/2) {
			VecSum[PreInd] += VecInt[index];
			++PreInd;
			cout << "PreInd = " << PreInd << endl;
		}
		else {
			--PreInd;
			VecSum[PreInd] += VecInt[index];
			cout << "PreInd = " << PreInd << endl;
		}
	
	}
*/		
	cout << "Sum: "; 
	for (auto i : VecSum) {
		cout << i << " ";
	}
	cout << endl;
}
