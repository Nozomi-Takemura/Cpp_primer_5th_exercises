#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<fstream>
using namespace std;
struct PersonInfo {
    string name;
    vector<string> phones;
};
istream& fline2vec(istream& rin, vector<PersonInfo>& people, istringstream& record){
  string line, word;  
  while (getline(rin, line)) {
      PersonInfo info;      // create an object to hold this record's data
      record.clear();
      record.str(line);
      record >> info.name;  // read the name
      while (record >> word)        // read the phone numbers
          info.phones.push_back(word);  // and store them
      people.push_back(info); // append this record to people
     // cout <<  record.good() << "<-- good, " << record.eof() << "<-- eof, " << record.fail() << "<-- fail, " << record.bad() << "<-- bad";
  }
  return record;
}

ostringstream& output(ostringstream& formatted, const vector<PersonInfo>& people){
  for (const auto &entry : people) {    
      // make the flush empty
      formatted.str(string(""));
      formatted.clear();
      for (const auto &nums : entry.phones) { 
              formatted << " " << nums;
      }
      if (!formatted.str().empty())      
          cout << entry.name << " "     
             << formatted.str() << endl; 
      else                   
          cerr << "input error: " << entry.name
               << " invalid number(s) " << endl; 
  }  // cout << endl;
  return formatted;
}
int main(int argc, char **argv){
  vector<PersonInfo> people; 
  istringstream record; 
  ifstream finput(argv[1]);
  if(finput.is_open()){
    fline2vec(finput, people,record);
  }
  ostringstream formatted; 
  output(formatted, people);
}
