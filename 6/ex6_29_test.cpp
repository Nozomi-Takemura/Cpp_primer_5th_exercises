#include<iostream>
using namespace std;
int main(){
  int myarray [] = {1,2,3};
  int myarray2 [] = {1,2,3};
  for (auto i : myarray){
    i = 10;}
  for (auto & i : myarray2){
    i=10;}
  cout << "myarray: ";
  for (auto i : myarray){
    cout << i << " ";
  }
  cout << endl; 
  cout << "myarray2: ";
  for (auto i : myarray2){
    cout << i << " ";
  }
  cout << endl;
  
}
