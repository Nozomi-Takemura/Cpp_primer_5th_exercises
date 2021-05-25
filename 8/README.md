# 8_1:
```cpp
#include <string>
#include <iostream>
std::istream& f(std::istream& is){
  std::string inp;
  while(!is.eof()){
    is >> inp;
    std::cout << inp << " ";
  }
  is.clear();
  return is;
}
int main(){
  f(std::cin);
}
```

# 8_2:
```console
$ ./objectfile/ex8_1.o 
Every time I close my eyes
Every time I close my eyes 
```

# 8_3:
- [] the *while* statement is terminated by "incorrect" state of the input stream; such error states occurs when *>>* (read) operation fails or it encounters *end-of-line*.

# 8_4
```cpp
// non-function version
#include <vector>
#include <string>
//#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
int main(const int argc, const char** argv){
  std::fstream in;//(*argv);
  std::ostringstream op;
  std::vector<std::string> vec;
  in.open(*(argv+1));
  std::cout << "will open " << std::string(*argv) << std::endl;
  std::string tmp;
  if (in){
    while(std::getline(in, tmp)){
      vec.push_back(tmp);
      std::cout << tmp << std::endl;
      op.str(tmp);
      op << "--stringstream--" << tmp << std::endl; 
      std::cout << op.str();
    }
  } else
    std::cerr << "could't open: " + std::string(*argv);
}
```
```console
8$ cat ex8_4.txt 
I want to live in New York.
I want to visit Budapest.
I want to become an actuary.
I want to learn how to invest.

$ ./objectfile/ex8_4.o "ex8_4.txt"
will open ./objectfile/ex8_4.o
I want to live in New York.
--stringstream--I want to live in New York.
I want to visit Budapest.
--stringstream--I want to visit Budapest.
I want to become an actuary.
--stringstream--I want to become an actuary.
I want to learn how to invest.
--stringstream--I want to learn how to invest.
```
```cpp
//function version
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
ifstream& fread(ifstream& ifs, vector<string>& rvec, const string fname){
  ifs.open(fname);
  std::cout << "will open " << fname << std::endl;
  std::string tmp;
  if (ifs.is_open()){
    while(std::getline(ifs, tmp)){
      rvec.push_back(tmp);
    }
  } else
    std::cerr << "could't open: " + fname;
  return ifs;
}

ostringstream& vecprint(ostringstream& oss, const vector<string>& rcvec){
  for(auto line : rcvec){
    cout << "--ostream-- " << line << ", ";
    oss.str(line);
    oss << "--ostringstream-- " << line;
    cout << oss.str() << endl;
  }
  return oss;
}

int main(const int argc, const char** argv){
  const string fname = *(argv+1); // take a file name, argv[0] is the script name
  std::vector<std::string> vec;
  std::ifstream in;
  std::ostringstream op;
  if(fread(in, vec, fname).eof())
    vecprint(op, vec);
  else
    std::cerr << "could't open: " + fname;
}
```
```console
$ ./objectfile/ex8_4_update.o "ex8_4.txt"
will open ex8_4.txt
--ostream-- I want to live in New York., --ostringstream-- I want to live in New York.
--ostream-- I want to visit Budapest., --ostringstream-- I want to visit Budapest.
--ostream-- I want to become an actuary., --ostringstream-- I want to become an actuary.
--ostream-- I want to learn how to invest., --ostringstream-- I want to learn how to invest.
```

# 8_5:
```cpp
#include <vector>
#include <string>
//#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
ifstream& fread(ifstream& ifs, vector<string>& rvec, string fname){
  ifs.open(fname);
  std::cout << "will open " << fname << std::endl;
  std::string tmp;
  if (ifs.is_open()){
    while(ifs >> tmp){
      rvec.push_back(tmp);
    }
  } else
    std::cerr << "fread - could't open: " + fname << endl;
  return ifs;
}

ostringstream& vecprint(ostringstream& oss, const vector<string>& rcvec){
  for(auto line : rcvec){
    cout << "--ostream-- " << line << ", ";
    oss.str(line);
    oss << "--ostringstream--" << line << endl;
    cout << oss.str();
  }
  return oss;
}

int main(const int argc, const char** argv){
  string fname = *(argv+1); // take a file name, argv[0] is the script name
  std::vector<std::string> vec;
  std::ifstream in;
  std::ostringstream op;
  if(fread(in, vec, fname).eof())
    vecprint(op, vec);
  else
    std::cerr << "main-could't open: " + fname << endl;
}
```
```console
$ ./objectfile/ex8_5.o "ex8_4.txt"
will open ex8_4.txt
--ostream-- I, --ostringstream--I
--ostream-- want, --ostringstream--want
--ostream-- to, --ostringstream--to
--ostream-- live, --ostringstream--live
--ostream-- in, --ostringstream--in
--ostream-- New, --ostringstream--New
--ostream-- York., --ostringstream--York.
--ostream-- I, --ostringstream--I
--ostream-- want, --ostringstream--want
--ostream-- to, --ostringstream--to
--ostream-- visit, --ostringstream--visit
--ostream-- Budapest., --ostringstream--Budapest.
--ostream-- I, --ostringstream--I
--ostream-- want, --ostringstream--want
--ostream-- to, --ostringstream--to
--ostream-- become, --ostringstream--become
--ostream-- an, --ostringstream--an
--ostream-- actuary., --ostringstream--actuary.
--ostream-- I, --ostringstream--I
--ostream-- want, --ostringstream--want
--ostream-- to, --ostringstream--to
--ostream-- learn, --ostringstream--learn
--ostream-- how, --ostringstream--how
--ostream-- to, --ostringstream--to
--ostream-- invest., --ostringstream--invest.
```

# 8_6 & 8_7:
```cpp
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Sales_data {
  friend ostream& print(ostream& os, const Sales_data& crsd);
  friend istream& read(istream& is, Sales_data& rsd);
  public:
    inline const string& isbn() {return bookNo;}
    Sales_data& combine(const Sales_data& crsd);
  private:
    /*
    ostream& do_disply(ostream& os){
      os << "bookNo=" << bookNo << " " << "units_sold=" << units_sold << " revenue=" << revenue;
      return os;
    }
    */
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& crsd){
  units_sold += crsd.units_sold;
  revenue += crsd.revenue;
  return (*this);
}
istream& read(istream& is, Sales_data& rsd){
  double price;
  is >> rsd.bookNo >> rsd.units_sold >> price;
  rsd.revenue = price*rsd.units_sold;
  return is;
}
ostream& print(ostream& os, const Sales_data& crsd){
  os << "bookNo=" << crsd.bookNo << " " << "units_sold=" << crsd.units_sold << " revenue=" << crsd.revenue;
}
int main(int argc, const char** argv){
  string fname(argv[1]);
  string foutname(argv[2]);
  cout << fname << endl;
  Sales_data total;         // variable to hold the running sum
  ifstream fin;
  ofstream fout;
  fin.open(fname);
  fout.open(foutname);
  if(fin.is_open()){
    if (read(fin, total))  {  // read the first transaction
        Sales_data trans;     // variable to hold data for the next transaction
        while(read(fin, trans)) {      //  read the remaining transactions
            if (total.isbn() == trans.isbn())   // check the isbns
                total.combine(trans);  // update the running total
            else {
              if(fout){
                print(fout, total) << endl;  // print the results
                total = trans;               // process the next book
              }
            }
        }
        if(fout){
          print(fout, total) << endl;          // print the last transaction
        }
    } else {                                 // there was no input
        cerr << "No data?!" << endl;         // notify the user
    }
  } else 
    cerr << "Cannot find/open Input file: " << fname; 
  fin.close();
  fout.close();
}
```
```console
$ cat ex8_6.txt 
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
0-202-12345-X 3 30.00
0-202-12345-X 4 4
0-202-12347-X 1 60.00
0-202-12346-X 7 3

$ cat ex8_6_result.txt 
bookNo=0-201-78345-X units_sold=5 revenue=110
bookNo=0-202-12345-X units_sold=7 revenue=106
bookNo=0-202-12347-X units_sold=1 revenue=60
bookNo=0-202-12346-X units_sold=7 revenue=21
```

# 8_8:
```cpp
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Sales_data {
  friend ostream& print(ostream& os, const Sales_data& crsd);
  friend istream& read(istream& is, Sales_data& rsd);
  public:
    inline const string& isbn() {return bookNo;}
    Sales_data& combine(const Sales_data& crsd);
  private:
    /*
    ostream& do_disply(ostream& os){
      os << "bookNo=" << bookNo << " " << "units_sold=" << units_sold << " revenue=" << revenue;
      return os;
    }
    */
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& crsd){
  units_sold += crsd.units_sold;
  revenue += crsd.revenue;
  return (*this);
}
istream& read(istream& is, Sales_data& rsd){
  double price;
  is >> rsd.bookNo >> rsd.units_sold >> price;
  rsd.revenue = price*rsd.units_sold;
  return is;
}
ostream& print(ostream& os, const Sales_data& crsd){
  os << "bookNo=" << crsd.bookNo << " " << "units_sold=" << crsd.units_sold << " revenue=" << crsd.revenue;
}
int main(int argc, const char** argv){
  string fname(argv[1]);
  string foutname(argv[2]);
  cout << fname << endl;
  Sales_data total;         // variable to hold the running sum
  ifstream fin;
  ofstream fout;
  fin.open(fname);
  fout.open(foutname, ofstream::app);
  if(fin.is_open()){
    if (read(fin, total))  {  // read the first transaction
        Sales_data trans;     // variable to hold data for the next transaction
        while(read(fin, trans)) {      //  read the remaining transactions
            if (total.isbn() == trans.isbn())   // check the isbns
                total.combine(trans);  // update the running total
            else {
              if(fout){
                print(fout, total) << endl;  // print the results
                total = trans;               // process the next book
              }
            }
        }
        if(fout){
          print(fout, total) << endl;          // print the last transaction
        }
    } else {                                 // there was no input
        cerr << "No data?!" << endl;         // notify the user
    }
  } else 
    cerr << "Cannot find/open Input file: " << fname; 
  fin.close();
  fout.close();
}
```
```console
$ g++ ex8_8.cpp -o objectfile/ex8_8.o
$ ./objectfile/ex8_8.o ex8_6.txt ex8_8_cyc1.txt
ex8_6.txt
$ cat ex8_8_cyc1.txt 
bookNo=0-201-78345-X units_sold=5 revenue=110
bookNo=0-202-12345-X units_sold=7 revenue=106
bookNo=0-202-12347-X units_sold=1 revenue=60
bookNo=0-202-12346-X units_sold=7 revenue=21
$ ./objectfile/ex8_8.o ex8_6.txt ex8_8_cyc1.txt
ex8_6.txt
$ cat ex8_8_cyc1.txt 
bookNo=0-201-78345-X units_sold=5 revenue=110
bookNo=0-202-12345-X units_sold=7 revenue=106
bookNo=0-202-12347-X units_sold=1 revenue=60
bookNo=0-202-12346-X units_sold=7 revenue=21
bookNo=0-201-78345-X units_sold=5 revenue=110
bookNo=0-202-12345-X units_sold=7 revenue=106
bookNo=0-202-12347-X units_sold=1 revenue=60
bookNo=0-202-12346-X units_sold=7 revenue=21

```
# 8_9:
```cpp
$ cat ex8_9.cpp 
#include <string>
#include <iostream>
#include <sstream>
std::istream& f(std::istream& is){
  std::string inp;
  std::cout << std::endl;
  while(!is.eof()){
    is >> inp;
    std::cout << inp << " ";
  }
  is.clear();
  return is;
}
int main(){
  //f(std::cin);
  std::string line;
  while (std::getline(std::cin, line))
  {
    std::stringstream record(line);
    f(record);
  }
}
```
```console
$ ./objectfile/ex8_9.o
morgan 2015552368 8625550123
drew 9735550130
lee 6095550132 2015550175 8005550000
morgan 2015552368 8625550123 
drew 9735550130 
lee 6095550132 2015550175 8005550000
```

# 8_10:
```cpp
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
std::istream& f(std::istream& is){
  std::string inp;
  while(!is.eof()){
    is >> inp;
    std::cout << inp << " ";
  }
  is.clear();
  return is;
}
void line2vec(std::istream &cin, std::vector<std::string> &vec){
  std::string line;
  while(std::getline(cin, line)){
    vec.push_back(line);
  }
}
int main(int argc, char** argv){
  std::ifstream inputf(argv[1]);
  std::vector<std::string> output;
  line2vec(inputf, output);
  for(auto ite : output){
    std::stringstream record(ite);
    f(record);
    std::cout << "Done" <<  std::endl;
  }
}
```
```console
$ cat ex8_10.txt
morgan 2015552368 8625550123
drew 9735550130
lee 6095550132 2015550175 8005550000

$ ./objectfile/ex8_10.o ex8_10.txt
morgan 2015552368 8625550123 Done
drew 9735550130 Done
lee 6095550132 2015550175 8005550000 Done
```

# 8_11:
- ```cpprecord.clear();``` needs to be added because the operation `str()` does not work for the `sstream` with status `fail`.
```cpp
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
struct PersonInfo {
    string name;
    vector<string> phones;
};
int main(){
  string line, word;  // will hold a line and word from input, respectively
  vector<PersonInfo> people; // will hold all the records from the input
  // read the input a line at a time until cin hits end-of-file (or another error)
  istringstream record; // bind record to the line we just read
  while (getline(cin, line)) {
      PersonInfo info;      // create an object to hold this record's data
      record.clear();
      record.str(line);
      record >> info.name;  // read the name
      while (record >> word)        // read the phone numbers
          info.phones.push_back(word);  // and store them
      people.push_back(info); // append this record to people
     // cout <<  record.good() << "<-- good, " << record.eof() << "<-- eof, " << record.fail() << "<-- fail, " << record.bad() << "<-- bad";
  }
  cout << endl;
  for (auto APersonInfo : people){
    cout << "name:" << APersonInfo.name << ", phone:";
    for (auto Aphone : APersonInfo.phones)
      cout << Aphone << ", ";
    cout << endl;
  }
}
```
```console
$ ./objectfile/ex8_11.o
morgan 2015552368 8625550123
drew 9735550130
lee 6095550132 2015550175 8005550000
name:morgan, phone:2015552368, 8625550123, 
name:drew, phone:9735550130, 
name:lee, phone:6095550132, 2015550175, 8005550000,
```

# 8_12:
- We did not use in-class initializers in `PersonInfo` since its member needs to be filled with user input, and it does not really make sense to create certain default initial value for name and phone. Also, the length of vector phone is not known at initialization phase.


# 8_13:
```cpp
$ cat ex8_13.cpp
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
```
```console
$ cat ex8_10.txt
morgan 2015552368 8625550123
drew 9735550130
lee 6095550132 2015550175 8005550000

$ ./objectfile/ex8_13.o ex8_10.txt
morgan  2015552368 8625550123
drew  9735550130
lee  6095550132 2015550175 8005550000
```

# 8_14:
- [] `entry` and `nums` were declared as `const auto &` with two reasons.
- - Firstly, `const` is used because these objects are only read to have it pass its value to an `ostringstream&` object and not changed.
- - Secondly, `&` is used to prevent the `entry` and `nums` (`vectors`s) from being copied.	
```cpp
```
```console

```