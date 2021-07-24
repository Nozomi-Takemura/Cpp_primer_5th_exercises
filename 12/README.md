# 12_1:
- `b1`: 4 elements
- `b2`: 0 elements (it is destroyed after exiting the scope)

# 12_2:
- ex12_02.cpp
```cpp
#include<StrBlob.h>
#include<iostream>
#include<string>
using std::cout;
using std::endl;
int main(){
  StrBlob b2 = {"a", "an", "the"};
  StrBlob b1;
  const StrBlob b3 = {"1","2","3"};
  string s;
  b1 = b2;
  b2.push_back("about");
  s = b1.back();
  b1.back() = "OverWrite";
  cout << "--- non const version ----" << endl;
  std::cout << "last element of b1 - " << s << std::endl;
  cout << "--- after chages----" << endl;
  std::cout << "last element of b1 - " << b1.back() << std::endl;
  const string s2 = b3.back();
  cout << "--- const version ----" << endl;
  std::cout << "last element of b1 - " << s2 << std::endl;
  // this raises error
  //b3.back() = "4";
}
```
- StrBlob.h
```cpp
#ifndef STRBLOB
#define STRBLOB
#include<string>
#include<vector>
#include<memory>
using std::string; 
using std::vector;
using std::make_shared;
class StrBlob {
  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    inline size_type size() const {return (data->size());};
    inline bool empty() const {return data->empty();};
    // add/remove elements
    void push_back(const std::string& s) {data->push_back(s);};
    void pop_back();
    const string& front() const;
    const string& back() const;
    string& front();
    string& back();
  private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>()){};
StrBlob::StrBlob(std::initializer_list<string> il):
  data(std::make_shared<vector<string>>(il)){};

void StrBlob::check(size_type i, const string &msg) const{
  if(i >= data->size()){
    throw std::runtime_error(msg);
  }
};
void StrBlob::pop_back(){
  if(!empty()){
    data->pop_back();
  }
}
const string& StrBlob::front() const
{
  check(0,"front on empty StrBlob");
  return data->front();
}
const string& StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}
string& StrBlob::front()
{
  check(0,"front on empty StrBlob");
  return data->front();
}
string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}
#endif
```
```console
$ g++ ex12_02.cpp -I ~/Cpp_primer_5th_exercises/12 -o  objectfile/ex12_02.o
$ ./objectfile/ex12_02.o
--- non const version ----
last element of b1 - about
--- after chages----
last element of b1 - OverWrite
--- const version ----
last element of b1 - 3

```
# 12_3:
- the const version of push_back and pop_back are not needed because these operations needs to modify the container itself; more specifically adding new elements and removing an existing elements. With const versions would not apply such changes to the container.

# 12_4:
- `data->size()` is greater than or equal to `0` so there is no need to check if `i` is geater than 0.

# 12_5:
- pros:
 - in some cases, it is easy to assigne a value to the class like `StrBlob b3 = {"1","2","3"};`
 - in other words, copy-form-initialization can become usable.
- cons: 
 - implicitely converted/constructed `StrBlob` object from initializer_list is a temporary object, and therefore it is discarded after the evaluation of the operation is done.

# 12_6:
```cpp
#include<new>
#include<memory>
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using std::cout; 
using std::cin;
using std::endl;
using std::vector;
using std::istream;
using std::ostream;
using std::endl;
vector<int>* create(vector<int>* pt)
{
 pt = new vector<int>();
 return pt;
}
istream& fill(vector<int>* pt, istream& in)
{
  int i;
  while(in >> i)
  {
    pt->push_back(i);
  }
  return in;
}
ostream& print(vector<int>* pt, ostream& op)
{
  // ostream_iterator<int>& op_ite(op, " ");
  // copy(pt->begin(), pt->end(), op_ite);
  for(const auto i : *pt)
    op << i << " ";
  delete pt;
  return op;
}
int main(){
  vector<int>* pt = nullptr;
  pt = create(pt);
  fill(pt, cin);
  print(pt, cout) << endl;
}
```
```console
$ ./objectfile/ex12_06.o 
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10 
```

# 12_7:
```cpp
#include<new>
#include<memory>
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using std::cout; 
using std::cin;
using std::endl;
using std::vector;
using std::istream;
using std::ostream;
using std::endl;
using std::shared_ptr;
using std::make_shared;
shared_ptr<vector<int>> create()//(shared_ptr<vector<int>> pt)
{
  return make_shared<vector<int>>(); 
}
istream& fill(shared_ptr<vector<int>> pt, istream& in)
{
  int i;
  while(in >> i)
  {
    pt->push_back(i);
  }
  return in;
}
ostream& print(shared_ptr<vector<int>> pt, ostream& op)
{
  // ostream_iterator<int>& op_ite(op, " ");
  // copy(pt->begin(), pt->end(), op_ite);
  for(const auto i : *pt)
    op << i << " ";
return op;
}
int main(){
  // vector<int>* pt = nullptr;
  auto pt = create();
  fill(pt, cin);
  print(pt, cout) << endl;
}
```
```console
$ ./objectfile/ex12_07.o 
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10 
```

# 12_8:
- after calling the function `b()`, there is no way to access nor delete the dynamically allocated memory inside this function. This is caused bacause the function returns a pointer to a dynamically allocated integer, but the returned pointer value is automatically converted into bool and thus is lost.

# 12_9:
- create two pointers, q and r, that point to dynamically allocate memory addresses for type int, which are respectively initialized with 42 and 100.
- assigne the pointer value of q to r
- create shared_ptr type q2 and r2 that points to the dynamically allocated memory location where integers, 42 and 100, are respectively  stored.
- the shared_ptr value of q2 is assigned to r2, simultaneously reducing the reference count of shared_ptr which r2 pointed and increasing the reference count of shared_ptr which q2 points to. 

# 12_10:
- This call is correct because the reference count of `p` is 1 after calling funciton `process`. Concretely, the creation of the temporal `shared_ptr<int>(p)` increments the reference count of `p` by 1 and then it is copied to the function's parameter further increasing the reference count by 1. These two objects are both deleted after the function `process` is called. 

# 12_11:
- `p.get()` returns a built in type pointer to the dynamically allocated memory. This implies that `shared_ptr<int>(p.get())` results in creating a temporal shared_ptr object which is independ from `p`, althogh they are actually pointing the same dynamically allocated memory. This means that each shared_ptr object has its own reference count with its value 1. Hence, after the call of `process`, the temporal shared_ptr is deleted and simultaneously the int object pointed by this pointer is destructed and the dynamically allocated memory is freed. At this moment, `p` becomes a `dangling` pointer since the dynamically allocated memory it points to is already freed. 

# 12_12:
- a. This is legal. The shared_ptr `sp` is copied to the parameter of process where the reference count of `sp` becomes 2. Once the call of `process` is done, the shared_ptr of parameter is destructed and the reference count of `sp` gets back to `1`. 
- b. This is illegal because a temporal shared_ptr object initialized from `new int()` is deleted after the call of `process` and simultaneously the dynamically allocated memory which was pointed by that temporal shared_ptr is freed.
- c. This is illegal because a temporal shared_ptr object implicitely constructed from a built in pointer type `p` is deleted after the call of `process` and simultaneously the dynamically allocated memory which was pointed by `p` is freed. This led `p` to becoming a `dangling` pointer.
- d. This is illegal because a temporal shared_ptr object explicitely constructed from a built in pointer type `p` is deleted after the call of `process` and simultaneously the dynamically allocated memory which was pointed by `p` is freed. This led `p` to becoming a `dangling` pointer.

# 12_13:
- This results in freeing dynamically allocated memory which is pointed by a shared_ptr `sp`. As a result, `sp` becomes a dangling pointer.

# [X] 12_14:
```cpp
```
```console
```

# 12_15:
```cpp
  shared_ptr<connection> p(&c, [](connection *ptr) -> void {disconnect(*ptr);});
```

# 12_16:
```cpp
#include<iostream>
#include<memory>
#include<string>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::string;
int main(){
  unique_ptr<string> uptr(new string("unique_ptr"));
  unique_ptr<string> uptr2(uptr);
}
```
```console
$ g++ ex12_16.cpp -o objectfile/ex12_16.o
ex12_16.cpp: In function ‘int main()’:
ex12_16.cpp:10:32: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]’
   unique_ptr<string> uptr2(uptr);
                                ^
In file included from /usr/include/c++/7/memory:80:0,
                 from ex12_16.cpp:2:
/usr/include/c++/7/bits/unique_ptr.h:383:7: note: declared here
       unique_ptr(const unique_ptr&) = delete;
       ^~~~~~~~~~
```
```cpp
#include<iostream>
#include<memory>
#include<string>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::string;
int main(){
  unique_ptr<string> uptr(new string("unique_ptr"));
  unique_ptr<string> uptr2;
  uptr2 = uptr;
}
```
```console
$ g++ ex12_16_assignment.cpp -o ex12_16_assignment.o
ex12_16_assignment.cpp: In function ‘int main()’:
ex12_16_assignment.cpp:11:11: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]’
   uptr2 = uptr;
           ^~~~
In file included from /usr/include/c++/7/memory:80:0,
                 from ex12_16_assignment.cpp:2:
/usr/include/c++/7/bits/unique_ptr.h:384:19: note: declared here
       unique_ptr& operator=(const unique_ptr&) = delete;
                   ^~~~~~~~
```

# 12_17:
- a. illegal: ix is not a pointer.
- b. illegal: pi is a builin pointer type - pi might become undefined when p1 is deleted
- c. illegal - pi2 can become undefined when p2 is deleted
- d. illegal: &ix is a builtin pointer type - pi can become undefined when p3 is deleted
- e. legal
- f. illegal: p2.get() is a builtin pointer type - pi2 can become undefined when p5 is deleted.

# 12_18:
- `shared_ptr` does not have `release` member because it does not neccesary to release `ownership` to enable other `shared_ptr`s to point to the same object.

# 12_19:
```cpp
//StrBlob.h
#ifndef STRBLOB
#define STRBLOB
#include<string>
#include<vector>
#include<memory>
#include<StrBlobPtr.h>
using std::string; 
using std::vector;
using std::make_shared;
class StrBlob {
  friend class StrBlobPtr;
  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    inline size_type size() const {return (data->size());};
    inline bool empty() const {return data->empty();};
    // add/remove elements
    void push_back(const std::string& s) {data->push_back(s);};
    void pop_back();
    const string& front() const;
    const string& back() const;
    string& front();
    string& back();
    // using StrBlobPtr class
    // this avoid creating another shared_ptr incrementing ref count
    StrBlobPtr begin(){
      return StrBlobPtr(*this,0);//0 is actually not mandatory
    }
    StrBlobPtr end(){
      return StrBlobPtr(*this, data->size());
    }
  private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>()){};
StrBlob::StrBlob(std::initializer_list<string> il):
  data(std::make_shared<vector<string>>(il)){};

void StrBlob::check(size_type i, const string &msg) const{
  if(i >= data->size()){
    throw std::runtime_error(msg);
  }
};
void StrBlob::pop_back(){
  if(!empty()){
    data->pop_back();
  }
}
const string& StrBlob::front() const
{
  check(0,"front on empty StrBlob");
  return data->front();
}
const string& StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}
string& StrBlob::front()
{
  check(0,"front on empty StrBlob");
  return data->front();
}
string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

// this is a method for StrBlobPtr.h
StrBlobPtr::StrBlobPtr(): curr(0){ }
StrBlobPtr::StrBlobPtr(StrBlob& a, std::size_t sz): wptr(a.data), curr(sz) { }
#endif
```
```cpp
// StrBlobPtr.h
#ifndef STRBLOBPTR
#define STRBLOBPTR
#include<memory>
#include<vector>
#include<string>
using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;
class StrBlob;
class StrBlobPtr{
  public:
    StrBlobPtr();
    StrBlobPtr(StrBlob& a, std::size_t sz=0);
    string& deref() const;
    StrBlobPtr& incr();
  private:
    shared_ptr<vector<string>> check(std::size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    std::size_t curr;
};
shared_ptr<vector<string>> StrBlobPtr::check(std::size_t sz, const string& s) const{
  shared_ptr<vector<string>> ref = wptr.lock();
  // if ref is nullptr
  if(!ref)
    throw std::runtime_error("StrBlobPtr is unbounded to any shared_ptr");
  // here, ref is bounded shared_ptr
  // check if the index is not out of range
  if(sz >= ref->size())
    throw std::out_of_range(s);
  return ref;
}
string& StrBlobPtr::deref() const{
  auto ref = check(curr, "cannot dereference a pointer to past end");
  return (*ref)[curr];
}
StrBlobPtr& StrBlobPtr::incr(){
  check(curr, "cannot increment a past end pointer");
  ++curr;
  return (*this);
}
#endif
```
```console
```

# 12_20:
```cpp
#include<fstream>
#include<StrBlob.h>
#include<iostream>
#include<string>
#include<sstream>
int main(int argc, char** argv){
  if(argc < 2)
    throw std::runtime_error("input file is missing.");
  std::ifstream fin(argv[1], std::ifstream::in);
  std::string input;
  StrBlob sb;
  if(fin.is_open()){
    std::getline(fin, input);
    std::stringstream ss(input);
    while(ss >> input)
      sb.push_back(input);
  }
  StrBlobPtr sbp(sb);
  // while(std::cout << sbp.deref()){
  std::size_t sz=0;
  while(sz!=sb.size()){
    std::cout << sbp.deref() << " ";
    sbp.incr();
    ++sz;
  }
  std::cout << std::endl;
}
```
```console
$ g++ ex12_20.cpp -I ~/Cpp_primer_5th_exercises/12 -o  objectfile/ex12_20.o
$ ./objectfile/ex12_20.o ex12_20.txt 
Your work is going to fill a large part of your life, and the only way to be truly satisfied is to do what you believe is great work. And the only way to do great work is to love what you do. If you haven't found it yet -- keep looking
```
```console
$ cat ex12_20.txt 
Your work is going to fill a large part of your life, and the only way to be truly satisfied is to do what you believe is great work. And the only way to do great work is to love what you do. If you haven't found it yet -- keep looking
```

# 12_21:
- original one in the below is better, for it gives a better readability and less chances to introduce syntax error.
```cpp
string& StrBlobPtr::deref() const{
  auto ref = check(curr, "cannot dereference a pointer to past end");
  return (*ref)[curr];
}
 ```

# 12_22:
- Constructor needs to be changed as `ConstStrBlobPtr(const StrBlob& a, std::size_t sz=0);`
```
```cpp
// ex12_22.cpp
#include<StrBlob.h>
#include<vector>
#include<string>
#include<iostream>
int main(){
  const StrBlob sb({"a","b","c"});
  ConstStrBlobPtr csbptr(sb);
  std::size_t sz = 0;
  while(sz!=sb.size()){
    std::cout << csbptr.deref() << " ";
    csbptr.incr();
    ++sz;
  }
  std::cout << std::endl;
}
```
```cpp
// StrBlob.h
#ifndef STRBLOB
#define STRBLOB
#include<string>
#include<vector>
#include<memory>
#include<StrBlobPtr.h>
#include<ConstStrBlobPtr.h>
using std::string; 
using std::vector;
using std::make_shared;
class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr; //necessary to use 'a.data' in custructor
  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    inline size_type size() const {return (data->size());};
    inline bool empty() const {return data->empty();};
    // add/remove elements
    void push_back(const std::string& s) {data->push_back(s);};
    void pop_back();
    const string& front() const;
    const string& back() const;
    string& front();
    string& back();
    // using StrBlobPtr class
    // this avoid creating another shared_ptr incrementing ref count
    StrBlobPtr begin(){
      return StrBlobPtr(*this,0);//0 is actually not mandatory
    }
    StrBlobPtr end(){
      return StrBlobPtr(*this, data->size());
    }
  private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>()){};
StrBlob::StrBlob(std::initializer_list<string> il):
  data(std::make_shared<vector<string>>(il)){};

void StrBlob::check(size_type i, const string &msg) const{
  if(i >= data->size()){
    throw std::runtime_error(msg);
  }
};
void StrBlob::pop_back(){
  if(!empty()){
    data->pop_back();
  }
}
const string& StrBlob::front() const
{
  check(0,"front on empty StrBlob");
  return data->front();
}
const string& StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}
string& StrBlob::front()
{
  check(0,"front on empty StrBlob");
  return data->front();
}
string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

// this is a method for StrBlobPtr.h
StrBlobPtr::StrBlobPtr(): curr(0){ }
StrBlobPtr::StrBlobPtr(StrBlob& a, std::size_t sz): wptr(a.data), curr(sz) { }
ConstStrBlobPtr::ConstStrBlobPtr(): curr(0){ }
ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob& a, std::size_t sz): wptr(a.data), curr(sz) { }
#endif
```
```cpp
// ConstStrBlobPtr.h
#ifndef CONSTSTRBLOBPTR
#define CONSTSTRBLOBPTR
#include<memory>
#include<vector>
#include<string>
using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;
class StrBlob;
class ConstStrBlobPtr{
  public:
    ConstStrBlobPtr();//: curr(0) { }
    ConstStrBlobPtr(const StrBlob& a, std::size_t sz=0);
    string& deref() const;
    ConstStrBlobPtr& incr();
  private:
    shared_ptr<vector<string>> check(std::size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    std::size_t curr;
};
shared_ptr<vector<string>> ConstStrBlobPtr::check(std::size_t sz, const string& s) const{
  shared_ptr<vector<string>> ref = wptr.lock();
  // if ref is nullptr
  if(!ref)
    throw std::runtime_error("StrBlobPtr is unbounded to any shared_ptr");
  // here, ref is bounded shared_ptr
  // check if the index is not out of range
  if(sz >= ref->size())
    throw std::out_of_range(s);
  return ref;
}
string& ConstStrBlobPtr::deref() const{
  auto ref = check(curr, "cannot dereference a pointer to past end");
  return (*ref)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr(){
  check(curr, "cannot increment a past end pointer");
  ++curr;
  return (*this);
}
#endif
```
```console
$ ./objectfile/ex12_22.o 
a b c 
```

# 12_23:
```cpp
#include<memory>
#include<iostream>
#include<string>
int main(){
  const char* cptr = "abcde""fghij";
  std::unique_ptr<char[]> uptr(new char[10]);
  // for (auto ptr = uptr, char* ptr2 = cptr; (ptr != uptr+10) and (
        // ptr2 != cptr+10); ++ptr,++ptr2){
  const char* ptr = cptr;
  for (std::size_t i = 0; i!=10; ++i){
    uptr[i] = *ptr++;
  }
  for (std::size_t i = 0; i!=10; ++i){
    std::cout << uptr[i] << " ";
  }
  std::cout << std::endl;
  uptr.reset();
  
  // string
  std::string s1("abcde");
  std::string s2("fghij");
  s1.append(s2);
  std::cout << s1 << std::endl;
}
```
```console
$ ./objectfile/ex12_23.o 
a b c d e f g h i j 
abcdefghij
```

# 12_24:
- since `std::cin.get()` requires maximum length of array, the characeters longer than the array size are simply lost.
```cpp
#include<memory>
#include<string>
#include<iostream>
int main(){
  std::cout << "type required array size" << std::endl;
  std::size_t sz;
  std::cin >> sz;
  std::unique_ptr<char[]> uptr(new char[sz]);
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  std::cout << "type input string" << std::endl;
  std::cin.get(uptr.get(),sz);
  // std::cin.get(cptr,10);
  for(std::size_t szt = 0; szt!=sz and uptr[szt]!='\0';++szt){
    std::cout << uptr[szt];
  }
  std::cout << std::endl << "this can contain memory leak" << std::endl;
  for(std::size_t szt = 0; uptr[szt]!='\0';++szt){
    std::cout << uptr[szt];
  }
  std::cout << std::endl;
}
```
```console
$ ./objectfile/ex12_24.o 
type required array size
5
type input string
12345
--output--
1234
this can contain memory leak
1234

$ ./objectfile/ex12_24.o 
type required array size
5
type input string
1234
--output--
1234
this can contain memory leak
1234

```

# 12_25:
- `delete[] pa;`
```cpp
```
```console
```

# 12_26:
```cpp
#include<string>
#include<memory>
#include<iostream>
int main(){
  std::allocator<std::string> alloc;
  std::size_t sz = 10;
  std::string s;
  std::string *const p = alloc.allocate(sz);
  std::string * q = p;
  while(std::cin >> s && q!=p+sz){
    alloc.construct(q, s);
    std::cout << *q << " ";
  }
  std::cout << std::endl;
  while(q!=p)
    alloc.destroy(--q);
  alloc.deallocate(p, sz);
}
```
```console
$ ./objectfile/ex12_26.o 
12 23 34 45 56 67 78
12 23 34 45 56 67 78 
```

# 12_27:
- ex12_27.cpp
```cpp
#include<iostream>
#include<fstream>
using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::cin;
#include<TextQueryQueryResult.h>
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);  //  store the file and build the query map
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        QueryResult::print(cout, tq.query(s)) << endl;
    }
}
int main(int argc, char** argv){
  if(argc > 0){
    std::ifstream fin(argv[1], std::ifstream::in);
    runQueries(fin);
  }
  else{
    throw std::runtime_error("no input file was found.");
  }
}
```
- TextQueryQueryResult.h
```cpp
#ifndef TEXTQUERYQUERYRESULT
#define TEXTQUERYQUERYRESULT
#include<vector>
#include<sstream>
#include<iostream>
#include<string>
#include<memory>
#include<fstream>
#include<set>
#include<map>
typedef std::vector<std::string> vec;
typedef std::set<std::size_t> sset;
class QueryResult{
  public:
    QueryResult() = default;
    QueryResult(std::shared_ptr<vec> ip_sp_lines,
        std::shared_ptr<std::map<std::string,sset>> ip_sp_word2lines,
        std::shared_ptr<std::map<std::string,std::size_t>> ip_sp_word2counts,
        const std::string &ip_word):
        sp_lines(ip_sp_lines), sp_word2lines(ip_sp_word2lines),
        sp_word2counts(ip_sp_word2counts), word(ip_word) { }

    // inline vec get_lines() {return *sp_lines;};
    // inline std::map<std::string, sset> get_word2lines() {return *sp_word2lines;};
    // inline std::map<std::string, std::size_t> get_word2counts() {return *sp_word2counts;};
    inline vec get_lines() const {return *sp_lines;};
    inline std::map<std::string, sset> get_word2lines() const {return *sp_word2lines;};
    inline std::map<std::string, std::size_t> get_word2counts() const {return *sp_word2counts;};

    static std::ostream& print(std::ostream&, const QueryResult);

  private:
    std::shared_ptr<vec> sp_lines = std::make_shared<vec>();
    std::shared_ptr<std::map<std::string,sset>> sp_word2lines;
    std::shared_ptr<std::map<std::string,std::size_t>> sp_word2counts;
    const std::string word;
};
class TextQuery{
  public:
    TextQuery() = default;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string &); 
    
  private:
    std::shared_ptr<vec> sp_lines = std::make_shared<vec>();
    std::shared_ptr<sset> sp_line_nums = std::make_shared<sset>();
    std::shared_ptr<std::map<std::string,sset>> sp_word2lines 
      = std::make_shared<std::map<std::string,sset>>();
    std::shared_ptr<std::map<std::string,std::size_t>> sp_word2counts
      = std::make_shared<std::map<std::string,std::size_t>>();
    void create_map(const std::string&);
};
TextQuery::TextQuery(std::ifstream &fin) {
  if(fin.is_open()){
    std::string line;
    while(std::getline(fin, line)){
      sp_lines->push_back(line);
    }
    for(const auto &aline : *sp_lines){
      std::string aword;
      std::istringstream ss(aline);
      while(ss >> aword){
        // if a word has already appeared, then skip
        auto it = sp_word2lines->find(aword);
        if(it  == sp_word2lines->end()){
          // std::cout << "test - " << aword << std::endl;
          create_map(aword);
        sp_line_nums->clear();
        }
      }
    }
  }
}
void TextQuery::create_map(const std::string& ip_word){
  std::size_t line_num = 1;
  std::size_t counts_total = 0;
  for(const auto line : *sp_lines){
    std::string word;
    std::istringstream ss(line);
    while(ss >> word){
      if(!word.compare(ip_word)){
        ++counts_total;
        auto i = (*sp_line_nums).count(line_num);
        if (i == 0 ){
          sp_line_nums->emplace(line_num);
          // std::cout << "current word: " << word << std::endl;
        }
      }
    }
   ++line_num;
  }
  (*sp_word2lines)[ip_word] = *sp_line_nums; 
  (*sp_word2counts)[ip_word] = counts_total;
}

QueryResult TextQuery::query(const std::string& word){
    return QueryResult(sp_lines, sp_word2lines, sp_word2counts, word);
}


std::ostream& QueryResult::print(std::ostream& op, const QueryResult qr){
  if(qr.get_word2lines().find(qr.word)!=(qr.get_word2lines().end())){
    std::cout << "element occurs " << qr.get_word2counts()[qr.word] << 
     ((qr.get_word2counts()[qr.word]>1)? " times":" time") << std::endl;
    //print line number and lines 
    //index number for vector of lines is line number - 1
    const auto aset = qr.get_word2lines()[qr.word]; 
    for (sset::iterator it = aset.cbegin(); 
        it != aset.cend(); ++it){
      std::cout << "   (line " << *it << ") " << (*qr.sp_lines)[*it-1] << std::endl;
    }
  }
  else{
    std::cout << qr.word << " is not appearing in the files." << std::endl;
  }
    return op;
}
#endif
```
```console
$ g++ ex12_27.cpp -I ~/Cpp_primer_5th_exercises/12 -o  objectfile/ex12_27.o
enter word to look for, or q to quit: I
element occurs 7 times
   (line 1) This was the closest I’ve been to facing death, and I hope it’s the closest I get for a few more decades.
   (line 2) Having lived through it, I can now say this to you with a bit more certainty than when death was a useful but purely intellectual concept.
   (line 19) When I was young, there was an amazing publication called The Whole Earth Catalog, which was one of the bibles of my generation.
   (line 25) It was the mid-1970s, and I was your age.
   (line 30) And I have always wished that for myself.
   (line 31) And now, as you graduate to begin anew, I wish that for you.

enter word to look for, or q to quit: they
element occurs 2 times
   (line 24) Stewart and his team put out several issues of The Whole Earth Catalog, and then when it had run its course, they put out a final issue.
   (line 28) It was their farewell message as they signed off.

enter word to look for, or q to quit: q
```
- ex12_27.txt
```console
This was the closest I’ve been to facing death, and I hope it’s the closest I get for a few more decades.
Having lived through it, I can now say this to you with a bit more certainty than when death was a useful but purely intellectual concept.
No one wants to die.
Even people who want to go to heaven don’t want to die to get there.
And yet death is the destination we all share.
No one has ever escaped it.
And that is as it should be, because Death is very likely the single best invention of Life.
It is Life’s change agent.
It clears out the old to make way for the new. Right now the new is you, but someday not too long from now, you will gradually become the old and be cleared away.
Sorry to be so dramatic, but it is quite true.

Your time is limited, so don’t waste it living someone else’s life.
Don’t be trapped by dogma — which is living with the results of other people’s thinking.
Don’t let the noise of others’ opinions drown out your own inner voice.
And most important, have the courage to follow your heart and intuition.
They somehow already know what you truly want to become.
Everything else is secondary.

When I was young, there was an amazing publication called The Whole Earth Catalog, which was one of the bibles of my generation.
It was created by a fellow named Stewart Brand not far from here in Menlo Park, and he brought it to life with his poetic touch.
This was in the late 1960s, before personal computers and desktop publishing, so it was all made with typewriters, scissors and Polaroid cameras.
It was sort of like Google in paperback form, 35 years before Google came along: It was idealistic, and overflowing with neat tools and great notions.

Stewart and his team put out several issues of The Whole Earth Catalog, and then when it had run its course, they put out a final issue.
It was the mid-1970s, and I was your age.
On the back cover of their final issue was a photograph of an early morning country road, the kind you might find yourself hitchhiking on if you were so adventurous.
Beneath it were the words: “Stay Hungry. Stay Foolish.”
It was their farewell message as they signed off.
Stay Hungry. Stay Foolish.
And I have always wished that for myself.
And now, as you graduate to begin anew, I wish that for you.

Stay Hungry. Stay Foolish.

Thank you all very much.
```

# 12_28_30:
```cpp
#include<vector>
#include<sstream>
#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<map>
typedef std::vector<std::string> vec;
typedef std::set<std::size_t> sset;
typedef std::map<std::string,std::size_t> szmap;
typedef std::map<std::string,sset> setmap;
using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::cin;
void create_map(const std::string& ip_word, vec &lines, sset &line_nums,
    setmap &word2lines, szmap &word2counts){
  std::size_t line_num = 1;
  std::size_t counts_total = 0;
  for(const auto line : lines){
    std::string word;
    std::istringstream ss(line);
    while(ss >> word){
      if(!word.compare(ip_word)){
        ++counts_total;
        auto i = (line_nums).count(line_num);
        if (i == 0 ){
          line_nums.emplace(line_num);
          // std::cout << "current word: " << word << std::endl;
        }
      }
    }
   ++line_num;
  }
  (word2lines)[ip_word] = line_nums; 
  (word2counts)[ip_word] = counts_total;
}
void TextQuery(std::ifstream &fin, vec &lines, setmap& word2lines, sset &line_nums,
    szmap &word2counts) {
  if(fin.is_open()){
    std::string line;
    while(std::getline(fin, line)){
      lines.push_back(line);
    }
    for(const auto &aline : lines){
      std::string aword;
      std::istringstream ss(aline);
      while(ss >> aword){
        // if a word has already appeared, then skip
        auto it = word2lines.find(aword);
        if(it  == word2lines.end()){
          // std::cout << "test - " << aword << std::endl;
          create_map(aword, lines, line_nums,word2lines,word2counts);
        line_nums.clear();
        }
      }
    }
  }
}
std::ostream& print(std::ostream& op, setmap &word2lines, szmap &word2counts,
    vec &lines ,const std::string &word){
  if(word2lines.find(word)!=(word2lines.end())){
    std::cout << "element occurs " << word2counts[word] << 
     ((word2counts[word]>1)? " times":" time") << std::endl;
    //print line number and lines 
    //index number for vector of lines is line number - 1
    const auto aset = word2lines[word]; 
    for (sset::iterator it = aset.cbegin(); 
        it != aset.cend(); ++it){
      std::cout << "   (line " << *it << ") " << (lines)[*it-1] << std::endl;
    }
  }
  else{
    std::cout << word << " is not appearing in the files." << std::endl;
  }
    return op;
}
int main(int argc, char** argv) {
  if(argc < 1)
    throw std::runtime_error("no input file was found.");
  vec lines; 
  setmap word2lines;
  szmap word2counts;
  const std::string word;
  sset line_nums;
  
  std::ifstream fin(argv[1], std::ifstream::in);
  // create a map
  TextQuery(fin, lines, word2lines, line_nums, word2counts);
  // run query
  while (true) {
      cout << "enter word to look for, or q to quit: ";
      string s;
      if (!(cin >> s) || s == "q") break;
      print(cout,word2lines,word2counts,lines, s) << endl;
  }
}
```
```console
$ ./objectfile/ex12_28.o ex12_27.txt
enter word to look for, or q to quit: I
element occurs 7 times
   (line 1) This was the closest I’ve been to facing death, and I hope it’s the closest I get for a few more decades.
   (line 2) Having lived through it, I can now say this to you with a bit more certainty than when death was a useful but purely intellectual concept.
   (line 19) When I was young, there was an amazing publication called The Whole Earth Catalog, which was one of the bibles of my generation.
   (line 25) It was the mid-1970s, and I was your age.
   (line 30) And I have always wished that for myself.
   (line 31) And now, as you graduate to begin anew, I wish that for you.

enter word to look for, or q to quit: now
element occurs 2 times
   (line 2) Having lived through it, I can now say this to you with a bit more certainty than when death was a useful but purely intellectual concept.
   (line 9) It clears out the old to make way for the new. Right now the new is you, but someday not too long from now, you will gradually become the old and be cleared away.

enter word to look for, or q to quit: q
```

# 12_29:
- `do while` loop is preferred because there is no need to use `break`.
```cpp
int main(int argc, char** argv) {
  if(argc < 1)
    throw std::runtime_error("no input file was found.");
  vec lines; 
  setmap word2lines;
  szmap word2counts;
  const std::string word;
  sset line_nums;
  
  std::ifstream fin(argv[1], std::ifstream::in);
  // create a map
  TextQuery(fin, lines, word2lines, line_nums, word2counts);
  // run query
  string s;
  do {
      cout << "enter a word to look for: ";
      cin >> s;
      print(cout,word2lines,word2counts,lines, s) << endl;
      cout << "enter q to quit: ";
      cin >> s;
  } while ((!s.empty()) and  s != "q");
}
```
```console
$ ./objectfile/ex12_29.o ex12_27.txt
enter a word to look for: now
element occurs 2 times
   (line 2) Having lived through it, I can now say this to you with a bit more certainty than when death was a useful but purely intellectual concept.
   (line 9) It clears out the old to make way for the new. Right now the new is you, but someday not too long from now, you will gradually become the old and be cleared away.

enter q to quit: 
f
enter a word to look for: now
element occurs 2 times
   (line 2) Having lived through it, I can now say this to you with a bit more certainty than when death was a useful but purely intellectual concept.
   (line 9) It clears out the old to make way for the new. Right now the new is you, but someday not too long from now, you will gradually become the old and be cleared away.

enter q to quit: q
```

# 12_31:
- `vector` is not suitable because it allows to store the same line number more than once.  

# 12_32:
```cpp
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<map>
#include<string>
#include<new>
#include<set>
#include<sstream>
#include<algorithm>
#include<StrBlob.h>
using std::ifstream;
class QueryResult;
// template <class T>
class TextQuery{
  public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    // QueryResult query(const std::string&) const;
    QueryResult query(const std::string&) const;
  private:
    // std::shared_ptr<std::vector<std::string>> file;
    // std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<StrBlob> file;
    std::map<std::string,
      std::shared_ptr<std::set<line_no>>> wm;
};
TextQuery::TextQuery(std::ifstream& is): file(new StrBlob){ 
// TextQuery::TextQuery(std::ifstream& is): file(new std::vector<std::string>){
  std::string text;
  while(std::getline(is, text)){
    file->push_back(text);
    int n = file->size()-1;
    std::istringstream line(text);
    std::string word;
    while(line >> word) {
      auto &lines = wm[word];
      if(!lines){
        lines.reset(new std::set<line_no>);
      }
      // std::cout << "----word: " << word << std::endl;
      lines->insert(n);
    }
  }
}
// template <class T>
class QueryResult{
  friend std::ostream& print(std::ostream&, const QueryResult&);
  public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p, 
                // std::shared_ptr<std::vector<std::string>> f):
                std::shared_ptr<StrBlob> f):
      sought(s), lines(p), file(f) { }
  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    // std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<StrBlob> file;
};
QueryResult TextQuery::query(const std::string& s) const {
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
  auto it = wm.find(s);
  if(it != wm.end()){
    // std::cout << "----------- it->second -------" << it->second << std::endl;
    // return QueryResult(s, it->second, file);
    return QueryResult(s, it->second, file);
  }
    // return QueryResult(s, wm[s], file);
  else
    return QueryResult(s, nodata, file);
}
std::ostream& print(std::ostream& os, const QueryResult& qr){
try { 
  os << qr.sought << " occurs " << qr.lines->size() << " "
    << ((qr.lines->size()>1)? "time":"times") << std::endl;
  for (auto num : *(qr.lines)){
    os << "\t(line " << num + 1 << ") ";
    auto it = qr.file->begin();
    while(num != 0){
      it.incr();
      --num;
    }
    std::cout  << it.deref() << std::endl;
  }
} catch (const std::exception& e) { 
     std::cout << e.what() << std::endl; 
}
    // throw std::runtime_error("the word does not appear");
    return os;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);  //  store the file and build the query map
    while (true) {
      std::cout << "enter word to look for, or q to quit: ";
      std::string s;
      if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}
int main(int argc, char** argv){
  if(argc < 1)
    throw std::runtime_error("no input file.");
  std::ifstream fin(argv[1], std::ifstream::in);
  runQueries(fin);
}
```
```console
$ g++ ex12_32.cpp -I ~/Cpp_primer_5th_exercises/12 -o  objectfile/ex12_32.o
$ ./objectfile/ex12_32.o ex12_27.txt
enter word to look for, or q to quit: now
now occurs 2 time
  (line 2) Having lived through it, I can now say this to you with a bit more certainty than when death was a useful but purely intellectual concept.
  (line 9) It clears out the old to make way for the new. Right now the new is you, but someday not too long from now, you will gradually become the old and be cleared away.
```

# 12_33:
- `TextQuery_QueryResult_LAST.h`
```cpp
#ifndef TextQuery_QueryResulti_LAST
#define TextQuery_QueryResulti_LAST
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<map>
#include<string>
#include<new>
#include<set>
#include<sstream>
#include<algorithm>
#include<StrBlob.h>
#include<StrBlobPtr.h>
#include<ConstStrBlobPtr.h>
using std::ifstream;
class QueryResult;
class TextQuery{
  public:
    // using line_no = std::vector<std::string>::size_type;
    using line_no = StrBlob::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
  private:
    std::shared_ptr<StrBlob> file;
    std::map<std::string,
    std::shared_ptr<std::set<line_no>>> wm;
};
class QueryResult{
  friend std::ostream& print(std::ostream&, const QueryResult&);
  public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p, 
                std::shared_ptr<StrBlob> f):
      sought(s), lines(p), file(f) { }
    inline std::set<TextQuery::line_no>::iterator begin() const {return lines->begin();}
    inline std::set<TextQuery::line_no>::iterator end() const {return lines->end();}
    inline std::shared_ptr<StrBlob> getfile() const {return file;}; 

  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<StrBlob> file;
};
// ---- definition for TextQuery ----
TextQuery::TextQuery(std::ifstream& is): file(new StrBlob){
  std::string text;
  while(std::getline(is, text)){
    file->push_back(text);
    int n = file->size()-1;
    std::istringstream line(text);
    std::string word;
    while(line >> word) {
      auto &lines = wm[word];
      if(!lines){
        lines.reset(new std::set<line_no>);
      }
      lines->insert(n);
    }
  }
}
QueryResult TextQuery::query(const std::string& s) const {
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
  auto it = wm.find(s);
  if(it != wm.end()){
    return QueryResult(s, it->second, file);
  }
  else
    return QueryResult(s, nodata, file);
}
// ---- definition for print ----
std::ostream& print(std::ostream& os, const QueryResult& qr){
  try { 
    os << qr.sought << " occurs " << qr.lines->size() << " "
      << ((qr.lines->size()>1)? "time":"times") << std::endl;
    for (auto num : *(qr.lines)){
      ConstStrBlobPtr cStrBlobPtr(*(qr.file), num);  
      os << "\t(line " << num + 1 << ") " << cStrBlobPtr.deref() << std::endl;
      }
    } catch (const std::exception& e) { 
      std::cout << e.what() << std::endl; 
    }
    return os;
}
#endif
```
