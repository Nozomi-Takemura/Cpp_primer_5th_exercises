#include <iostream>
#include <vector>
#include <list>
using namespace std;
void f(vector<int>::const_iterator citev, list<int>::const_iterator citel, bool& vLarThal, bool& vEqul){
  if((*citev) > (*citel)){
    vLarThal = true;
    vEqul = false;
  } 
  else if((*citev) < (*citel)){
    vLarThal = false;  
    vEqul = false;
  }
}

int main(){
  // vector<int> vecint1 = {1,2,3,20};
  vector<int> vecint1 = {1,2,3,20};
  list<int> vecint2 = {5,6,7,8,10,15};
  auto vecint2beg = vecint2.begin();
  auto vecint1beg = vecint1.begin();
  bool vecint1Largerthanvecint2;
  bool vecint1Equvecint2 = true;
  // for(auto ite = vecint1.begin(); ite != vecint1.end(); ite++){
  if(vecint1.size() == vecint2.size()){
   while(vecint1beg != vecint1.end()){
      // if((*vecint1beg) == (*vecint2beg)){
      f(vecint1beg, vecint2beg,vecint1Largerthanvecint2,vecint1Equvecint2);
        ++vecint1beg;
        ++vecint2beg;
    }
   }
  else if(vecint1.size() > vecint2.size()){
   vecint1Equvecint2 = false;
   vecint1Largerthanvecint2 = true; 
   while(vecint2beg != vecint2.end()){
      f(vecint1beg, vecint2beg,vecint1Largerthanvecint2,vecint1Equvecint2);
        ++vecint1beg;
        ++vecint2beg;
    }
  }
  else{
   vecint1Equvecint2 = false;
   vecint1Largerthanvecint2 = false; 
   while(vecint1beg != vecint1.end()){
      f(vecint1beg, vecint2beg, vecint1Largerthanvecint2,vecint1Equvecint2);
        ++vecint1beg;
        ++vecint2beg;
    }
  }
  cout << "vector<int>: ";
  for(auto e : vecint1)
    cout << e << " ";
  cout << endl;
  cout << "list<int>: ";
  for(auto e : vecint2)
    cout << e << " ";
  cout << endl;

  if(vecint1Equvecint2)
    cout << "vector == list - true" << endl;
  else{
   if(vecint1Largerthanvecint2)
    cout << "vector >  list - true" << endl;
   else 
    cout << "vector <  list - true" << endl;
  }
}
