#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void f(){
  const string asc("BDFHIKLTbdfhiklt");
  const string des("GJPQYgjpqy");
  const string nei("ACEMNORSUVWXZacemnorsuvwxz");

}
size_t f(iostream& rin, size_t maxlen, const string& des, const string& asc, string& maxstring){
  string s;
  while(rin >> s){
    bool IfNotAscExi =(s.find_first_of(asc,0) == string::npos);
    bool IfNotDecExi =(s.find_first_of(des,0) == string::npos);
    if(IfNotAscExi and IfNotDecExi){
      if (maxlen < s.size()){
        maxlen = s.size();
        maxstring = s;
      } else if ((maxlen == s.size()) and maxlen != 0) {
        maxstring += ", " + s;
      }
    }
    cout << s << " ";
  }
  return maxlen;
}

int main(int argc, char** argv){
  const string asc("BDFHIKLTbdfhiklt");
  const string des("GJPQYgjpqy");
  const string nei("ACEMNORSUVWXZacemnorsuvwxz");
  string maxstring;
  fstream fs(*(argv+1), fstream::in | fstream::out);
  cout << "######## The input text ########" << endl;
  size_t maxlen = f(fs, 0, des, asc, maxstring);
  cout << endl << "######## The input text ########" << endl;
  fs.close();
  cout << "the longest word that contains neither ascenders not descenders: '" << maxstring << "' with length " << maxlen << "." << endl; 
}
