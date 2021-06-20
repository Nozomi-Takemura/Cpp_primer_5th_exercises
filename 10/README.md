# 10_1:
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
int main(){
  std::vector<int> ivec;
  int i;
  std::cout << "type a series of integers: " << std::endl;
  while(std::cin >> i){
    ivec.push_back(i);
  }
  std::cout << "type the integer you want to count: " << std::endl;
  std::cin.clear();
  std::cin >> i;
  std::cout << "the integer " << i<< " appears " << count(ivec.begin(), ivec.end(), i) << " times." << std::endl;
}
```
```console
$ ./objectfile/ex10_1.o 
type a series of integers: 
1 2 3 4 5 1 2 3 41 2 3 4
type the integer you want to count: 
2
the integer 2 appears 3 times.
```

# 10_2:
```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using std::string;
int main(){
  std::list<string> ilist;
  string s;
  std::cout << "type a series of integers: " << std::endl;
  while(std::cin >> s){
    ilist.push_back(s);
  }
  std::cout << "type the integer you want to count: " << std::endl;
  std::cin.clear();
  std::cin >> s;
  std::cout << "the integer " << s<< " appears " << count(ilist.begin(), ilist.end(), s) << " times." << std::endl;
}
```
```console
$ ./objectfile/ex10_2.o 
type a series of integers: 
1 2 3 4 5 1 2 3 41 2 3 4
type the integer you want to count: 
3
the integer 3 appears 3 times.
```

# 10_3:
```cpp
#include<vector>
#include<iostream>
#include<numeric>
using std::vector;
using std::cin;
using std::cout;
using std::endl;//, std::accumulate;
int main(){
  vector<int> ivec;
  int i;
  cout << "type series of integers: " << endl;
  while(cin >> i)
    ivec.push_back(i);
  cout << "sum of the given integers is " << accumulate(ivec.cbegin(), ivec.cend(), 0) << "." << endl;
}
```
```console
$ ./objectfile/ex10_3.o 
type series of integers: 
1 2 3 4 5 1 2 3 41 2 3 4
sum of the given integers is 71.
```

# 10_4:
- Since the summation is done based on the type of the third argument `0`, the calculation precision below decimal points will be lost.
```cpp
#include<vector>
#include<iostream>
#include<numeric>
using std::vector;
using std::cin;
using std::cout;
using std::endl;//, std::accumulate;
int main(){
  vector<double> ivec;
  double i;
  cout << "type series of integers: " << endl;
  while(cin >> i)
    ivec.push_back(i);
  cout << "sum of the given integers 'accumulate(ivec.cbegin(), ivec.cend(), 0)' is " << accumulate(ivec.cbegin(), ivec.cend(), 0) << "." << endl;
  cout << "sum of the given integers 'accumulate(ivec.cbegin(), ivec.cend(), 0.0)' is " << accumulate(ivec.cbegin(), ivec.cend(), 0.0) << "." << endl;
}
```
```console
$ ./objectfile/ex10_4.o 
type series of integers: 
1 2 3 4 5 1 2 3 41 2 3 4.1
sum of the given integers 'accumulate(ivec.cbegin(), ivec.cend(), 0)' is 71.
sum of the given integers 'accumulate(ivec.cbegin(), ivec.cend(), 0.0)' is 71.1.
```

# [X]10_5:
- It would work without any issues as long as the identical `char []`s were passed. Note, however, `char []` is automatically converted to `char*` when the `char[]` is passed to the `equal` algorithm. Hence, the algorithm would compare two pointers to char. This means that even if two `char []`s consist the same elements, `equal` does not return `1` unless they indicate the identical memory space.
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<char*> roster1;
  vector<char*> roster2;
  int ifequal;
  char c[] = {'a', 'b'};
  char c2[] = {'a', 'b','c'};
  char c3[] = {'a', 'b','c'};
  roster1.push_back(c);
  roster2.push_back(c2);
  cout << roster1.at(0) << " vs " << roster2.at(0) << endl; 
  ifequal = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  cout << "c:{'a', 'b'}; and c2{'a', 'b','c'} equal?" << endl;
  cout << "ifequal: " << ifequal << endl;

  roster1.clear();
  roster2.clear();
  roster1.push_back(c3);
  roster2.push_back(c2);
  cout << "c3:" << roster1.at(0) << " vs " << "c2:" << roster2.at(0) << endl; 
  ifequal = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  cout << "c3{'a', 'b', 'c'}; and c2{'a', 'b','c'} equal?" << endl;
  cout << "ifequal: " << ifequal << endl;

  roster1.clear();
  roster2.clear();
  roster1.push_back(c2);
  roster2.push_back(c2);
  cout << "c2:" << roster1.at(0) << " vs " << "c2:" << roster2.at(0) << endl; 
  ifequal = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
  cout << "c2{'a', 'b', 'c'}; and c2{'a', 'b','c'} equal?" << endl;
  cout << "ifequal: " << ifequal << endl;
}
```
```console
$ ./objectfile/ex10_5.o 
ababcabc vs abcabc
c:{'a', 'b'}; and c2{'a', 'b','c'} equal?
ifequal: 0
c3:abc vs c2:abcabc
c3{'a', 'b', 'c'}; and c2{'a', 'b','c'} equal?
ifequal: 0
c2:abcabc vs c2:abcabc
c2{'a', 'b', 'c'}; and c2{'a', 'b','c'} equal?
ifequal: 1
```

# 10_6:
```cpp
#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
  cout << "original sequence: ";
  for(const int i : ivec){
    cout << i << " ";
  }
  cout << endl;
  cout << "after fill_n - sequence: ";
  fill_n(ivec.begin(), ivec.size(), 0);
  for(const int i : ivec){
    cout << i << " ";
  }
  cout << endl;
}
```
```console
$ ./objectfile/ex10_6.o 
original sequence: 1 2 3 4 5 6 7 8 9 10 
after fill_n - sequence: 0 0 0 0 0 0 0 0 0 0 
```
# 10_7:
---
- a. error: `copy` does not work because `lst` is not empty while `vec` is empty
```cpp
#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
int main(){
  vector<int> vec; list<int> lst; int i;
  while (cin >> i)
       lst.push_back(i);
  // this will raise an error
  // copy(lst.cbegin(), lst.cend(), vec.begin());
  copy(lst.cbegin(), lst.cend(), back_inserter(vec));
  cout << "works" << endl;
}
```
```console
$ ./objectfile/ex10_7_a.o 
1 2 3 4 5 6 7 8 9 0
works
```
---
- [X]b. no error: the 10 elemetns are reserved so, `fill_n` works.
- KEY1: `reserve` only allocates memory and it does not add any elements to the container.
- KEY2: `fill_n` requires the container with at least `n` elements.
```cpp
$ ./objectfile/ex10_7_b.o 
vec.reserve(10);
vec.resize(10);
0 0 0 0 0 0 0 0 0 0 
works
```
```console
#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> vec;
  vec.reserve(10); 
  cout << "vec.reserve(10);" << endl;
  for (const auto i : vec)
    cout << i << " ";
  cout << "vec.resize(10);" << endl;
  vec.resize(10); 
  for (const auto i : vec)
    cout << i << " ";
  fill_n(vec.begin(), 10, 0);
  cout << endl << "works" << endl;
}
```
---

# [X]10_8:
- `back_inserter` returns `back_insert_iterator` through which new element can be inserted to the end of a container with assignment operation. However, such assignment is implemented based on `push_back` member function of containers. Therefore, the algorithm `back_inserter` does not change the size of the containers, but their member function `push_back` does.
```cpp
```
```console
```

# 10_9:
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
ostream& svecprint(ostream& ros, const vector<string> &words ){
  for (const auto e : words){
    ros << e << " ";
  }
  return ros;
}
void elimDump(vector<string> &words){
  cout << "after read: ";
  svecprint(cout, words) << endl;
  sort(words.begin(), words.end());
  cout << "after sort: ";
  svecprint(cout, words) << endl;
  auto it = unique(words.begin(), words.end());
  cout << "after unique: ";
  svecprint(cout, words) << endl;
  words.erase(it, words.end());
  cout << "after erase: ";
  svecprint(cout, words) << endl;
}

int main(){
  vector<string> csvec{"dog","cat", "bird", "monkey", "dog","pigeon", "ticken","cat", "dog"};
  elimDump(csvec);
}
```
```console
$ ./objectfile/ex10_9.o 
after read: dog cat bird monkey dog pigeon ticken cat dog 
after sort: bird cat cat dog dog dog monkey pigeon ticken 
after unique: bird cat dog monkey pigeon ticken    
after erase: bird cat dog monkey pigeon ticken 
```

# 10_10:
- The `algorithms` take `iterators` and perform `operations` on them, not on the containers themselves. This implies that `algorithms` can change or read the elements of containers, but cannot add or remove them. 

# 10_11:
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
ostream& svecprint(ostream& ros, const vector<string> &words ){
  for (const auto e : words){
    ros << e << " ";
  }
  return ros;
}
inline bool isShorter(const string& s1, const string& s2){
 return (s1.size() < s2.size());
}
void elimDump(vector<string> &words,bool ifstablesort){
  cout << "after read: ";
  svecprint(cout, words) << endl;
  if(ifstablesort == true){
    stable_sort(words.begin(), words.end(), isShorter);
    cout << "after stable_sort: ";
  }
  else{
    sort(words.begin(), words.end());
    cout << "after sort: ";
  }
  svecprint(cout, words) << endl;
  auto it = unique(words.begin(), words.end());
  cout << "after unique: ";
  svecprint(cout, words) << endl;
  words.erase(it, words.end());
  cout << "after erase: ";
  svecprint(cout, words) << endl;
}

int main(){
  vector<string> csvec1{"dog","cat", "bird", "monkey", "dog","pigeon", "chicken","cat", "dog"};
  vector<string> csvec{"the","quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  vector<string> csvec2{"the","quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  cout << "-----Firtst apply normal elimDump based on normal sort:-----" << endl;
  elimDump(csvec, false);
  cout << "-----Additionaly, apply the elimDump based on stable_sort:-----" << endl;
  elimDump(csvec, true);
  cout << endl; 
  cout << "-----other example  :-----" << endl;
  elimDump(csvec1, false);
  elimDump(csvec1, true);
```
```console
$ ./objectfile/ex10_11.o 
-----Firtst apply normal elimDump based on normal sort:-----
after read: the quick red fox jumps over the slow red turtle 
after sort: fox jumps over quick red red slow the the turtle 
after unique: fox jumps over quick red slow the turtle the  
after erase: fox jumps over quick red slow the turtle 
-----Additionaly, apply the elimDump based on stable_sort:-----
after read: fox jumps over quick red slow the turtle 
after stable_sort: fox red the over slow jumps quick turtle 
after unique: fox red the over slow jumps quick turtle 
after erase: fox red the over slow jumps quick turtle 

-----other example  :-----
after read: dog cat bird monkey dog pigeon chicken cat dog 
after sort: bird cat cat chicken dog dog dog monkey pigeon 
after unique: bird cat chicken dog monkey pigeon dog   
after erase: bird cat chicken dog monkey pigeon 
after read: bird cat chicken dog monkey pigeon 
after stable_sort: cat dog bird monkey pigeon chicken 
after unique: cat dog bird monkey pigeon chicken 
after erase: cat dog bird monkey pigeon chicken 
```

# 10_12:
```cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Sales_data {
  public:
    Sales_data() = default;
    Sales_data(string argbk, unsigned argus, double argpr):bookNo(argbk), units_sold(argpr), revenue(argpr*argus)   {}
    inline string get_isbn() const{
      return bookNo;  
    }
    void display(){
      show();
    }
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    void show(){
      
    }
};
ostream& printSd(const Sales_data& rcsd, ostream& ros){
  ros << rcsd.get_isbn() << " ";
  return ros;
}
bool compareIsbn(const Sales_data& Sada1, const Sales_data& Sada2){
  const string isbn1 = Sada1.get_isbn();
  const string isbn2 = Sada2.get_isbn();
  return isbn1.size() < isbn2.size();
}

int main(){
 vector<Sales_data> vec{Sales_data("boo", 1, 2.5),Sales_data("book", 2, 3.5), Sales_data("boo", 1, 1.5)
   ,Sales_data("bookA", 1, 2.5), Sales_data("book", 2, 1.5), Sales_data("bookA", 1, 2.5)
   ,Sales_data("EnbookA",2, 4),Sales_data("GerbookA",3,5)};
 cout << "before sort - BookNumber of Sales_data in a vector: " << endl;
 for (const auto e : vec){
  printSd(e, cout);
 }
 cout << endl;
 sort(vec.begin(), vec.end(), compareIsbn);
 cout << "after sort - BookNumber of Sales_data in a vector: " << endl;
 for (const auto e : vec){
  printSd(e, cout); 
 }
 cout << endl;
}
```
```console
$ ./objectfile/ex10_12.o 
before sort - BookNumber of Sales_data in a vector: 
boo book boo bookA book bookA EnbookA GerbookA 
after sort - BookNumber of Sales_data in a vector: 
boo boo book book bookA bookA EnbookA GerbookA 
```

# 10_13:
```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline bool ifmorethanfive(const string& s1){
  return s1.size() >= 5;
}
int main(){
 vector<string> svec{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle"};
 vector<string>::iterator iter =  partition(svec.begin(), svec.end(), ifmorethanfive);
 cout << "original vector of words after partition: ";
 for (const auto e : svec){
  cout << e << " ";
 }
 cout << endl;
 cout << "the elements that have file or more chars: " << endl;
 for(decltype(iter) it = svec.begin(); it != iter; it++){
  cout << *it << " ";
 }
 cout << endl;
}
```
```console
$ ./objectfile/ex10_13.o 
original vector of words after partition: turtle quick jumps fox red over the slow red the 
the elements that have file or more chars: 
turtle quick jumps 
```

# 10_14:
```cpp
#include<iostream>
using namespace std;
int main(){
  auto lambda = [] (int i1, int i2) -> int {return i1+i2;};
  cout << " lambda expression: 1 + 5 = " << lambda(1,5) << endl;
}
```
```console
$ ./objectfile/ex10_14.o 
 lambda expression: 1 + 5 = 6
```

# 10_15:
```cpp
#include<iostream>
using namespace std;
int main(){
  const int ig = 10;
  auto lambda = [ig] (int i1, int i2) -> int {return i1+i2+ig;};
  cout << " lambda expression: 1 + 5 + 10(<- captured by enclosing function) = " << lambda(1,5) << endl;
}
```
```console
$ ./objectfile/ex10_15.o 
 lambda expression: 1 + 5 + 10(<- captured by enclosing function) = 16
```

# 10_16:
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto IteToOnePastUniEnd = unique(words.begin(), words.end());
  words.erase(IteToOnePastUniEnd, words.end());
}
inline string make_plural(string::size_type sz, const string &word, const string &ending){
  return (sz > 1)? word+ending : word;
}
void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = find_if(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() >= sz;});
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
int main(){
  vector<string> svec{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle"};
  cout << "input words: " << endl;
  for (const auto e : svec)
    cout << e << " ";
  cout << endl;
  biggies(svec, 5);
}
```
```console
$ ./objectfile/ex10_16.o 
input words: 
the quick red fox jumps over the slow red turtle 
3 words of length 5 or longer
jumps quick turtle 
```

# 10_17:
```cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Sales_data {
  public:
    Sales_data() = default;
    Sales_data(string argbk, unsigned argus, double argpr):bookNo(argbk), units_sold(argpr), revenue(argpr*argus)   {}
    inline string get_isbn() const{
      return bookNo;  
    }
    void display(){
      show();
    }
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    void show(){
      
    }
};
ostream& printSd(const Sales_data& rcsd, ostream& ros){
  ros << rcsd.get_isbn() << " ";
  return ros;
}
bool compareIsbn(const Sales_data& Sada1, const Sales_data& Sada2){
  const string isbn1 = Sada1.get_isbn();
  const string isbn2 = Sada2.get_isbn();
  return isbn1.size() < isbn2.size();
}

int main(){
 vector<Sales_data> vec{Sales_data("boo", 1, 2.5),Sales_data("book", 2, 3.5), Sales_data("boo", 1, 1.5)
   ,Sales_data("bookA", 1, 2.5), Sales_data("book", 2, 1.5), Sales_data("bookA", 1, 2.5)
   ,Sales_data("EnbookA",2, 4),Sales_data("GerbookA",3,5)};
 vector<Sales_data> vec2(vec);
 cout << "before sort - BookNumber of Sales_data in a vector: " << endl;
 for (const auto e : vec){
  printSd(e, cout);
 }
 cout << endl;
 sort(vec.begin(), vec.end(), compareIsbn);
 cout << "after sort - BookNumber of Sales_data in a vector: " << endl;
 for (const auto e : vec){
  printSd(e, cout); 
 }
 cout << endl;
 cout << "-- use lamda expression instead of compareIsbn function:  --" << endl;
 sort(vec2.begin(), vec2.end(), [] (const Sales_data &rcSD1, const Sales_data &rcSD2)
     -> bool {return rcSD1.get_isbn().size() < rcSD2.get_isbn().size();} );
 cout << "after sort - BookNumber of Sales_data in a vector: " << endl;
 for (const auto e : vec){
  printSd(e, cout); 
 }
 cout << endl;

}
```
```console
$ ./objectfile/ex10_17.o 
before sort - BookNumber of Sales_data in a vector: 
boo book boo bookA book bookA EnbookA GerbookA 
after sort - BookNumber of Sales_data in a vector: 
boo boo book book bookA bookA EnbookA GerbookA 
-- use lamda expression instead of compareIsbn function:  --
after sort - BookNumber of Sales_data in a vector: 
boo boo book book bookA bookA EnbookA GerbookA 
```

# 10_18:
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto IteToOnePastUniEnd = unique(words.begin(), words.end());
  words.erase(IteToOnePastUniEnd, words.end());
}
inline string make_plural(string::size_type sz, const string &word, const string &ending){
  return (sz > 1)? word+ending : word;
}
void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = find_if(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() >= sz;});
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
void biggiesPartition(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = partition(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() < sz;});
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
int main(){
  vector<string> svec{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle"};
  vector<string> svec2(svec);
  cout << "input words: " << endl;
  for (const auto e : svec)
    cout << e << " ";
  cout << endl;
  biggies(svec, 5);
  cout << "-- case: partition algorithm --" << endl;
  for (const auto e : svec2)
    cout << e << " ";
  cout << endl;
  biggiesPartition(svec2, 5);
}
```
```console
$ ./objectfile/ex10_18.o 
input words: 
the quick red fox jumps over the slow red turtle 
3 words of length 5 or longer
jumps quick turtle 
-- case: partition algorithm --
the quick red fox jumps over the slow red turtle 
3 words of length 5 or longer
jumps quick turtle 
```

# 10_19:
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto IteToOnePastUniEnd = unique(words.begin(), words.end());
  words.erase(IteToOnePastUniEnd, words.end());
}
inline string make_plural(string::size_type sz, const string &word, const string &ending){
  return (sz > 1)? word+ending : word;
}
void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = find_if(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() >= sz;});
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
void biggiesPartition(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  // for testing the effect of stable_partition, remove stable_sort
  // stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        // const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = partition(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() < sz;});
  cout << "## after partition algorithm ##: ";
  for (const auto &rcs : words)
    cout << rcs << " ";
  cout << endl;
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
void biggiesStablePartition(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  // for testing the effect of stable_partition, remove stable_sort
  // stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        // const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = stable_partition(words.begin(), words.end(),
      [sz] (const string &rcs) -> bool {return rcs.size() < sz;});
  cout << "## after stable_partition algorithm ##: ";
  for (const auto &rcs : words)
    cout << rcs << " ";
  cout << endl;
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
int main(){
  vector<string> svec{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle"};
  vector<string> svec2(svec);
  vector<string> svec3(svec);
  cout << "input words: " << endl;
  for (const auto e : svec)
    cout << e << " ";
  cout << endl;
  biggies(svec, 5);
  // use partition algorithm instead
  cout << "-- case: partition algorithm --" << endl;
  for (const auto e : svec2)
    cout << e << " ";
  cout << endl;
  biggiesPartition(svec2, 5);
  // use stable_partition algorithm instead
  cout << "-- case: partition algorithm --" << endl;
  for (const auto e : svec3)
    cout << e << " ";
  cout << endl;
  biggiesStablePartition(svec3, 5);
}
```
```console
0$ ./objectfile/ex10_19.o 
input words: 
the quick red fox jumps over the slow red turtle 
3 words of length 5 or longer
jumps quick turtle 
-- case: partition algorithm --
the quick red fox jumps over the slow red turtle 
## after partition algorithm ##: fox the over slow red quick jumps turtle 
3 words of length 5 or longer
quick jumps turtle 
-- case: partition algorithm --
the quick red fox jumps over the slow red turtle 
## after stable_partition algorithm ##: fox over red slow the jumps quick turtle 
3 words of length 5 or longer
jumps quick turtle 
```

# 10_20:
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<string> words{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle", "peanuts"};
  auto count = count_if(words.begin(), words.end(), [] (const string &word) 
      -> bool {return word.size()>6? true : false;});
  cout << "input words vector: " << endl;
  for (const auto & rcstr : words)
    cout << rcstr << " ";
  cout << endl;
  cout << count << (count>1? " words ": " word ") << "of length greater than " << 6 <<  endl;
}
```
```console
$ ./objectfile/ex10_20.o 
input words vector: 
the quick red fox jumps over the slow red turtle peanuts 
1 word of length greater than 6
```

# 10_21:
```cpp
#include<iostream>
using namespace std;
int main(){
  int i = 10;
  bool tof;
  auto lambda = [&i] () -> bool {
    if (i>0){
      --i;
      return (i==0);
    }
    else if (i == 0)
      return (i==0); 
  };
  cout << "while (!lambda()) for int=10:" << endl;
  cout << "chnages of (i,lambda())  per iteration: " << endl;
  while(!(tof=lambda()))
    cout << "(" << i << ", " << tof  <<  "), ";
  cout << endl;
  cout << "after while (!lambda()) loop" << endl;
  cout << "(" << i << ", " << tof  <<  "), ";
  cout << endl;
}
```
```console
$ ./objectfile/ex10_21.o 
while (!lambda()) for int=10:
chnages of (i,lambda())  per iteration: 
(9, 0), (8, 0), (7, 0), (6, 0), (5, 0), (4, 0), (3, 0), (2, 0), (1, 0), 
after while (!lambda()) loop
(0, 1), 
```

# 10_22:
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using std::placeholders::_1;
inline bool ifstrlen(const string &rcs, const string::size_type sz){
  return rcs.size() <= sz;
}
int main(){
  vector<string> words{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle", "peanuts"};
  auto count = count_if(words.begin(), words.end(), bind(ifstrlen, _1, 6));
  cout << "input words vector: " << endl;
  for (const auto & rcstr : words)
    cout << rcstr << " ";
  cout << endl;
  cout << count << (count>1? " words ": " word ") << "of length equal to or less than " << 6 <<  endl;
}
```
```console
$ ./objectfile/ex10_22.o 
input words vector: 
the quick red fox jumps over the slow red turtle peanuts 
10 words of length equal to or less than 6
```

# 10_23:
- `bind` takes `n+1` aruguments, where `n` is the number of arguments passed to the callable function passed to `bind` to its first parameter. 

# 10_24:
```cpp
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz){
  return s.size() >= sz;
}
int main(){
  const vector<int> civec{2,4,6,8,10,12};
  const string cs("Inputstr");  
  auto itefirele = find_if_not(civec.begin(), civec.end(), bind(check_size, cs, _1));
  cout << "input vector<int>: ";
  for (const auto ci : civec)
    cout << ci << " ";
  cout << endl << "input string: " << cs << endl;
  cout << "the first element in a vector of ints that has a value greater than the length of a specified string value: " << *itefirele << endl;
}
```
```console
$ ./objectfile/ex10_24.o 
input vector<int>: 2 4 6 8 10 12 
input string: Inputstr
the first element in a vector of ints that has a value greater than the length of a specified string value: 10
```

# 10_25:
```cpp
#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using std::placeholders::_1;
void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto IteToOnePastUniEnd = unique(words.begin(), words.end());
  words.erase(IteToOnePastUniEnd, words.end());
}
inline string make_plural(string::size_type sz, const string &word, const string &ending){
  return (sz > 1)? word+ending : word;
}
inline bool check_size(const string &s, string::size_type sz){
  return s.size() >= sz;
}
inline bool isShorter(const string &s1, const string &s2){
  return s1.size() < s2.size();
}
void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words);
  stable_sort(words.begin(), words.end(), isShorter);
  // for testing the effect of stable_partition, remove stable_sort
  // stable_sort(words.begin(), words.end(), [] (const string& rcs1,
        // const string& rcs2) -> bool {return rcs1.size() < rcs2.size();});
  auto IteFirstWordOfSz = find_if(words.begin(), words.end(),
      bind(check_size,_1,sz));
      
  cout << "## after bind(check_size,-1,sz) parts: ";
  for (const auto &rcs : words)
    cout << rcs << " ";
  cout << endl;
  auto CountMoreThanSz = words.end() - IteFirstWordOfSz;
  cout << CountMoreThanSz << " " << make_plural(CountMoreThanSz, "word", "s")
    << " of length " << sz << " or longer" << endl;
  for_each(IteFirstWordOfSz, words.end(), [] (const string & rcs)
      -> void {cout << rcs << " ";});
  cout << endl;
}
int main(){
  vector<string> svec{"the","quick", "red", "fox",
   "jumps", "over", "the", "slow", "red", "turtle"};
  cout << "input words: " << endl;
  for (const auto e : svec)
    cout << e << " ";
  cout << endl;
  biggies(svec, 5);
}
```
```console
$ ./objectfile/ex10_25.o 
input words: 
the quick red fox jumps over the slow red turtle 
## after bind(check_size,-1,sz) parts: fox red the over slow jumps quick turtle 
3 words of length 5 or longer
jumps quick turtle 
```

# [X]10_26:
- `back inserter` iterator: an iterator to insert its `assigned` value to the container by calling `push_back`.
- `inserter` iterator: an iterator to insert its `assigned` value to the container by calling `insert` operation of the container. In other words, an iterator of the container needs to be fed as an argument when a `inserter` is created, and the `assigned` value to the `inserter` is inserted just ahead of the element which the `iterator` passed as the argument points to. 
- `front_inserter` iterator:  an iterator to insert its `assigned` value to the beginning of container by calling `push_front`

# 10_27:
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  const vector<int> civec{1,2,3,4,5,6,7,8,9,2,2,3,3,4,4};  
  vector<int> ivec{1,2,3,4,5,6,7,8,9,2,2,3,3,4,4};  
  vector<int> ivec2;
  vector<int> ivec3;
  unique_copy(civec.cbegin(), civec.cend(), back_inserter(ivec2));
  cout << "original input vector<int>: ";
  for(const auto ci : civec)
    cout << ci << " ";
  cout << endl;
  cout << "only unique_copy - copied vector: ";
  for(const auto ci : ivec2)
    cout << ci << " ";
  cout << endl;
  sort(ivec.begin(), ivec.end());
  unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ivec3));
  cout << "sort + unique_copy - copied vector: ";
  for(const auto ci : ivec3)
    cout << ci << " ";
  cout << endl;
}
```
```console
$ ./objectfile/ex10_27.o 
original input vector<int>: 1 2 3 4 5 6 7 8 9 2 2 3 3 4 4 
only unique_copy - copied vector: 1 2 3 4 5 6 7 8 9 2 3 4 
sort + unique_copy - copied vector: 1 2 3 4 5 6 7 8 9 
```

# 10_28:
- suppose the original `container` contains `1,2,3,4,5,6,7,8,9` and the target `container` contains `10,20,30`.
- - after `back_inserter`: `10,20,30,1,2,3,4,5,6,7,8,9` 
- - after `front_inserter`: `9,8,7,6,5,4,3,2,1,10,20,30`
- - after `inserter(*tar_con*,*inter_to_middle*`: `10,9,8,7,6,5,4,3,2,1,20,30`
```cpp
$ cat ex10_28.cpp
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
template<typename T>
ostream& vprint(const T civec, ostream &ros){
  for (const auto ci : civec)
    ros << ci << " ";
  return ros;
}
int main(){
  const vector<int> civec{1,2,3,4,5,6,7,8,9};  
  vector<int> ivec{10,20,30};
  vector<int> ivec2{10,20,30};
  list<int> ivec3{10,20,30};
  vector<int>::iterator iter = ivec2.begin() + 1;
  cout << "original input vector<int>: ";
  vprint(civec,cout) << endl;
  cout << "original target vector<int>: ";
  vprint(ivec,cout) << endl;
  cout << "back_inserter: " << endl; 
  copy(civec.cbegin(), civec.cend(), back_inserter(ivec));
  cout << "target vector<int> -back_inserter - " << endl;
  vprint(ivec,cout) << endl;
  cout << "front_inserter: " << endl; 
  copy(civec.cbegin(), civec.cend(), front_inserter(ivec3));
  cout << "target vector<int> -front_inserter - " << endl;
  vprint(ivec3,cout) << endl;
  cout << "inserter(): " << endl; 
  copy(civec.cbegin(), civec.cend(), inserter(ivec2,iter));
  cout << "target vector<int> -inserter() - " << endl;
  vprint(ivec2,cout) << endl;
}
```
```console
$ ./objectfile/ex10_28.o 
original input vector<int>: 1 2 3 4 5 6 7 8 9 
original target vector<int>: 10 20 30 
back_inserter: 
target vector<int> -back_inserter - 
10 20 30 1 2 3 4 5 6 7 8 9 
front_inserter: 
target vector<int> -front_inserter - 
9 8 7 6 5 4 3 2 1 10 20 30 
inserter(): 
target vector<int> -inserter() - 
10 1 2 3 4 5 6 7 8 9 20 30 
```

# 10_29:
```cpp
#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<string>
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ostream_iterator;
using std::istream_iterator;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
// using namespace std;

int main(int argc, char** argv){
  // vector<string> svec;
  if(argc>1){
    ifstream fin (argv[1], ifstream::in);
    ostream_iterator<string> out(cout, " ");
    istream_iterator<string> initer(fin), end;
    vector<string> svec(initer, end);
    // copy(initer, end, back_inserter(svec));
    for (const auto &rcstr : svec)
      *out++ = rcstr;
    cout << endl;
  }else{
    cerr << "there are no input file." << endl;
  }

} 
```
```console
$ ./objectfile/ex10_29.o ex10_29.txt 
Socrates greek philosopher quotes: “The only true wisdom is in knowing you know nothing.” ... “The unexamined life is not worth living.” ... “I cannot teach anybody anything. ... “There is only one good, knowledge, and one evil, ignorance.” ... “Be kind, for everyone you meet is fighting a hard battle.” ... “Wonder is the beginning of wisdom.” 
```

# 10_30:
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
 istream_iterator<int> is_iter(cin), end;
 ostream_iterator<int> os_iter(cout, " ");
 vector<int> ivec; 
 copy(is_iter, end, back_inserter(ivec));
 sort(ivec.begin(), ivec.end());
 copy(ivec.begin(), ivec.end(), os_iter);
 cout << endl;
}
```
```console
$ ./objectfile/ex10_30.o 
10 9 8 7 6 5 4 11 3 12 1 13 0  
0 1 3 4 5 6 7 8 9 10 11 12 13 
```

# 10_31:
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
 istream_iterator<int> is_iter(cin), end;
 ostream_iterator<int> os_iter(cout, " ");
 vector<int> ivec; 
 copy(is_iter, end, back_inserter(ivec));
 sort(ivec.begin(), ivec.end());
 cout << "just after unique_copy: " << endl;
 unique_copy(ivec.begin(), ivec.end(), os_iter);
 cout << endl;
}
```
```console
$ ./objectfile/ex10_31.o 
10 9 10 9 8 7 6 8 7 6 
just after unique_copy: 
6 7 8 9 10 
```

# 10_32:
- `ex10_32.cpp`
```cpp
#include<iostream>
// #include<Sales_item.h>
#include<my_Sales_Item.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
using std::placeholders::_1;
using namespace std;
inline bool comparison(const Sales_item &rc_sal_ite1, const Sales_item &rc_sal_ite2){
  return rc_sal_ite1.isbn().size() < rc_sal_ite2.isbn().size();
  // return rc_sal_ite1.get_isbn().size() < rc_sal_ite2.get_isbn().size();
}
inline bool if_str_larger_than(const Sales_item &rc_sal_ite1, const Sales_item &rc_sal_ite2){
  return  rc_sal_ite1.isbn() < rc_sal_ite2.isbn();
  // for(const auto c : rc_sal_ite1)
}
inline bool differentisbn(const Sales_item &rc_sal_ite, const string &rcs){
  return rcs.compare(rc_sal_ite.isbn());
  // return rc_sal_ite.isbn() != rcs;
}
int main(){
 //read all Sales_item into vector<Sales_item> 
 istream_iterator<Sales_item> is_ite(cin), end;
 ostream_iterator<Sales_item> os_ite(cout, "\n");
 vector<Sales_item> v_sal_ite(is_ite, end);
 vector<Sales_item> v_sal_ite2;
 vector<Sales_item>::iterator pre_ite;
 vector<Sales_item>::iterator ite_at_new_bookNo;
 vector<string> v_bookNo;
 Sales_item sum_sal_ite;
 // print initial input
 cout << "-----input vector: -------" << endl;
 copy(v_sal_ite.cbegin(), v_sal_ite.cend(), os_ite);
 cout << endl;
 //sort the vector
 sort(v_sal_ite.begin(), v_sal_ite.end(), if_str_larger_than);
 //create new vector with unique bookNo
 unique_copy(v_sal_ite.cbegin(), v_sal_ite.cend(), back_inserter(v_sal_ite2),
     [] (const Sales_item &rc_sal_ite1, const Sales_item &rc_sal_ite2) 
     -> bool {rc_sal_ite1.if_bookNo_same(rc_sal_ite2);});
 //for each unique bookNo, calculate the sum of the revenue
 cout << "vector after preprocessing: " << endl;
 copy(v_sal_ite.cbegin(), v_sal_ite.cend(), os_ite);
 cout << endl;
 pre_ite = v_sal_ite.begin(); 
 for (const auto &rc_one_of_sal_ite2 : v_sal_ite2){
  sum_sal_ite = Sales_item(rc_one_of_sal_ite2.isbn());
  cout << "---- This is one of the unique bookNo: " << rc_one_of_sal_ite2.isbn() << " ----"<< endl;
  cout << "*pre_ite - " << *pre_ite << endl;
  ite_at_new_bookNo = find_if(pre_ite, v_sal_ite.end(), bind(differentisbn, _1,
        rc_one_of_sal_ite2.isbn()));
  // calculate sum so long as there's new bookNo record
  if(ite_at_new_bookNo != v_sal_ite.end()){
    cout << "*new_ite - " << *ite_at_new_bookNo << endl;
    cout << (pre_ite->isbn() == ite_at_new_bookNo->isbn()) << "<- if 1 then isbns are the same "<< endl;
    // write to the output stream
    cout << "new bookNo: " << (ite_at_new_bookNo->isbn()) << endl;
    *os_ite++ = accumulate(pre_ite,ite_at_new_bookNo , sum_sal_ite);
    cout << endl;
    // set the pre_ite to the current bookNo to calculate sum of Sales_item for next bookNo
    pre_ite = ite_at_new_bookNo;
    cout << "sum-test: " <<  accumulate(pre_ite,ite_at_new_bookNo, sum_sal_ite) << endl;
   }
 }
 cout << endl;
 // the summation for the final record still needs to be computed
 cout << "last bookNo: " << (sum_sal_ite.isbn()) << endl;
 *os_ite++ = accumulate(pre_ite,v_sal_ite.end(), sum_sal_ite);
 cout << endl;
}
```
- `my_Sales_Item.h`
```cpp
#ifndef MY_SALES_ITEM_H
#define MY_SALES_ITEM_h 
#include<iostream>
#include<string>
using namespace std;
class Sales_item {
  public:
    double price;
    Sales_item() = default;
    // this constructor is required to clean revenue and avg_price with new bookNo
    Sales_item(const string c_bookNo): bookNo(c_bookNo) {}
    Sales_item(istream &ris) {
      // double price;
      ris >> (this->bookNo) >> (this->units_sold) >> price;
      revenue = price*units_sold;
      ave_price = revenue/units_sold;
    }
    inline string isbn() const {return bookNo;};
    inline int get_units_sold() const {return units_sold;};
    inline double get_revenue() const {return revenue;};
    inline double get_ave_price() const {return ave_price;};
    bool if_bookNo_same (const Sales_item&) const;
    // bool if_bookNo_same() const;
    friend ostream & operator<<(ostream &, const Sales_item &);
    friend istream & operator>>(istream &, Sales_item &);
    // summation should be done between two Sales_items so no 'friend' is necessary
    Sales_item& operator+(const Sales_item &rc_sal_ite){
      //assume the bookNo is the same
      this->bookNo = rc_sal_ite.bookNo;
      this->units_sold += rc_sal_ite.units_sold;
      this->revenue += rc_sal_ite.revenue;
      this->ave_price = (this->revenue)/(this->units_sold);
      return *this;
    }
    // != will be used inside accumulate so needs to be defined
    // comparison needs to be done only for Sales_item type so no 'friend' is necessary
    inline bool operator!=(const Sales_item& rhs){
      return this->isbn().compare(rhs.isbn());
    }
    // assignment = operator is also mandatory for accumulate
    // it is supposed that two Sales_items are the same if their bookNo are the same
    // inline Sales_item& operator=(const Sales_item& rhs){
      // this->bookNo = rhs.isbn();
      // this->units_sold = rhs.get_units_sold();
      // this->revenue = rhs.get_revenue();
      // this->ave_price = rhs.get_ave_price();
      // return *this;
    // }
  private:
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
    double ave_price = 0.0;
};
bool Sales_item::if_bookNo_same(const Sales_item &rc_sal_ite) const{
  return !(this->bookNo).compare(rc_sal_ite.isbn()); 
}

ostream & operator<<(ostream & ros, const Sales_item &rc_sal_ite){
  ros << "bookNo: " << rc_sal_ite.isbn() << ", units_sold: " 
    << rc_sal_ite.get_units_sold() << ", revenue: "
    << rc_sal_ite.get_revenue() << ", ave_price: " << rc_sal_ite.get_ave_price();
  return ros;
}
istream & operator>>(istream & ris, Sales_item &r_sal_ite){
  ris >> r_sal_ite.bookNo >> r_sal_ite.units_sold >> r_sal_ite.price; 
  r_sal_ite.revenue = r_sal_ite.price*r_sal_ite.units_sold;
  r_sal_ite.ave_price = r_sal_ite.revenue/r_sal_ite.units_sold;
  return ris;
}
#endif
```
```console
$ g++ ex10_32.cpp -I ~/Cpp_primer_5th_exercises/10 -o  objectfile/ex10_32.o
$ ./objectfile/ex10_32.o
a-201-70353-X 4 10.5 
b-201-70353-X 5 20.5 
a-201-70353-X 4 30.5 
b-201-70353-X 3 40.5 
c-201-70353-X 1 10.5 
c-201-70353-X 1 20.5 
a-201-70353-X 4 30.5 
c-201-70353-X 1 40.5 
-----input vector: -------
bookNo: a-201-70353-X, units_sold: 4, revenue: 42, ave_price: 10.5
bookNo: b-201-70353-X, units_sold: 5, revenue: 102.5, ave_price: 20.5
bookNo: a-201-70353-X, units_sold: 4, revenue: 122, ave_price: 30.5
bookNo: b-201-70353-X, units_sold: 3, revenue: 121.5, ave_price: 40.5
bookNo: c-201-70353-X, units_sold: 1, revenue: 10.5, ave_price: 10.5
bookNo: c-201-70353-X, units_sold: 1, revenue: 20.5, ave_price: 20.5
bookNo: a-201-70353-X, units_sold: 4, revenue: 122, ave_price: 30.5
bookNo: c-201-70353-X, units_sold: 1, revenue: 40.5, ave_price: 40.5

vector after preprocessing: 
bookNo: a-201-70353-X, units_sold: 4, revenue: 42, ave_price: 10.5
bookNo: a-201-70353-X, units_sold: 4, revenue: 122, ave_price: 30.5
bookNo: a-201-70353-X, units_sold: 4, revenue: 122, ave_price: 30.5
bookNo: b-201-70353-X, units_sold: 5, revenue: 102.5, ave_price: 20.5
bookNo: b-201-70353-X, units_sold: 3, revenue: 121.5, ave_price: 40.5
bookNo: c-201-70353-X, units_sold: 1, revenue: 10.5, ave_price: 10.5
bookNo: c-201-70353-X, units_sold: 1, revenue: 20.5, ave_price: 20.5
bookNo: c-201-70353-X, units_sold: 1, revenue: 40.5, ave_price: 40.5

---- This is one of the unique bookNo: a-201-70353-X ----
*pre_ite - bookNo: a-201-70353-X, units_sold: 4, revenue: 42, ave_price: 10.5
*new_ite - bookNo: b-201-70353-X, units_sold: 5, revenue: 102.5, ave_price: 20.5
0<- if 1 then isbns are the same 
new bookNo: b-201-70353-X
bookNo: a-201-70353-X, units_sold: 12, revenue: 286, ave_price: 23.8333

sum-test: bookNo: a-201-70353-X, units_sold: 0, revenue: 0, ave_price: 0
---- This is one of the unique bookNo: b-201-70353-X ----
*pre_ite - bookNo: b-201-70353-X, units_sold: 5, revenue: 102.5, ave_price: 20.5
*new_ite - bookNo: c-201-70353-X, units_sold: 1, revenue: 10.5, ave_price: 10.5
0<- if 1 then isbns are the same 
new bookNo: c-201-70353-X
bookNo: b-201-70353-X, units_sold: 8, revenue: 224, ave_price: 28

sum-test: bookNo: b-201-70353-X, units_sold: 0, revenue: 0, ave_price: 0
---- This is one of the unique bookNo: c-201-70353-X ----
*pre_ite - bookNo: c-201-70353-X, units_sold: 1, revenue: 10.5, ave_price: 10.5

last bookNo: c-201-70353-X
bookNo: c-201-70353-X, units_sold: 3, revenue: 71.5, ave_price: 23.8333
```

# 10_33:
```cpp
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;
int main(int argc, char** argv){
  ifstream fin(argv[1], ifstream::in);
  ofstream fop_odd(argv[2], ofstream::out);
  ofstream fop_even(argv[3], ofstream::out);
  istream_iterator<int> in_ite(fin), end;
  ostream_iterator<int> op_ite_odd(fop_odd, "\n");
  ostream_iterator<int> op_ite_even(fop_even, "\n");
  for(auto iter = in_ite; iter!= end; ++iter){
    (*iter%2)? *op_ite_odd++ = *iter : *op_ite_even++ = *iter; 
  }
  // copy_if(in_ite, end, op_ite_odd, [] (const int i) -> bool {return i%2;});
  // copy_if(in_ite, end, op_ite_even, [] (const int i) -> bool {return !(i%2);});
}
```
```console
$ ./objectfile/ex10_33.o ex10_33_input.txt ex10_33_out1_odd.txt ex10_33_out2_even.txt

$ cat ex10_33_input.txt 
1 2 3 4 5 6 7 8 9 10 12 13 15 17 19 20

$ cat ex10_33_out1_odd.txt 
1
3
5
7
9
13
15
17
19

$ cat ex10_33_out2_even.txt 
2
4
6
8
10
12
20
```

# 10_34:
```cpp
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main(){
  const vector<int> c_ivec{1,2,3,4,5,6,7,8,9,10};
  ostream_iterator<int> op_ite(cout, " ");
  cout << "original vector<int>: ";
  for(const auto i : c_ivec)
    cout << i << " ";
  cout << endl << "vector<int> in reverse order: ";
  copy(c_ivec.crbegin(), c_ivec.crend(), op_ite);
  cout << endl;
}
```
```console
$ ./objectfile/ex10_34.o
original vector<int>: 1 2 3 4 5 6 7 8 9 10 
vector<int> in reverse order: 10 9 8 7 6 5 4 3 2 1
```

# 10_35:
```cpp
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main(){
  const vector<int> c_ivec{1,2,3,4,5,6,7,8,9,10};
  ostream_iterator<int> op_ite(cout, " ");
  cout << "original vector<int>: ";
  for(const auto i : c_ivec)
    cout << i << " ";
  cout << endl << "vector<int> in reverse order: ";
  for(auto i = c_ivec.end(); i!=c_ivec.begin();){
    --i;
    cout << *i << " ";
  }
  // copy(c_ivec.crbegin(), c_ivec.crend(), op_ite);
  cout << endl;
}
```
```console
$ ./objectfile/ex10_35.o
original vector<int>: 1 2 3 4 5 6 7 8 9 10 
vector<int> in reverse order: 10 9 8 7 6 5 4 3 2 1 
```

# 10_36:
```cpp
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
  const list<int> c_ilist{1,0,3,4,0,6,7,0,9,11};
  ostream_iterator<int> op_ite(cout, " ");
  cout << "original vector<int>: ";
  for(const auto i : c_ilist)
    cout << i << " ";
  cout << endl << "list<int> in reverse order: ";
  copy(c_ilist.crbegin(), c_ilist.crend(), op_ite);
  cout << endl;
  // find the last element with value 0
  auto rite_bef_last_zero = find(c_ilist.crbegin(), c_ilist.crend(), 0);
  if(rite_bef_last_zero != c_ilist.crend()){
    cout << "(distance(rite_bef_last_zero,c_ilist.crend())) - the last 0 is found at " << (distance(rite_bef_last_zero,c_ilist.crend()))  << "th element." <<  endl;
  }
}
```
```console
$ ./objectfile/ex10_36.o
original vector<int>: 1 0 3 4 0 6 7 0 9 11 
list<int> in reverse order: 11 9 0 7 6 0 4 3 0 1 
(distance(rite_bef_last_zero,c_ilist.crend())) - the last 0 is found at 8th element.
```

# 10_37:
```cpp
#include<vector>
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main() {
  const vector<int> c_ivec{1,2,3,4,5,6,7,8,9,10};
  list<int> ilist;
  ostream_iterator<int> op_ite(cout, " ");
  copy(c_ivec.crbegin()+3, c_ivec.crend()-2, back_inserter(ilist));
  cout << "original input vec: ";
  copy(c_ivec.cbegin(), c_ivec.cend(), op_ite);
  cout << endl << "elements at position between 3 and 7 in reverse order: " << endl;
  copy(ilist.cbegin(), ilist.cend(), op_ite);
  cout << endl;
}
```
```console
$ ./objectfile/ex10_37.o
original input vec: 1 2 3 4 5 6 7 8 9 10 
elements at position between 3 and 7 in reverse order: 
7 6 5 4 3
```

# 10_38:
- `Input iterator`: operators, `==`, `!=`, `++`, `*`(maybe onlyon right hand side), `->`
- `Output iterator`: `++`(both prefix and postfix), `*`(maybe only on left hand side)
- `Forward iterator`: `==`, `!=`, `++`(both prefix and postfix), `*`(both left and right hand sides)
- `Bidirectional iterator`: `==`, `!=`, `++`(both prefix and postfix), `*`(both left and right hand sides), '--'(both prefix and postfix)
- `Random-access iterator`: `==`, `!=`, `++`(both prefix and postfix), `*`(both left and right hand sides), '--'(both prefix and postfix)
 - `<`, `<=`, `>`, `>=`
 - `+`, `+=`, `-`, `-=` on an `iterator` and an `integral` value
 - `-` gives the distance between two iterators when it is applied for them
 - `[n]` is the same operation as `*(iter + n)`

# 10_39:
- `list`: Bidirectional iterator (because its elements )
- `vector`: Random-access iterator 
 - This is because that a vector reserve a continuous memory spaces, and therefore random-access is possible via its iterator. 
```cpp
```
```console
```

# [X]10_40:
- `copy` requires iterators:
 - `Input iterator`s - first and second argumens
 - `Output iterator` - third argument. This is because `copy` needs to pass `iterator`, and then internally dereference the `iterator` (left hand side) and then assign source value to the dereferenced variable.
- `reverse` requires iterators:
 - (two) `Bidirectional iterator`
  - Why: reversing implies `swap`ing the values. This means that `*` (both left and right hand sides) is required given two input `iterators`. Furthermore, after each iteration of swap between `begin` and `end` pointed by each `iterator`, they need to be increased`++`/decreased(--). Thus, `Bidirectional iterator` is required as `reverse`'s arguments. 
- `unique` requires iterators:
 - `ForwardIterator`
  - the implementation logic for `unique` requires basically moving bothe of the input iterators forward and possibly overwriting their elements; however, there is no need to move the iterator backward via `--`.

# 10_41:
- `replace(beg, end, old_val, new_val);`
 - operation: replace all the `old_val` appearing between the range `[beg, end)` with `new_val`
- `replace_if(beg, end, pred, new_val);`
 - operation: replace all the elements for which the predicate `pred` returns `true` with `new_val` between the range specified by the iterators `[beg, end)`
- `replace_copy(beg, end, dest, old_val, new_val);`
 - operation: copy(insert) the elements of a container in a range `[beg,end)` into the element pointed by `dest` of a new container replacing all the `old_val` with `new_val` 
- `replace_copy_if(beg, end, dest, pred, new_val);`
 - copy(insert) the elements of a container in a range `[beg, end)` at the location specified by `dest` of another container replacing each element with `new_val` if `pred` returns `true`

# 10_42:
```cpp
#include<string>
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void elimDumps(list<string> &words){
  ostream_iterator<string> op_ite(cout, " ");
  cout << "original input: ";
  copy(words.cbegin(), words.cend(), op_ite);
  cout << endl;
  words.sort();
  words.unique();
  cout << "after sort+unique: ";
  copy(words.cbegin(), words.cend(), op_ite);
  cout << endl;
}
int main(){
  istream_iterator<string> ip_ite(cin), end;
  list<string> words;
  copy(ip_ite, end, back_inserter(words));
  elimDumps(words);
}
```
```console
$ ./objectfile/ex10_42.o
the quick red fox jumps over the slow red turtle
original input: the quick red fox jumps over the slow red turtle 
after sort+unique: fox jumps over quick red slow the turtle 
```