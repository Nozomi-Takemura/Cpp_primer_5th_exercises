#include<string>
#include<memory>
#include<map>
#include<iostream>
using std::shared_ptr;
using std::string;
using std::make_shared;
using std::map;
using std::cout;
using std::endl;
struct destination{
  // destination();
  public:
    destination() = default;
    destination(string &s1, int i): ipaddress(s1), port(i){};
  
    // const string _data;
    string ipaddress;
    int port;
    // shared_ptr<string> _sptr;
};
struct connection{
  public:
    connection() = default;
    connection(string s, int i): myport(i), myip(s){};
    // connection(initializer_list<string> il);
 
    int myport;
    string myip;
};
//create connection for certain destination
connection connect(destination *ptr)
{
  // shared_ptr<map<int,string>> map2port();
  // mapwport[ptr->ipaddress] = ptr->ipaddress;
  connection sptr(ptr->ipaddress, ptr->port);
  cout << "my ip:" << sptr.myip << ", myport:" << sptr.myport << " is now conncected to" 
    << " destination ip " << ptr->ipaddress <<" with port " << ptr->port << endl;
  return sptr;
}
void disconnect(connection sptr){
  cout << "my ip:" << sptr.myip << ", myport:" << sptr.myport << " is now disconnected from" << endl;
}
void end_connection(connection *p)
{
  disconnect(*p);
}
void f(destination &d){
  //bef: d._sptr-refcount=1 (b.c this is a reference to d)
  connection c = connect(&d);//pass ptr to d;
  // this is needed b.c. connecton does not have destructor
  // shared_ptr<connection> p(&c, end_connection);
  shared_ptr<connection> p(&c, [](connection *ptr) -> void {disconnect(*ptr);});
}
int main(){
  string target("http://test.com");
  int tarport = 8888;
  destination des(target,tarport); //des._sptr-refcount=1
  f(des); // des._sptr-refcount=2, destination._sptr-refcount=1(in f())
  //
}
