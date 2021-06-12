# 9_1:
- [] a.  `list` is the most appropriate because insertion can occur in the middle of the containers. --However, since only a fixed number of words needs to be read, `array` would be more appropriate.--
- [X] b. `deque` is the most appropriate because it supports the fast insertion at the back and delection at the front of the container.
- [] c. there are no specific preferences because all three types of containers can be used by leveraging the generic function `sort`. --When printing the contents of the containers to standard output, random access is not mandatory.--

# 9_2:
```cpp
$ cat ex9_2.cpp 
#include<vector>
#include<list>
#include<deque>
#include<iostream>
int main(){
  std::list<std::deque<int>> listofdequeofint = {{1,2}};
  for(auto dequeofint : listofdequeofint){
    for(auto i : dequeofint)
      std::cout << "- " << i;
  }
  std::cout << std::endl;
}
```
```console
$ ./objectfile/ex9_2.o 
- 1- 2
```

# 9_3:
- The constraints on the iterators forming iterator ranges are as follows:
- - [X] the iterators must refer to the elements of a container or one past the last element.
- - the last element can be reached by increasing the preceding iterator.
- - the range is left-inclusive. 
```cpp
```
```console
```

# 9_4:
```cpp
$ cat ex9_4.cpp 
#include<vector>
#include<iostream>
using namespace std;
bool f(vector<int>::iterator beg, const vector<int>::iterator end, const int cint){
  while(beg != end){
    if(*beg == cint)
      return true;
    ++beg;
  }
  return false;
}
int main(){
  int uint;
  vector<int> vinput = {1,2,3,4,5,6,7,8,9};
  cout << "type an integer between 1 and 9" << endl;
  if(cin >> uint){
    cout << "ok" << endl;
    cout << "if " << uint << " exists within {1,2,3,4,5,6,7,8,9}? " <<  f(vinput.begin(), vinput.end(), uint) << endl;
  }
}
```
```console
$ ./objectfile/ex9_4.o 
type an integer between 1 and 9
10
ok
if 10 exists within {1,2,3,4,5,6,7,8,9}? 0
$ ./objectfile/ex9_4.o 
type an integer between 1 and 9
3
ok
if 3 exists within {1,2,3,4,5,6,7,8,9}? 1
```

# 9_5:
```cpp
#include<vector>
#include<iostream>
using namespace std;
vector<int>::iterator f(vector<int>::iterator beg, const vector<int>::iterator end, const int cint){
  vector<int>::iterator res;
  while(beg != end){
    if(*beg == cint)
      return beg;
    ++beg;
  }
    return beg;
}
int main(){
  int uint;
  vector<int>::iterator reite;
  vector<int> vinput = {1,2,3,4,5,6,7,8,9};
  cout << "type an integer between 1 and 9" << endl;
  if(cin >> uint){
    cout << "ok" << endl;
    reite = f(vinput.begin(), vinput.end(), uint);
    if(reite!=vinput.end())
      cout << "if " << uint << " exist within {1,2,3,4,5,6,7,8,9}? " <<  *reite << endl;
    else
      cerr << "the value " << uint << " is not found in {1,2,3,4,5,6,7,8,9}." << endl;
  }
}
```
```console
$ ./objectfile/ex9_5.o 
type an integer between 1 and 9
10
ok
the value 10 is not found in {1,2,3,4,5,6,7,8,9}.
$ ./objectfile/ex9_5.o 
type an integer between 1 and 9
9
ok
if 9 exist within {1,2,3,4,5,6,7,8,9}? 9
```

# [X] 9_6:
- --The problem is that the condition in `while (iter1 < iter2)` is never passed because `lst1` is empty; in other words `lst1.begin() == lst1.end()`.
- I might correct this program by explicitly defining `lst1` e.g. `lst1 = {1,2}`--
-   
```cpp
```
```console
```

# [X]9_7:
```cpp
vector<int>::iterator()
```

# 9_8:
- read --> ```cpp list<string>::const_iterator```
- write --> ```cpp list<string>::iterator```
```cpp
```
```console
```

# 9_9:
- `begin` returns a normal iterator, while `cbegin` returns `const` version of the iterator. This implies that `begin` can be used for reading and writing the first element of a container, while `cbegin` can be used only for reading.
```cpp
```
```console
```

# [X] 9_10:
- `it1`=`vector<int>::interator`
- `it2`=`vector<int>::const_iterator`
- `it3`=`vector<int>::const_iterator`
- `it4`=`vector<int>::const_iterator`
- (the following code produces no compile error:)
- key: when `auto` is used for `const vector<T>`, the `const` is dropped but `const_iterator` is used. 
```cpp
#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin();
vector<int>::iterator it1A;
auto it2 = v2.begin();
vector<int>::const_iterator it2A;
auto it3 = v1.cbegin();
vector<int>::const_iterator it3A;
auto it4 = v2.cbegin();
vector<int>::const_iterator it4A;
it1A = it1 +1;
cout << *it2 << endl;
it2A = it2;
it3A = it3;
it4A = it4;
}
```

# 9_11:
``````
``````
```cpp
#include<iostream>
#include<vector>
using namespace std;
ostream& vecprint(ostream& ros, const vector<int>& cvi){
  for(auto e : cvi)
    ros << e << " ";
  return ros;
}
int main(){
   vector<int> vint1 = {1,2,3}; //1st way - list initialization
  //vint1 contains three elemetns: 1,2,3
   vector<int> vint2(vint1); //2nd way - copy from already existing ocntainer (type match)
  //vint2 contains the copy of the vint1; namely 1,2,3
  vector<int> vint3(vint1.begin(), vint1.end()); //3rd way - copy the container via iterator
  //vint3 contains the range specified [1st_iterator, 2nd_iterator); namely, 1,2,3

  //sequential container specific constructors
   vector<int> vint4(3,1); //4th way - size & element initializer
  //vint4 contains 1,1,1 
   vector<int> vint5(3); //5th way - value initialization
  //vint5 contains 0,0,0
   vector<int> vint6(vint1.begin(), vint1.begin()+1); //6th way - copy a subset of the container via iterator
  //vint6 contains 1
   vector<int> vint6_2; //another possibility for 6th way - default initilization
  //vint6_2 contains nothing

  //print the each vector
  const vector<vector<int>> vecvecint = {vint1, vint2, vint3, vint4, vint5, vint6, vint6_2};
  for (auto vecint : vecvecint){
    vecprint(cout, vecint) <<  endl;
  }
}

```
```console
$ objectfile/ex9_11.o
1 2 3 
1 2 3 
1 2 3 
1 1 1 
0 0 0 
1 

```

# 9_12:
- when `iterator` is used to initialize an container by copying an existing ocntainer, 
- - there is no requirement that the container types of two containers need to be the same
- - there is no requirement that the container element types of two containers do not have to be the same as long as the conversion between them is feasible.
```cpp
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
ostream& vecprint(ostream& ros, const vector<int>& cvi){
  for(auto e : cvi)
    ros << e << " ";
  return ros;
}
int main(){
  vector<double> vint1 = {1.11,2.22,3.33}; //1st way - list initialization
  //vint1 contains three elemetns: 1,2,3
  
  // vector<int> vint2(vint1);
  //the above gives compilation error
  
  deque<int> vint3(vint1.begin(), vint1.end()); //3rd way - copy the container via iterator
  // the above line is valid because 
  // - there is no requirement that both container types need to be the same when iterators are used for initialization of the containe

  //print the each vector
  for (auto e : vint1)
    cout << e << " ";
  cout << "<-- vint1" << endl;
  for (auto e : vint3)
    cout << e << " ";
  cout << "<-- vint3" << endl;
}
```
```console
$ ./objectfile/ex9_12.o 
1.11 2.22 3.33 <-- vint1
1 2 3 <-- vint3
```

# 9_13:
- The container type `list` and `vector` are different so the simple copy cannot be used. Instead `iterator` must be used.
- The container element type vector`<int>` and vector`<double>` are different so the simple copy cannot be used. Instead `iterator` must be used.
```cpp
#include<iostream>
#include<vector>
#include<list>
using namespace std;
ostream& vecprint(ostream& ros, const vector<int>& cvi){
  for(auto e : cvi)
    ros << e << " ";
  return ros;
}
int main(){
  list<int> liin = {1,2,3};
  vector<int> vecin = {4,5,6,7};
  vector<double> v1 = {liin.begin(), liin.end()}; //1st way - list initialization
  vector<double> v2 = {vecin.begin(), vecin.end()}; //1st way - list initialization
  //vint1 contains three elemetns: 1,2,3
  
  //print the each vector
  for (auto e : v1)
    cout << e << " ";
  cout << "<-- v1" << endl;
  for (auto e : v2)
    cout << e << " ";
  cout << "<-- v2"<< endl;
}
```
```console
$ ./objectfile/ex9_13.o 
1 2 3 <-- v1
4 5 6 7 <-- v2
```

# 9_14:
``````
``````
```cpp
#include<iostream>
#include<list>
#include<string>
#include<vector>
using namespace std;
int main(){
  char Cstr1[]{"string1"};
  char Cstr2[]{"string2"};
  list<char*> liptr2cha = {Cstr1,Cstr2};

//container type and element type are different so normal assignement cannot be used.`
  vector<string> vecstr(1);
  vecstr.assign(liptr2cha.begin(), liptr2cha.end());

  for (auto e : liptr2cha)
    cout << e << " ";
  cout << "<-- lipt2cha" << endl;
  for (auto e : vecstr)
    cout << e << " ";
  cout << "<-- vecstr" << endl;
  
}
```
```console
$ ./objectfile/ex9_14.o 
string1 string2 <-- lipt2cha
string1 string2 <-- vecstr
```

# 9_15:
``````
``````
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main(){
  vector<int> vecint1 = {1,2,3,4};
  vector<int> vecint2 = {5,6,7,8};
  cout << "vecint1 == vecint2: " << (vecint1 == vecint2) << endl;
  cout << "vecint1 != vecint2: " << (vecint1 != vecint2) << endl;
}
```
```console
$ ./objectfile/ex9_15.o 
vecint1 == vecint2: 0
vecint1 != vecint2: 1
```

# 9_16:
- when the container typesare different, the relational operations cannot be used. Therefore, the logic needs to be implemented.
```cpp
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
```
```console
$ ./objectfile/ex9_16.o 
vector<int>: 1 2 3 4 
list<int>: 5 6 7 8 10 15 
vector <  list - true

$ ./objectfile/ex9_16.o 
vector<int>: 1 2 3 20 
list<int>: 5 6 7 8 10 15 
vector >  list - true

$ ./objectfile/ex9_16.o 
vector<int>: 5 6 7 8 10 15 
list<int>: 5 6 7 8 10 15 
vector == list - true
```

# 9_17:
The usage places the follwoing constraints: 
- the container types of `c1` and `c2` must be the same.
- the container element types of `c1` and `c2` must be the same.
- the container element types of `c1` and `c2` must have `<` operation.

# 9_18:
```cpp
#include<iostream>
#include<deque>
using namespace std;
int main(){
  string input;
  deque<string> deqstr;
  deque<string>::iterator iter = deqstr.begin();
  while(cin >> input){
   iter = deqstr.insert(iter, input); 
  }
  iter = deqstr.begin();
  cout << "deque<string>: ";
  while(iter != deqstr.end()){
    cout << *iter << " ";
    ++iter;
  }
  cout << endl;
}
#####---#####
#####---#####
#include<iostream>
#include<deque>
using namespace std;
int main(){
  string input;
  deque<string> deqstr;
  // deque<string>::const_reverse_iterator criter;
  deque<string>::const_iterator citer;
  while(cin >> input){
   deqstr.push_back(input); 
  }
  citer = deqstr.begin();
  cout << "deque<string>: ";
  while(citer != deqstr.end()){
    cout << *citer << " ";
    ++citer;
  }
  cout << endl;
}
```
```console
$ ./objectfile/ex9_18.o 
  cout << "vector == list - true" << endl;
deque<string>: endl; << true" - list == "vector << cout
#####---#####
#####---#####
$ ./objectfile/ex9_18_2.o 
  cout << "vector == list - true" << endl;
deque<string>: cout << "vector == list - true" << endl;  
```

# 9_19:
- `#include<vector>` to `#include<list>` 
- `vector<string> deqstr;` to `list<string> deqstr;` 
- `vector<string>::iterator iter = deqstr.begin();` to `list<string>::iterator iter = deqstr.begin();` 
```cpp
#include<iostream>
#include<list>
using namespace std;
int main(){
  string input;
  list<string> deqstr;
  list<string>::iterator iter = deqstr.begin();
  while(cin >> input){
   iter = deqstr.insert(iter, input); 
  }
  iter = deqstr.begin();
  cout << "deque<string>: ";
  while(iter != deqstr.end()){
    cout << *iter << " ";
    ++iter;
  }
  cout << endl;
}
```
```console
$ ./objectfile/ex9_19.o 
  cout << "vector == list - true" << endl;
deque<string>: endl; << true" - list == "vector << cout 
```

# 9_19_2:
- `#include<vector>` to `#include<list>` 
- `vector<string> deqstr;` to `list<string> deqstr;` 
- `vector<string>::iterator iter = deqstr.begin();` to `list<string>::iterator iter = deqstr.begin();` 
```cpp
#include<iostream>
#include<list>
using namespace std;
int main(){
  string input;
  list<string> deqstr;
  // deque<string>::const_reverse_iterator criter;
  list<string>::const_iterator citer;
  while(cin >> input){
   deqstr.push_back(input); 
  }
  citer = deqstr.begin();
  cout << "deque<string>: ";
  while(citer != deqstr.end()){
    cout << *citer << " ";
    ++citer;
  }
  cout << endl;
}
```
```console
$ ./objectfile/ex9_19_2.o 
  cout << "vector == list - true" << endl;
deque<string>: cout << "vector == list - true" << endl; 
```

# 9_20:
``````
``````
```cpp
#include<deque>
#include<list>
#include<iostream>
using namespace std;
int main(){
  deque<int> odd;
  deque<int> even;
  list<int> input;
  int i;
  div_t divresult;
  list<int>::const_iterator cite;// = input.begin();
  cout << "type a bunch of integers" << endl;
  while(cin >> i){
    input.push_back(i);
  }
  cite = input.begin();
  while(cite != input.end()){
    divresult = div(*cite, 2);
    // cout << divresult.rem << " ";
    if(divresult.rem == 0)
      even.push_back(*cite);
    else
      odd.push_back(*cite);
    ++cite; 
  }
  cout << "odd - list: ";
  for(auto e : odd)
    cout << e << " ";
  cout << endl;

  cout << "even - list: ";
  for(auto e : even)
    cout << e << " ";
  cout << endl;
}
```
```console
$ ./objectfile/ex9_20.o 
type a bunch of integers
1 2 3 4 5 6 7 8 9 10 11 12 13 15 17 16
odd - list: 1 3 5 7 9 11 13 15 17 
even - list: 2 4 6 8 10 12 16 
```

# [X]9_21:
- it works with `vector` in the same way for `list`. `vector.insert(iter, word)` returns `iterator` to the inserted element, which will be passed as the 1st argument to the `insert` method in the `while` loop.
- it is very important to know that `insert` operation for `vector` can become very computationally expentive.
```cpp
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
  vector<string> vec;
  auto iter = vec.begin();
  string word;
  while(cin >> word)
    iter = vec.insert(iter, word);
  cout << "vector<string>: ";
  for(const auto e : vec)
    cout << e << " ";
  cout << endl;
}
```
```console
$ ./objectfile/ex9_21.o 
 list<int>::const_iterator cite;// = input.begin();
vector<string>: input.begin(); = cite;// list<int>::const_iterator 
```

# 9_22:
- `iter` will be never increased in `while` loop, resulting in the endless loop
- One way to correct this issue just add `++iter` inside while loop.
```cpp
#include<iostream>
#include<vector>
using namespace std;
int main() {
  vector<int> iv = {1,2,3,4,5,6,7,8};
  int some_val = 3;
  vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size()/2;
  cout << "iv: ";
  for (const auto e : iv)
    cout << e << " ";
  cout << endl;
  while (iter != mid){
      if (*iter == some_val){
          iv.insert(iter, 2 * some_val);
      }
      ++iter;
  }
  cout << "iv: -after operation- ";
  for (const auto e : iv)
    cout << e << " ";
  cout << endl;
}
```
```console
$ ./objectfile/ex9_22.o 
iv: 1 2 3 4 5 6 7 8 
iv: -after operation- 1 2 6 3 4 5 6 7 8 
```

# 9_23:
- val, val2, val3, and val4 be if c.size() is 1
- val = c[0],  val2 = c[0], val3 = c[0], val4 = c[0] 

# 9_24:
``````
``````
```cpp
#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> c = {};
  auto val = c.at(0);
  auto val2 = c[0];
  auto val3 = c.front();
  auto val4 = *c.begin();
  cout << "val: " << val << "val2:" << val2 << "val3:" << val3 << "val4" << val4 << "last" << endl;

  // if (!c.empty()) {
      // val and val2 are copies of the value of the first element in c
      // auto val = *c.begin(), val2 = c.front();
      // val3 and val4 are copies of the of the last element in c
      // auto last = c.end();
      // auto val3 = *(--last); // can't decrement forward_list iterators
      // auto val4 = c.back();  // not supported by forward_list
      // cout << "val: " << val << "val2:" << val2 << "val3:" << val3 << "val4" << val4 << "last" << endl;
  // }
}
```
```console
$ ./objectfile/ex9_24.o 
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
Aborted (core dumped)
```

# 9_25:
- when `elem1` == `elem2`, nothing will be erased from a container
- when `elem2` = the off-the-end iterator, all elements from `elem1` till the end of a container will be erased.
- when `elem1` == `elem2` are both the off-the-end iterators, nothing will be erased from a container.
```cpp
#include<iostream>
#include<list>
using namespace std;
int main(){
  list<int> slist = {0,1,2,3,4,5,6,7,8,9};
  cout << "original - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
  auto elem1 = slist.begin();
  auto elem2 = slist.begin();
  elem1 = slist.erase(elem1, elem2);
  cout << "when elem1==elem2(slist.begin()) - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
  elem1 = slist.begin();
  elem2 = slist.end();
  elem1 = slist.erase(elem1, elem2);
  cout << "when elem1==slist.begin(), elem2=slist.end() - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
  cout << endl;
  slist = {0,1,2,3,4,5,6,7,8,9};
  elem1 = slist.end();
  elem2 = slist.end();
  elem1 = slist.erase(elem1, elem2);
  cout << "when elem1==elem2=slist.end() - slist: ";
  for(const auto e : slist){
    cout << e << " ";
  }
  cout << endl;
}
```
```console
$ ./objectfile/ex9_25.o
original - slist: 0 1 2 3 4 5 6 7 8 9 
when elem1==elem2(slist.begin()) - slist: 0 1 2 3 4 5 6 7 8 9 
when elem1==slist.begin(), elem2=slist.end() - slist: 
when elem1==elem2=slist.end() - slist: 0 1 2 3 4 5 6 7 8 9 
```

# 9_26:
``````
``````
```cpp
#include<iostream>
#include<list>
#include<vector>
#include<iterator>
using namespace std;
  // template <class Container>
  // auto begin (Container& cont) -> decltype (cont.begin());
int main(){
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  vector<int> v;
  list<int> l;
  auto iter = std::begin(ia);
  cout << "ia[] = ";
  while(iter != end(ia)){
    cout << *iter << " ";
    v.push_back(*iter);
    l.push_back(*iter);
    ++iter;
  }
  cout << endl;
  for(auto i = v.begin(); i != v.end();){
    if(*i % 2 == 0)
      i = v.erase(i);
    else
      ++i;
  }
  for(auto i = l.begin(); i != l.end();){
    if(*i % 2 != 0)
      i = l.erase(i);
    else
      ++i;
  }
  cout << "list<int>: ";
  for(auto e : l)
    cout << e << " ";
  cout << endl;
  cout << "vector<int>: ";
  for(auto e : v)
    cout << e << " ";
  cout << endl;
}
```
```console
$ objectfile/ex9_26.o
ia[] = 0 1 1 2 3 5 8 13 21 55 89 
list<int>: 0 2 8 
vector<int>: 1 1 3 5 13 21 55 89 
```

# 9_27:
``````
``````
```cpp
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
  forward_list<int> fl;
  int input;
  forward_list<int>::iterator itercur;
  forward_list<int>::iterator iterpre;
  cout << "give the integers to pass to forward_list: ";
  iterpre = fl.before_begin();
  while(cin >> input)
    iterpre = fl.insert_after(iterpre, input);
  iterpre = fl.before_begin();
  itercur = fl.begin();
  while(itercur != fl.end()){
    if(*itercur % 2)
      itercur = fl.erase_after(iterpre);
    else{
      iterpre = itercur;
      ++itercur;
    }
  }
  cout << "after the 'erase_after': forward_list<int> = ";
  for(const auto e : fl)
    cout << e << " ";
  cout << endl;

}
```
```console
$ ./objectfile/ex9_27_2.o 
give the integers to pass to forward_list: 1 2 3 4 5 6 7 8 9 10 11
after the 'erase_after': forward_list<int> = 2 4 6 8 10 
```

# 9_28:
``````
``````
```cpp
#include<iostream>
#include<forward_list>
#include<string>
#include<algorithm>
using namespace std;
void f(forward_list<string>& fls, const string& cstre, const string& cstri){
  forward_list<string>::const_iterator locins;
  bool doneins = false;
  for(auto fls_curite = fls.begin(); fls_curite != fls.end(); fls_curite++){
    locins = fls_curite;
    if(cstre.compare(*fls_curite)==0){
      fls_curite = fls.insert_after(fls_curite, cstri);
      doneins = true;
    }
  }
  if(!doneins){
        fls.insert_after(locins, cstri);
  }

}
ostream& flsprint(ostream& ros, const forward_list<string>& crfls){
  for(const auto e : crfls)
    ros << e << " ";
  return ros;
}
int main(){
  forward_list<string> fls;
  auto preiter = fls.before_begin();
  string strinp;
  string strinpser;
  string strinpins;
  cout << "type forward_list<string>: ";
  while(cin >> strinp)
    preiter = fls.insert_after(preiter, strinp);
  cin.clear();
  cout << endl << "type a string to be searched: ";
  cin >> strinpser;
  cin.clear();
  cout << endl << "type a string to be inserted: ";
  cin >> strinpins;
  f(fls, strinpser, strinpins);
  cout << endl << "after the insert-funciton, forward_list: ";
  flsprint(cout, fls) << endl;
}
```
```console
$ ./objectfile/ex9_28.o 
type forward_list<string>: steve jobs stay hungry stay foolish

type a string to be searched: jobs
type a string to be inserted: -
after the insert-funciton, forward_list: steve jobs - stay hungry stay foolish 

$ ./objectfile/ex9_28.o 
type forward_list<string>: steve jobs stay hungry stay foolish

type a string to be searched: aaa
type a string to be inserted: NotFound
after the insert-funciton, forward_list: steve jobs stay hungry stay foolish NotFound
```

# 9_29:
- `vec.resize(100)` will add 75 `0` to the vector.
- `vec.resize(10)` will remove 90 elements from the back of the vector.

# 9_30:
- the element type must have a default constructor ().

# 9_31:
- The program does not work for `list` because random-access for `list` is not implemented. In other words, the operator `+=` used in `iter += 2` does not exist for `list<T>::iterator` and thus the program fails.
- The program does not work for `forward_list` because
- - 1. random access is not implemented and thus the operator `+=` used in `iter += 2` for `forward_list<T>::iterator` does not work.
- - 2. the `forward_list` do not have `erase` or `insert` methods. Instead, the methods `methods` `erase_after` or `insert_after` need to be called with the `iterator` pointing the element before the one to be erased or after which a new element is inserted.
```cpp
// -- For list --
#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main(){
  list<int> vi = {0,1,2,3,4,5,6,7,8,9};
  auto iter = vi.begin(); // call begin, not cbegin because we're changing
  decltype(iter) preiter;  
  while (iter != vi.end()) {
      if (*iter % 2) {
          preiter = iter;
          ++iter; // advance to the iterator before which insertion is done.
          iter = vi.insert(iter, *preiter);  // duplicate the current
          ++iter; // advance past this element and the one inserted before it
      } else
          iter = vi.erase(iter);          // remove even elements
          // don't advance the iterator; iter denotes the element after the one we
  }
  cout << " after erase - vi: ";
  for (const auto e : vi){
    cout << e << " ";
  }
  cout << endl;
}

// -- For forward_list --
#include<iostream>
#include<vector>
#include<forward_list>
using namespace std;
int main(){
  forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
  auto iter = vi.begin();
  decltype(iter) preiter = vi.before_begin();  
  while (iter != vi.end()) {
      if (*iter % 2) {
          iter = vi.insert_after(iter, *iter);
          preiter = iter;
          ++iter; 
      } else
          iter = vi.erase_after(preiter);          
 
  }
  cout << " after erase - vi: ";
  for (const auto e : vi){
    cout << e << " ";
  }
  cout << endl;
}
```
```console
$ ./objectfile/ex9_31_list.o 
 after erase - vi: 1 1 3 3 5 5 7 7 9 9 

 $ ./objectfile/ex9_31_forward_list.o 
 after erase - vi: 1 1 3 3 5 5 7 7 9 9
```

# 9_32:
- `vi.insert(iter, *iter++);` would be leagal since the `precedence` of post incremental operator `++` is higher than the dereference operator `*`. `iter + 2` needs to be chagned to `++iter` to get the same result.
```cpp
#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
using namespace std;
int main(){
  vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
  auto iter = vi.begin(); // call begin, not cbegin because we're changing
  while (iter != vi.end()) {
      if (*iter % 2) {
          iter = vi.insert(iter, *iter++);  // duplicate the current
          // iter += 2; // advance past this element and the one inserted before it
          ++iter;
      } else
          iter = vi.erase(iter);          // remove even elements
          // don't advance the iterator; iter denotes the element after the one we
  }
  cout << " after erase - vi: ";
  for (const auto e : vi){
    cout << e << " ";
  }
  cout << endl;
}
```
```console
$ ./objectfile/ex9_32.o 
 after erase - vi: 1 1 3 3 5 5 7 7 9 9 
```

# [X] 9_33:
- The program would fail with `undefined behavior`. The iterator returned by calling the `insert` method was not reassigned to the orignal iterator, therefore, the iterator would become invalidated.`  `
```cpp
#include<iostream>
#include<vector>
using namespace std;
void f_ori(vector<int>::iterator begin, vector<int>& v){
  while (begin != v.end()) {
      ++begin;  // advance begin because we want to insert after this element
      begin = v.insert(begin, 42);  // insert the new value
      ++begin;  // advance begin past the element we just added
  }
}
void f_mod(vector<int>::iterator begin, vector<int>& v){
  while (begin != v.end()) {
      ++begin;  // advance begin because we want to insert after this element
      v.insert(begin, 42);  // insert the new value
      ++begin;  // advance begin past the element we just added
  }
}
ostream& vprint(ostream& ros, vector<int>& crv){
  for(auto e : crv)
    ros << e << " ";
  return ros;
}
int main(){
  vector<int> v{0,1,2,3,4,5,6,7,8,9};
  vector<int> v2{0,1,2,3,4,5,6,7,8,9};
  auto begin = v.begin(); //end = v.end();
  auto begin2 = v2.begin();// end2 = v2.end();
  f_ori(begin, v);
  cout << "original inserting result: ";
  vprint(cout, v) << endl;;
  f_mod(begin2, v2);
  cout << "modified inserting result: ";
  vprint(cout, v2) << endl;
}
```
```console
$ ./objectfile/ex9_33.o 
original inserting result: 0 42 1 42 2 42 3 42 4 42 5 42 6 42 7 42 8 42 9 42 
Segmentation fault (core dumped)
```

# 9_34:
- The loop would result in a endless loop when it encouters an odd value. This is because after the insert, the `iterator` is reset by pointing to the inserted element and `++iter` keeps pointing the same odd value in the next iteration.

# 9_35:
- The difference between `capacity` and `size` is as follows:
- - `capacity` indicates the number of elements that a `container` can have without allocating new space in memory.
- - `size` means that the number of elements that a `contaner` currently has.

# 9_36:
- No, it is not possible.

# 9_37:
- `list` does not have a `capacity` member because the capacity constraint stem from storing elements contiguously in a memory as with `vector` does not exist for `list`. For `list`, new elements can be randomly added to somewhere in the memory due to the implementation of `list`.
-  `array` does not have a capacity number because the concept of capacity is not valide for array. More specifically, the array size is fixed and new elements can not be added to the `array` by reallocation of the memory.
```cpp
```
```console
```

# 9_38:
- a `vector` grows by doubling its `capacity` upon the reallocation occurs.
```cpp
#include<iostream>
#include<vector>
using namespace std;
ostream& vprint(ostream& ros, vector<int>& v){
  ros << "v.size(): " << v.size() << endl << "v.capacity: " << v.capacity() << endl;
  ros << "v.push_back(0);" << endl;
  v.push_back(0);
  ros << "v.size(): " << v.size() << endl << "v.capacity: " << v.capacity();
  return ros;
}
void addelement(vector<int>& crv){
  while(crv.size() != crv.capacity())
    crv.push_back(0);
}
int main(){
  vector<int> v;
  cout << "---v is empty---" << endl;
  vprint(cout, v) << endl;
  v.reserve(10);
  cout << "---v.researve(10);---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---first push_back cycle---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---second push_back cycle---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---3rd push_back cycle---" << endl;
  vprint(cout, v) << endl;
  addelement(v);   
  cout << "---4th push_back cycle---" << endl;
  vprint(cout, v) << endl;
}
```
```console
$ ./objectfile/ex9_38.o
---v is empty---
v.size(): 0
v.capacity: 0
v.push_back(0);
v.size(): 1
v.capacity: 1
---v.researve(10);---
v.size(): 1
v.capacity: 10
v.push_back(0);
v.size(): 2
v.capacity: 10
---first push_back cycle---
v.size(): 10
v.capacity: 10
v.push_back(0);
v.size(): 11
v.capacity: 20
---second push_back cycle---
v.size(): 20
v.capacity: 20
v.push_back(0);
v.size(): 21
v.capacity: 40
---3rd push_back cycle---
v.size(): 40
v.capacity: 40
v.push_back(0);
v.size(): 41
v.capacity: 80
---4th push_back cycle---
v.size(): 80
v.capacity: 80
v.push_back(0);
v.size(): 81
v.capacity: 160
```

# [X]9_39:
- The program first reserves a space in a memory where 1024 string elements can be stored before reallocation is required. After that, the strings coming from stream is added to the vector. Finally, the memory spaces allocated to the vector is changed so that at least half the number of elements currently stored in the vector can be added without realloction.(Note that the `capacity` of the vector is changed only if the requested `capacity` results in exceeding the current `capacity`.)

# [X]9_40:
- When the programa reads `256` words, the `capacity` after `resize` is likely to be `1024`
- When the programa reads `512` words, the `capacity` after `resize` is likely to be `1024`
- When the programa reads `1000` words, the `capacity` after `resize` is likely to be `2000`
- When the programa reads `1048` words, the `capacity` after `resize` is likely to be `2000`
```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void vadd(vector<string>& svec, const int ni){
  for(auto i = 0; i != ni; i++){
    svec.push_back("a");
  }
}
int main(){
  vector<string> svec;
  svec.reserve(1024);
  const vector<int> cv{256, 512, 1000, 1048};
  // string word;
  // while (cin >> word)
          // svec.push_back(word);
  for (const auto e : cv){
    cout << e << " number of words are added." << endl;
    vadd(svec, e);
    cout << "svec.size() - before resize: " << svec.size() << endl;
    svec.resize(svec.size()+svec.size()/2);
    cout << "svec.size() - after resize: " << svec.size() << endl;
    cout << "svec.capacity(): " << svec.capacity() << endl;
    svec.clear();
    svec.reserve(1024);
  }

}
```
```console
$ ./objectfile/ex9_40.o
256 number of words are added.
svec.size() - before resize: 256
svec.size() - after resize: 384
svec.capacity(): 1024
512 number of words are added.
svec.size() - before resize: 512
svec.size() - after resize: 768
svec.capacity(): 1024
1000 number of words are added.
svec.size() - before resize: 1000
svec.size() - after resize: 1500
svec.capacity(): 2000
1048 number of words are added.
svec.size() - before resize: 1048
svec.size() - after resize: 1572
svec.capacity(): 2000
```

# 9_41:
```cpp
#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<char> chvec{'H', 'i', '!',',', 'r', 'e','a', 'd', 'e','r','.'};
  string s1(chvec.begin(),chvec.end());
  cout << "vector<char>: ";
  for (const auto e : s1)
    cout <<  e << " ";
  cout << endl;
  cout << "string(vector<char>.begin(), vector<char>.end(): ): ";
  for (const auto e : s1)
    cout <<  e << " ";
  cout << endl;
}
```
```console
$ ./objectfile/ex9_41.o
vector<char>: H i ! , r e a d e r . 
string(vector<char>.begin(), vector<char>.end(): ): H i ! , r e a d e r . 
```

# 9_42:
- The performance of the program might be improved by
- 1. allocating the necessary memory space to the string using `reserve(100)`.

```cpp
// with reserve ./objectfile/ex9_42_imp.o 
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int main(int argc, char** argv){
  string s;
  const clock_t begin_time = clock();
  time_t start, finish;
  time(&start);
  for (auto i = 1; i != argc; i++){
    // s += **(argv+i);
    s = **(argv+i);
  }
  time(&finish);
  cout << "Time required(via time) = " << difftime(finish, start) << " seconds" << endl;
  cout << "cpu execution time (via clock): " << float(clock() - begin_time) << endl;
  cout << "length of input" << argc << endl;
  cout << "string: " << s << endl;
}
// without reserve - ./objectfile/ex9_42_test.o 
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int main(int argc, char** argv){
  string s;
  const clock_t begin_time = clock();
  time_t start, finish;
  time(&start);
  for (auto i = 1; i != argc; i++){
    // s += **(argv+i);
    s = **(argv+i);
  }
  time(&finish);
  cout << "Time required(via time) = " << difftime(finish, start) << " seconds" << endl;
  cout << "cpu execution time (via clock): " << float(clock() - begin_time) << endl;
  cout << "length of input" << argc << endl;
  cout << "string: " << s << endl;
}
```
```console
$ ./objectfile/ex9_42_test.o 
Time required(via time/sec): 0 seconds
cpu execution time (via clock/msec): 225

$ ./objectfile/ex9_42_imp.o 
Time required(via time/sec) with string.reserve(10000): 0 seconds
cpu execution time (via clock/msec) string.reserve(10000): 157
```

# 9_43:
```cpp
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
void fandr(string& s, const string& oldVal, const string& newVal){
  size_t sz = s.find(oldVal,0);
  string::const_iterator beg = s.begin();
  // cout << oldVal << " is found at the location from " << sz << endl;
  auto erbeg = beg+sz;
  auto erend = erbeg+oldVal.size();
  auto inbeg = s.begin() + sz;
  s.erase(erbeg, erend);
  cout << "just after erase :" << s;
  s.insert(inbeg, newVal.begin(), newVal.end());
  // s.replace(sz, oldVal.size(), newVal);
}
ostream& sprint(ostream& ros, const string& s, const string& oldVal, const string& newVal){
  ros << "s: " << s << endl;
  ros << "oldVal: " << oldVal << endl;
  ros << "newVal: " << newVal << endl;
  return ros;
}
int main(){
  string s("Water comes thru the pipe, tho it hasn't rained for almost one year.");
  string oldVal = "thru";
  string newVal = "through";
  cout << "case1: " << endl;
  cout << "before erase+insert" << endl;
  sprint(cout, s, oldVal, newVal);
  fandr(s,oldVal,newVal);
  cout << "after erase+insert: " << endl;
  sprint(cout, s, oldVal, newVal);
  cout << "case2: " << endl;
  oldVal = "tho";
  newVal = "though";
  cout << "before erase+insert" << endl;
  sprint(cout, s, oldVal, newVal);
  fandr(s,oldVal,newVal);
  cout << "after erase+insert: " << endl;
  sprint(cout, s, oldVal, newVal);
}
```
```console
$ ./objectfile/ex9_43.o 
case1: 
before erase+insert
s: Water comes thru the pipe, tho it hasn't rained for almost one year.
oldVal: thru
newVal: through
just after erase :Water comes  the pipe, tho it hasn't rained for almost one year.after erase+insert: 
s: Water comes through the pipe, tho it hasn't rained for almost one year.
oldVal: thru
newVal: through
case2: 
before erase+insert
s: Water comes through the pipe, tho it hasn't rained for almost one year.
oldVal: tho
newVal: though
just after erase :Water comes through the pipe,  it hasn't rained for almost one year.after erase+insert: 
s: Water comes through the pipe, though it hasn't rained for almost one year.
oldVal: tho
newVal: though

```

# 9_44:
```cpp
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
void fandr(string& s, const string& oldVal, const string& newVal){
  size_t sz = s.find(oldVal,0);
  // cout << oldVal << " is found at the location from " << sz << endl;
  s.replace(sz, oldVal.size(), newVal);
}
ostream& sprint(ostream& ros, const string& s, const string& oldVal, const string& newVal){
  ros << "s: " << s << endl;
  ros << "oldVal: " << oldVal << endl;
  ros << "newVal: " << newVal << endl;
  return ros;
}
int main(){
  string s("Water comes thru the pipe, tho it hasn't rained for almost one year.");
  string oldVal = "thru";
  string newVal = "through";
  cout << "case1: " << endl;
  cout << "before replacement" << endl;
  sprint(cout, s, oldVal, newVal);
  fandr(s,oldVal,newVal);
  cout << "after replace: " << endl;
  sprint(cout, s, oldVal, newVal);
  cout << "case2: " << endl;
  oldVal = "tho";
  newVal = "though";
  cout << "before replacement" << endl;
  sprint(cout, s, oldVal, newVal);
  fandr(s,oldVal,newVal);
  cout << "after replace: " << endl;
  sprint(cout, s, oldVal, newVal);
}
```
```console
case1: 
before replacement
s: Water comes thru the pipe, tho it hasn't rained for almost one year.
oldVal: thru
newVal: through
after replace: 
s: Water comes through the pipe, tho it hasn't rained for almost one year.
oldVal: thru
newVal: through
case2: 
before replacement
s: Water comes through the pipe, tho it hasn't rained for almost one year.
oldVal: tho
newVal: though
after replace: 
s: Water comes through the pipe, though it hasn't rained for almost one year.
oldVal: tho
newVal: though
```

# 9_45:
```cpp
#include<string>
#include<iostream>
using namespace std;
string& f(string& name, const string& prefix, const string& suffix){
  name.insert(0," ");
  name.insert(name.begin(), prefix.begin(), prefix.end());
  name.append(" ");
  name.append(suffix.begin(), suffix.end());
  return name;
}
int main(){
  string name("Robert Downy");
  cout << "before function call - name: " << name << endl;
  name = f(name, "Mr.", "Jr.");
  cout << "after function call - name: " << name << endl;
}
```
```console
$ ./objectfile/ex9_45.o 
before function call - name: Robert Downy
after function call - name: Mr. Robert Downy Jr.
```

# 9_46:
```cpp
#include<string>
#include<iostream>
using namespace std;
string& f(string& name, const string& prefix, const string& suffix){
  name.insert(0," ");
  name.insert(0, prefix,0, prefix.size());
  name.insert(name.size(), " ");
  name.insert(name.size(), suffix, 0, suffix.size());
  return name;
}
int main(){
  string name("Robert Downy");
  cout << "before function call - name: " << name << endl;
  name = f(name, "Mr.", "Jr.");
  cout << "after function call - name: " << name << endl;
}
```
```console
$ ./objectfile/ex9_46.o 
before function call - name: Robert Downy
after function call - name: Mr. Robert Downy Jr.
```

# 9_47:
```cpp
#include<string>
#include<iostream>
using namespace std;
size_t find_first(const string& crs, const string::size_type pos, const string& searchfrom){
  return crs.find_first_of(searchfrom, pos);
}
size_t find_not_first(const string& crs, const string::size_type pos, const string& searchfrom){
  return crs.find_first_not_of(searchfrom, pos);
}
int main(){
//version 1
  const string inp("ab2c3d7R4E6");
  const string alph("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  const string nume("0123456789");
  string::size_type pos = 0;
  // find all index for alphabet
  cout << "target string: " << inp << endl;
  while((pos = find_first(inp, pos, alph))!= string::npos){
    cout << "alphabet was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
  pos = 0;
  while((pos = find_first(inp, pos, nume))!= string::npos){
    cout << "numeric was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
  cout << "########## case: find_not_of ##########" << endl;
  cout << "target string: " << inp << endl;
  pos = 0;
  while((pos = find_not_first(inp, pos, nume))!= string::npos){
    cout << "alphabet was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
  pos = 0;
  while((pos = find_not_first(inp, pos, alph))!= string::npos){
    cout << "numeric was found at position: " << pos << ", with value '" << inp[pos] << endl;
    ++pos;
  }
}
```
```console
$ ./objectfile/ex9_47.o 
target string: ab2c3d7R4E6
alphabet was found at position: 0, with value 'a
alphabet was found at position: 1, with value 'b
alphabet was found at position: 3, with value 'c
alphabet was found at position: 5, with value 'd
alphabet was found at position: 7, with value 'R
alphabet was found at position: 9, with value 'E
numeric was found at position: 2, with value '2
numeric was found at position: 4, with value '3
numeric was found at position: 6, with value '7
numeric was found at position: 8, with value '4
numeric was found at position: 10, with value '6
########## case: find_not_of ##########
target string: ab2c3d7R4E6
alphabet was found at position: 0, with value 'a
alphabet was found at position: 1, with value 'b
alphabet was found at position: 3, with value 'c
alphabet was found at position: 5, with value 'd
alphabet was found at position: 7, with value 'R
alphabet was found at position: 9, with value 'E
numeric was found at position: 2, with value '2
numeric was found at position: 4, with value '3
numeric was found at position: 6, with value '7
numeric was found at position: 8, with value '4
numeric was found at position: 10, with value '6
```

# 9_48:
- `numbers.find(name)` returns `string::npos`.
- Note that `string::size_type` has the type `unsigned integer`. When `find` returns `string::npos` that is `static const size_t npos = -1;`, `signed integer` -1 is held by `unsigned iteger`. This results in showing a very lager integers `18446744073709551615` in stream when it is output in the ostream.
- reference:
- - <https://www.cplusplus.com/reference/string/string/npos/>
- - <http://www.cplusplus.com/forum/beginner/224624/>
```cpp
#include<iostream>
#include<string>
using namespace std;
int main(){
  string numbers("0123456789"), name("r2d2");
  string::size_type pos = numbers.find(name);
  string::size_type const_npos = string::npos;
  cout << "numbers: " << numbers << ", name: " << name << endl;
  cout << "numbers.find(name) returns " << pos << endl;
  cout << "if string::npos == numbers.find(name)? : " << ((const_npos == pos)? "true":"false") << endl; 
}
```
```console
$ ./objectfile/ex9_48.o 
numbers: 0123456789, name: r2d2
numbers.find(name) returns 18446744073709551615
if string::npos == numbers.find(name)? : true
```

# 9_49:
```cpp
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
```
```console
######## The input text ########
Deep learning allows computational models that are composed of multiple processing layers to learn representations of data with multiple levels of abstraction. These methods have dramatically improved the state-of-the-art in speech recognition, visual object recognition, object detection and many other domains such as drug discovery and genomics. Deep learning discovers intricate structure in large data sets by using the backpropagation algorithm to indicate how a machine should change its internal parameters that are used to compute the representation in each layer from the representation in the previous layer. Deep convolutional nets have brought about breakthroughs in processing images, video, speech and audio, whereas recurrent nets have shone light on sequential data such as text and speech. [https://www.nature.com/articles/nature14539] 
######## The input text ########
the longest word that contains neither ascenders not descenders: 'are, are' with length 3.
```

# 9_50:
```cpp
// For string<int>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
  vector<string> svec;
  string input;
  int sum = 0;
  cout << "Type multiple integers to be summed up.(with space) " << endl;
  while(cin >> input)
    svec.push_back(input);
  for (const auto e : svec){
    sum += stoi(e, nullptr);
  }
  cout << "Sum of the integers: " << sum << endl;
}

// For string<double>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
  vector<string> svec;
  string input;
  float sum = 0;
  cout << "Type multiple floating-point values to be summed up.(with space) " << endl;
  while(cin >> input)
    svec.push_back(input);
  for (const auto e : svec){
    sum += stod(e, nullptr);
  }
  cout << "Sum of the integers: " << sum << endl;
}
```
```console
$ ./objectfile/ex9_50.o  
Type multiple integers to be summed up.(with space) 
1 2 3 4 5
Sum of the integers: 15

$ ./objectfile/ex9_50_float.o  
Type multiple floating-point values to be summed up.(with space) 
1.1 1.2 1.3 1.4 1.5 1.6
Sum of the integers: 8.1
```

# 9_50:
- `ymd.h`
```cpp
#ifndef YMD_H
#define YMD_H
#include<string>
#include<iostream>
using namespace std;
class ymd {
  public:
    ymd() = default;
    ymd(string s) {
      if(s.find("/")!=string::npos){
        string::size_type sz1 = s.find_first_of("/");
        string::size_type sz2 = s.find_last_of("/");
        day = stoi(s.substr(0, sz1));
        month = stoi(s.substr(sz1+1, sz2));
        year = stoi(s.substr(sz2+1));
      }

      if(s.find(",")!=string::npos){
        const string cstr("JanuaryFebMchApilJgstSmbOoNvD");
        string monthstr;
        string::size_type sz1 = s.find_first_of(cstr);
        string::size_type sz2 = s.find_last_of(cstr);
        // string::size_type sz1 = s.find_first_of("JanuaryFebMchApilJgstSmbOoNvD");
        string::size_type sz3 = s.find_last_of(",");
        day = stoi(s.substr(sz2+1, sz3));
        year = stoi(s.substr(sz3+1));
        monthstr = s.substr(sz1, sz2+1);
        cout << "monthstr = " << monthstr << ", ";
        if (monthstr.find("Ja")!=string::npos)
          month = 1;
        else if (monthstr.find("Fe")!=string::npos)
          month = 2;
        else if (monthstr.find("Mar")!=string::npos)
          month = 3;
        else if (monthstr.find("Ap")!=string::npos)
          month = 4;
        else if (monthstr.find("May")!=string::npos)
          month = 5;
        else if (monthstr.find("Jun")!=string::npos)
          month = 6;
        else if (monthstr.find("Jul")!=string::npos)
          month = 7;
        else if (monthstr.find("Aug")!=string::npos)
          month = 8;
        else if (monthstr.find("Sep")!=string::npos)
          month = 9;
        else if (monthstr.find("Oct")!=string::npos)
          month = 10;
        else if (monthstr.find("Nov")!=string::npos)
          month = 11;
        else if (monthstr.find("Dec")!=string::npos)
          month = 12;
      }

    }
    unsigned int get_year(){
      return year;
    }
    unsigned int get_month(){
      return month;
    }
    unsigned int get_day(){
      return day;
    }
  private:
    unsigned int year, month, day;
};

#endif
```
- `ex9_51_main.cpp`
```cpp
#include<string>
#include<iostream>
#include<fstream>
#include<ymd.h>
using namespace std;


int main(int argc, char** argv){
  if(argc > 1){
    ifstream ifs(*(argv+1), ifstream::in);
    if(ifs.is_open()){
      string line;
      while(getline(ifs, line)){
       ymd ymdins(line);
       cout << "year: " << ymdins.get_year() << ", " << "month: " << ymdins.get_month() << ", day: " << ymdins.get_day() << endl;
      }
    }
  } else {
    cerr << "there are no inputs files in which dates of births are kept for each line." << endl;
  }
}
```
- `ex9_51_input.txt`
```txt
January 1, 1900
1/1/1900
10/12/1901
Jan 1, 1902
Feb 5, 1903
Mar 10, 1904
Apr 11, 1905
May 12, 1906
Jun 13, 1907
Jul 14, 1908
Aug 15, 1909
Sep 16, 1910
Oct 17, 1920
Nov 18, 1930
Dec 19, 1940
Jan 20, 1950
February 1, 1910
March 11, 1902
April 12, 1930
May 13, 1940
June 14, 1950
July 15, 1960
August 16, 1970
September 17, 1980
October 18, 1990
November 19, 1901
December 21, 1903
```

```console
$ g++ -o ./objectfile/ex9_51_main.o -I/home/nozomi/Cpp_primer_5th_exercises/9 ex9_51_main.cpp
$ ./objectfile/ex9_51_main.o ex9_51_input.txt 
monthstr = January, year: 1900, month: 1, day: 1
year: 1900, month: 1, day: 1
year: 1901, month: 12, day: 10
monthstr = Jan, year: 1902, month: 1, day: 1
monthstr = Feb, year: 1903, month: 2, day: 5
monthstr = Mar, year: 1904, month: 3, day: 10
monthstr = Apr, year: 1905, month: 4, day: 11
monthstr = May, year: 1906, month: 5, day: 12
monthstr = Jun, year: 1907, month: 6, day: 13
monthstr = Jul, year: 1908, month: 7, day: 14
monthstr = Aug, year: 1909, month: 8, day: 15
monthstr = Sep, year: 1910, month: 9, day: 16
monthstr = Oct, year: 1920, month: 10, day: 17
monthstr = Nov, year: 1930, month: 11, day: 18
monthstr = Dec, year: 1940, month: 12, day: 19
monthstr = Jan, year: 1950, month: 1, day: 20
monthstr = February, year: 1910, month: 2, day: 1
monthstr = March, year: 1902, month: 3, day: 11
monthstr = April, year: 1930, month: 4, day: 12
monthstr = May, year: 1940, month: 5, day: 13
monthstr = June, year: 1950, month: 6, day: 14
monthstr = July, year: 1960, month: 7, day: 15
monthstr = August, year: 1970, month: 8, day: 16
monthstr = September, year: 1980, month: 9, day: 17
monthstr = October, year: 1990, month: 10, day: 18
monthstr = November, year: 1901, month: 11, day: 19
monthstr = December, year: 1903, month: 12, day: 21
year: 1903, month: 12, day: 21
```

# 9_52:
```cpp
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
```
```console
$ ./objectfile/ex9_52.o
type parenthesized expressions:
((3+4) + (4+5)) + 14
---------
----3+4-----
****(3+4) <-- replaced*****
---- + -----
----4+5-----
****(4+5) <-- replaced*****
---------
****((3+4) <-- replaced + (4+5) <-- replaced) <-- replaced*****
final contents of stack: 
 + 14
((3+4) <-- replaced + (4+5) <-- replaced) <-- replaced
```