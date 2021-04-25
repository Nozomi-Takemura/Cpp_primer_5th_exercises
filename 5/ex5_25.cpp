#include <iostream>
#include <string>
using namespace std;
int main(){
  int intone;
  int inttwo;
  cout << "please type tow integers: " << endl;
  while(cin >> intone >> inttwo){
    try{
      cout << "input1 divided by input2 is " << intone/inttwo << endl;
      break;
    }
    catch (runtime_error err){
      //runtime_error("Data must not be 0.");
      cout << err.what() << endl;
      cout << "Devision by 0 is not allowed. Please type the correct tow integers " << endl;
      cout << "Try Again? Enter y or n" << endl;
      char c;
      if(!cin||c =='y'){
    //     cout << "input1 divided by input2 is " << intone/inttwo << endl;
         break;
      }
    }
  }
}
