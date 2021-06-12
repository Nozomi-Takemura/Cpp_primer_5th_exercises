#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
  cout << "type parenthesized expressions:" << endl;
  string input;
  getline(cin, input);
  string::size_type st;
  string::size_type prest = 0;
  stack<string> strStack;
  string ifenclosed;
  string rep;

  st = input.find_first_of("()");
  if(st != string::npos){
    if(st != 0)
        strStack.push(input.substr(0,st));
    // cout << "to_strin(input[st]): " << string(1,input[st]) << endl;
    strStack.push(string(1,input[st]));
    prest = st;
    // cout << "prest: " << prest << endl;
    while((st = input.find_first_of("()", prest+1)) != string::npos){
      strStack.push(input.substr(prest+1,st-prest-1));
      cout << "----" << input.substr(prest+1,st-prest-1) << "-----" << endl;
      if(input[st] == ')'){
        while((ifenclosed = strStack.top()).compare("(")!=0){
          rep = ifenclosed + rep;
          strStack.pop();
        }
        rep = "(" + rep + ")" + " <-- replaced"; // add open parenthesis
        strStack.pop(); // remove closest "("
        strStack.push(rep);// replaced. 
        cout << "****" << strStack.top() << "*****" << endl;
        rep.clear();
        ifenclosed.clear();
      } else {
        strStack.push(string(1,input[st]));
      }
      prest = st;
      // cout << "####" << st << "####" << endl;
    }
    // cout << "####prest" << prest << "####" << endl;
    if(prest != input.size())
      strStack.push(input.substr(prest+1));
    // cout << "====" << input.substr(prest+1) << "====" << endl;
  
  }
  cout << "final contents of stack: " << endl;
  while(!strStack.empty()){
    cout << strStack.top() << endl;
    strStack.pop();
  }
}
