# 7_4and5:
- these functions should be `const` because the name and address information of person accessed by these functions are stored in an object instance and they are not supposed to be changed. 
```console
$./objectfile/ex7_4and5.o 
type your name;
Steve
type your address;
New York
output from your class:
Steve - New
```

# 7_6and7:
```console
$ ./objectfile/ex7_6and7.o 
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00

isbn: 0-201-78345-X, units_sold: 5, total revenue: 45
```

# 7_8:
- The `Sales_data` parameter of `read` is defined as a plain reference because inputs from stream have to be passed to the members of that object. If `reference to const` was used, such an assignment would not be allowed. On the other hand, `print` needs to pass the member values of `Sales_data` parameter to stream, and the values of the given `Sales_data` should not be changed inside function. Hence, parameter of a reference to const `Sales_data` suits better.

# 7_9:
```console
$ ./objectfile/ex7_9.o 
type your name;
type your address;
Steve NewYork
output from your class:
name: Steve, address: NewYork
```

# 7_10:
- [] The `if` condition checks if data1 and data2 are sequentially read from a stream without any issues.

# 7_11:
```console
$ ./objectfile/ex7_11.o 
type, booknr, nr of units, and price with space
booknr4 3 40
Sales_data initialized by 1st constructer:
isbn: , units_sold: 0, total revenue: 0
Sales_data initialized by 2nd constructer:
isbn: booknr1, units_sold: 0, total revenue: 0
Sales_data initialized by 3rd constructer:
isbn: booknr2, units_sold: 3, total revenue: 300
Sales_data initialized by 4th constructer:
isbn: booknr4, units_sold: 3, total revenue: 120
```

# 7_12:
```console
$ ./objectfile/ex7_12.o 
type, booknr, nr of units, and price with space
booknr5 4 10
Sales_data initialized by 1st constructer:
isbn: , units_sold: 0, total revenue: 0
Sales_data initialized by 2nd constructer:
isbn: booknr1, units_sold: 0, total revenue: 0
Sales_data initialized by 3rd constructer:
isbn: booknr2, units_sold: 3, total revenue: 300
Sales_data initialized by 4th constructer:
isbn: booknr5, units_sold: 4, total revenue: 40
```

# 7_13:
```console
$ ./objectfile/ex7_13.o 
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
0-202-12345-X 3 30.00
0-202-12345-X 4 4
0-202-12347-X 1 60.00
0-202-12346-X 7 3

isbn: 0-201-78345-X, units_sold: 5, total revenue: 110inside else 


isbn: 0-202-12345-X, units_sold: 7, total revenue: 106inside else 


isbn: 0-202-12347-X, units_sold: 1, total revenue: 60inside else 
isbn: 0-202-12346-X, units_sold: 7, total revenue: 21
```

# 7_14:
```console
$ ./objectfile/ex7_14.o 
isbn: , units_sold: 0, total revenue: 0<-- this is total
isbn: , units_sold: 0, total revenue: 0<-- this is trans
type the value for total 
xqort 8 10
type the value for trans 
gheno 9 40
isbn: xqort, units_sold: 8, total revenue: 80<-- this is total after read
isbn: gheno, units_sold: 9, total revenue: 360<-- this is trans after read
```

# 7_15:
```console
$ ./objectfile/ex7_15.o 
type your name;
type your address;
Steve NewYork
output from your class:
```

# 7_16:
- There are no restrictions on how often an access spedifier, e.g. public:, private:, is allowed to be appearing in a class definition.
- The members defining the interface should be defined after the "public" access specifier; for instance, constructors or other interface member functions for interface to a member.
- The members defining the implementation should be defined after the "private" access specifier: for instance, each member definition.

# 7_17:
- When "class" is used, the members defined before a first access specifier are private. On the other hand, the members defined before a first access specifier are public when "struct" is used.

# 7_18:
- Encapsulation is hiding the implementation of a class from its users and enforce them to use its interface. 
- Encapsulation is important because it lets users to simply use a class with its interface without knowing its detailed implementation. Furthermore, encapsulation prevent users from reaching inside a class object and meddling with its implementation.

# 7_19:
- private: name, address
- public: pop_name, pop_address, Person(), Person(std::istream& is)
- The members, `name` and `address` sould be declared as `private` because they are a part of implementation. On the other hand, the other members should be declared as `public` because they are to be used by users and a part of interface.

# 7_20:
- Friends are useful when there are functions that are not part of the members of a class, but they need to have acess to the implementation of the class. This is possible since a function/class made`friend` by another class is allowed to access to the nonpublic members of that class.
- One of the pros to use `friend` is that nonpublic members of a class can become accessible from outside of the class. On the other hand, one of the cons is that nonpublic members could be potentially meddled by a class or function declared with `friend`.

# 7_21:
```console
$ ./objectfile/ex7_21.o 
asf 4 50
asf 6 40
isbn: asf, units_sold: 10, total revenue: 440
```

# 7_22:
```console
$ ./objectfile/ex7_22.o 
type your name;
type your address;
Steve NewYork
output from your class:
name: Steve, address: NewYork
```

# 7_23:
```console
$ ./objectfile/ex7_23.o 
h=0, contents=
h=3, contents=aaaaaa
```

# 7_24:
```console
$ ./objectfile/ex7_23_26.o 
h=0, contents=
h=3, contents=aaaaaa<-- ex7_24, 3 arguments
h=0, contents=      <-- ex7_24, 2 arguments
```

# 7_25:
- Yes. This is because the Screen class is not allocating resources that reside outside the class objects. If this was the case, the copy, assignment synthesized by the compiler would not correctly work.
```console

```

# 7_26:
```console
$ ./objectfile/ex7_26.o
1234 4 30
1234 5 10
sdf 3 4
isbn: 1234, units_sold: 9, total revenue: 170, average_price18.8889inside else 

isbn: sdf, units_sold: 3, total revenue: 12, average_price4
```

# 7_27:
```console
$ ./objectfile/ex7_27.o 
h=0, contents=
h=3, contents=aaaaaa<-- ex7_24, 3 arguments
h=0, contents=      <-- ex7_24, 2 arguments
Screen() - contents: 
Screen(3,2,'a') - contents: aaaaaa
Screen(3,2) - contents:       
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX   
```

# 7_28:
- If `Screen` was the return type not `&Screen`, a temporary copied object would be returned during the member functions call. This means that the `set` member function of the copied onbject would be called subsequently, and contexts of myScreen would not be changed.

# 7 29:
- XXXXXXXXXXXXXXXXXXXX#XXXX
- XXXXXXXXXXXXXXXXXXXXXXXXX
```console
$ ./objectfile/ex7_29.o 
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

# 7_30:
- pro: easier to read and interpret the code.
- con: more time to write a code and inconsistancy coming from nonavailability to pass `this` as an explicit argument.

# 7_31:
```console
class Y
class X {
	Y* y;
};
class Y {
	X x;
};
```
# 7_32
```console
$ ./objectfile/ex7_32.o
h=0, contents=
h=3, contents=aaaaaa<-- ex7_24, 3 arguments
h=0, contents=      <-- ex7_24, 2 arguments
Screen() - contents: 
Screen(3,2,'a') - contents: aaaaaa
Screen(3,2) - contents:       
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
 <-- 0
aaaaaa <-- 1
       <-- 2
```

# 7_33
- It would raise an error `no return statement in function returning no-void` because pos is not known outside of the `Screen` class; until the compiler reads the class name of definition of `size`, the scope is outside of the class. It needs to be fixed as follows:
```cpp
Screen::pos Screen::size() const{
  return (*this).w * (*this).h;
}
```
```console
$ ./objectfile/ex7_33.o 
h=0, contents=
h=3, contents=aaaaaa<-- ex7_24, 3 arguments
h=0, contents=      <-- ex7_24, 2 arguments
Screen() - contents: 
Screen(3,2,'a') - contents: aaaaaa
Screen(3,2) - contents:       
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
 <-- 0
aaaaaa <-- 1
       <-- 2
NNNN <-- ex7_33
ex7_33 - size of Screen(3,2,'a'): 6
```

# 7_34:
```cpp
int height;   // defines a name subsequently used inside Screen
class Screen {
public:
    typedef std::string::size_type pos;
    void dummy_fcn(pos height) {
        cursor = width * height; // which height? the parameter
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
};
```
- If the `typedef` of `pos` was put as the last line in the class, an compilation error would be raised. The error would arise because the type used for the `height` parameter of `dummy_fct` would not be able to be resolved. This is because the compiler would find `pos` not to have been yet declared when compling the declaration of `dummy_fcn`.

# 7_35:
```cpp
typedef string Type; // define an alias of string type, Type
Type initVal(); // define global function with return type Type
class Exercise { // define Exercise class
public:
    typedef double Type; // (re)define an alias of dobule as Type
    Type setVal(Type); // declare setval member function taking Type (string)
    Type initVal(); // (re)declare initVal member function, hiding the declaration of initVal in the outer scope
private:
    int val; // declare val as int
};
Type Exercise::setVal(Type parm) { // define setVal member function to take Type(double) parm and return Type(string) 
    val = parm + initVal(); // error
    return val; // error: 
}
```
- During the compilation of the declaration of `setVal`, both of the return and input parameter types are `Type(=double)`. However, when the compiler reads the definition of `setVal`, its return type is `Type(=string)`. This mismatch results in a compilation error `prototype for <member function> does not match any in class Exersize`. This issue can be fixed as follows:
```cpp
#include <string>
using namespace std;
typedef string Type; // define an alias of string type, Type
Type initVal(); // define global function with return type Type
class Exercise { // define Exercise class
public:
    typedef double Type; // error: redefinition of a type 
    Type setVal(Type);
    Type initVal();
private:
    int val;
};
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
- By explicitly specify the scope of the return type for the definition of`setVal` as `Exercise::Type`, the error can be fixed.

# 7_36:
- The order of construter initializer is not aligned with the order of members, which causes an error. Basically, `rem` is tried to be initialized firstly, but it fails due to `j` which has been undefined yet at this point. The issue can be fixed by changing the order of members appearning in the class. 
```cpp
struct X {
  X (int i, int j): base(i), rem(base % j) { }
  int base, rem;
};
```

# 7_37:
```cpp
Sales_data first_item(cin); 
int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
}
```
- `first_itme`: the constructor `Sales_data(std::istream& is)` is used, and the values of the data members depend on user input.
- `next`: the constructor `Sales_data(std::string s="")` is used, and the value of each member is `bookNo="", units_sold=0, revenue=0`.
- `last`: the constructor `Sales_data(const std::string& s, unsigned cnt, double rev)` is used, and the value of each member is `bookNo="9-999-99999-9", units_sold=0, revenue=0`.
```console
$ ./ex7_37.o 
123 2 20
isbn: 123, units_sold: 2, total revenue: 40, average_price20<-- member values for first_ite initializer
isbn: , units_sold: 0, total revenue: 0, average_price-nan<-- member values for next initializer
isbn: 9-999-99999-9, units_sold: 0, total revenue: 0, average_price-nan<-- member values for last initializer
```

# 7_38:
```cpp
Sales_data(std::istream& is = std::cin) {is >> (*this).bookNo;  }
```
```console
$ ./objectfile/ex7_38.o 
123
isbn: 123, units_sold: 0, total revenue: 0, average_price-nan<-- member values for next initializer
```

# 7_39:
- It is not legal for more than two constructors to have default arguments because the call of overloaded default constructer initialization `Sales_data()` is ambiguos. In this case, the compiler cannot determine `Sales_data()` may mean requesting a user input or filling an empty string for `bookNo`.
```cpp
Sales_data(std::string s = ""): bookNo(s) { }
Sales_data(std::istream& is = std::cin) {is >> (*this).bookNo;  }
```
```console
$ g++ ex7_39.cpp -o ./objectfile/ex7_39.o
ex7_39.cpp: In function ‘int main()’:
ex7_39.cpp:58:16: error: call of overloaded ‘Sales_data()’ is ambiguous
     Sales_data next;
                ^~~~
ex7_39.cpp:10:5: note: candidate: Sales_data::Sales_data(std::istream&)
     Sales_data(std::istream& is = std::cin) {is >> (*this).bookNo;  }
     ^~~~~~~~~~
ex7_39.cpp:9:5: note: candidate: Sales_data::Sales_data(std::__cxx11::string)
     Sales_data(std::string s = ""): bookNo(s) { }
     ^~~~~~~~~~
```

# 7_40:
- `Book`: each book needs the following members
- - members: `title`, `Author`, `NrPages`, `genre`
- - 
```console
$ ./objectfile/ex7_49.o
Onepiece OdaEichiro 100 manga
Book A - default constructor initialization: 
tile:, aurthor:, NrPages:0, genre:
Book B - initialization passing all 4 member values: 
tile:HarryPotter, aurthor:JKRolling, NrPages:560, genre:fantazy
Book C - initialization with user input: 
tile:Onepiece, aurthor:OdaEichiro, NrPages:100, genre:manga
```
```cpp
#include <string>
#include <iostream>
class Book{
  //friend Book read(std::istream& is, Book& rbk);
  friend std::ostream& print(std::ostream& os, const Book& crbk);
  public:
    Book(std::string s = "", int i = 0): title(s), aurthor(s), NrPages(i), genre(s) { }
    Book(const std::string& ti, const std::string& au, const int np, const std::string ge): title(ti), aurthor(au), NrPages(np), genre(ge) { }
    Book(std::istream& is) {
      read (is, *this);
    }
//    std::istream& read(std::istream& is, Book& rbk);
    std::istream& read(std::istream& is, Book& rbk){
      is >> rbk.title >> rbk.aurthor >> rbk.NrPages >> rbk.genre;
      return is;
    }
  private:  
    std::string title;
    std::string aurthor;
    int NrPages = 0;
    std::string genre;
};
std::ostream& print(std::ostream& os, const Book& crbk){
  os << "tile:" << crbk.title << ", aurthor:" << crbk.aurthor << ", NrPages:" << crbk.NrPages << ", genre:" << crbk.genre;
  return os;
}
int main(){
  Book A;
  Book B("HarryPotter", "JKRolling", 560, "fantazy");
  Book C(std::cin);
  std::cout << "Book A - default constructor initialization: " << std::endl;
  print(std::cout, A) << std::endl;
  std::cout << "Book B - initialization passing all 4 member values: " << std::endl;
  print(std::cout, B) << std::endl;
  std::cout << "Book C - initialization with user input: " << std::endl;
  print(std::cout, C) << std::endl;
}
```

# 7_41:
```console
$ ./objectfile/ex7_41.o 
all three param-input const initi
default const initi
AAA 2 30
const init - istream input
isbn: AAA, units_sold: 2, total revenue: 60, average_price30<-- member values for first_ite initializer
all three param-input const initi
default const initi
isbn: , units_sold: 0, total revenue: 0, average_price-nan<-- member values for next initializer
all three param-input const initi
bookNo-para const initi
isbn: 9-999-99999-9, units_sold: 0, total revenue: 0, average_price-nan<-- member values for last initializer
all three param-input const initi
isbn: 9-999-99999-9, units_sold: 20, total revenue: 1000, average_price50<-- member values for lasttwo initializer
```
# 7_42:
```console
$ ./objectfile/ex7_42.o
delegated-to const-init
default const-init
delegated-to const-init
delegated-to const-init
default const-init
Norway'sforecast HarukiMurakami 500 HardBoiled
const-inits istream
Book A - default constructor initialization: 
tile:, aurthor:, NrPages:0, genre:
Book B - initialization passing all 4 member values: 
tile:HarryPotter, aurthor:JKRolling, NrPages:560, genre:fantazy
Book C - initialization with user input: 
tile:Norway'sforecast, aurthor:HarukiMurakami, NrPages:500, genre:HardBoiled
```

# 7_43:
```console
$ g++ ex7_43.cpp -o ./objectfile/ex7_43.o
/tmp/ccLpZ3ue.o: In function `C::C(int)':
ex7_43.cpp:(.text._ZN1CC2Ei[_ZN1CC5Ei]+0x1c): undefined reference to `NoDefault::NoDefault(int)'
collect2: error: ld returned 1 exit status
```
```cpp
#include <iostream>
class NoDefault{
  public:
    NoDefault(int i) ;
};
struct C{
    //C() = default;
    C(int i = 0): cmember(i) { }
    //C(int i): cmember(i) { }
    NoDefault cmember;
};
int main(){
  C c;
//  std::cout << c.cmember << std::endl;
}
```

# 7_44:
- Illegal. This is because that there is two ristrictions on value initialization and the declaration `vector<NoDefault> vec(10)` violates one of it. More specifically, when a `vector` holds objects of a type that cannot be default initialized, which is the case for `Nodefault` class because it does not have default initializer, an initial element value must be supplied as well as the size of `vector`.

# 7_45:
Legal because class `C` has the default constructer initializer.

# 7_46:
- [] a. Untrue. If no constructors are supplied, a synthesized constructor will perform the default constructor initilization so long as built-in types or class-types with default constructor initialization for members are used.
- [] b. Untrue. A default constructor can take non-empty parameter list when a parameter with the specific argument for initialization is given. If keyword `<Classname>() = default` is used for default constructor initialization, then the parameter list is indeed empty.   
- [] c. Untrue. Without a default constructor of a class, an object of the class type could not be instantiated without arguments or another class which has a member of that class could encounter the issue in a default initialization. Hence, it is always better to provide a default constructor.
- [X] d. Untrue. If a class does not define a default constructor, the compiler generates one. However, it does not initialize the data member to the default value of its associated type.

# 7_47:
- the `Sales_data` constructor that takes a `string` should be `explicit` because it is not really useful to call a member function with an argument of a temporary `Sales_data` object which has 0 `units_sold` and 0 `revenue`-
- The benefits of making the constructor `explicit` is that you can avoid an implicit conversion from a type to a class type.
- The drawbacks of using `explicit` are that the `temporary object`s are no longer automatically created, and hence explicitly created.

# 7_48:
```cpp
string null_isbn("9-999-99999-9"); // explicit conversion from const char* to string - direct initialization
Sales_data item1(null_isbn); // explicit conversion from string to Sales_data - direct initialization
Sales_data item2("9-999-99999-9"); // implicit conversion from const char* to string, and explicit conversion from string to Sales_data - 
```
- [X] Even if `Sales_data` constructor are explicit, all the definitions still work because they don't contain any implicit conversion from sting to Sales_data. The first and second are just normal initialization. The third one includes the implicit conversion/indirect initialization of string, and it is used as an argument for direct initialization of Sales_data.

# 7_49:
- key: the compiler does not allow to make a reference to a temporary object. (you can make a reference to a temporary object, but once the scope goes out of the expression, the temporary oject is gone and a dangling reference issue can occur.)
- [] a. Works. `s` is implicitly converted to `Sales_data` by creating a temporary object `Sales_data`. This object is then copied and passed to the `combine` function and it is combined to `i` and the reference to `i` is returned.
- [X] b. Fails. `s` is implicitly converted to `Sales_data` by creating a temporary object `Sales_data`. Then this object is passed by reference to the function. However, after the evaluation of assignment(binding) of constructed Sales_data, the temporary object is removed. Hence the operation inside combine would encounter an issue.
- [X] c. Fails. `s` is implicitly converted to `Sales_data` by creating a temporary object `Sales_data`. --Then from this object, another temporary object of the type `const Sales_data&` is created-- This temporary object is bined to const reference to Sales_data as such its life time is prolonged.  --and the operation in combine would work without any issues.-- Nevertheless, this still fails becuase `const this` is passed and therefore no changes on `this` is allowed.  As a result, new Sales_data transaction cannot be combined to `i`.

# 7_50:
- [X] It depends on the user requirements/design choices. Among the constructors of `Person` class, only `Person(std::istream& is)` constructor takes one parameter, so this is the only candidate for addking `explicit`. By default, when `Person` class type is expected, the implicit conversion is done from the class type `std::istream&` to `Person`. If this is not what the users/designers want, then `explicit` prevent this from occurring.

# 7_51:
- *vector* defined its single-argument constructor as *explicit* because it dones not really make sense to allow implicit conversion from *int* give for the size of a vector to uninitialized *vector* of the given size. Remembering that a *reference* to a *temporary object* only exists during the evaluation of the expression, and any operations inside the function intended to be applied for the original *vecotr* do not work. You can make a such reference by defining the function's parameter as *const Person&*, but there's no point to pass the empty *const* object. Hence, it is always make sense to prohibit the implicit conversion only from the *size*-related information.    

# 7_52:
```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```
- [X] The usage `Sales_data item = {"978-0590353403", 25, 15.99};` is only allowed for aggregated classes. Since agreegated classes are not allowed to have in-class initialier, the original `Sales_data`  class should be
```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

# 7_53:
- See the `cpp` file

# 7_54:
- [X] `void set_hw(bool b) { hw = b; }` should be defined as `constexp` because this member function takes a `bool` type as its parameter and it is a literal type so the expression can be evaluated during the compile-time. Moreover, in `C++14`, `void` is a `literal` type so it is allowed to add `constexpr`.

# 7_55:
- the *Data* class is a `literal` type because it is a *aggrefate* class whose `member`s are all `literal` type.

# 7_56:
- A `static` class member is a `member` associated to a class not a specific instance of that class object, and it exits during the program execution and accessible from outside of the class scope.
- [X] The advantages of `static` members are efficiency. Since `static` members are not a class member, an object instance of the class does not have them, but they are associated to the class itself. As a result, regardless how many instances of the object classs are defined, only one `static` member definition needs to be stored.
- [X] Another advantage is that changes applied to the `static` class members values automatically reflected to all of the instances of the class object. Hence, there is no need to change the value for each of them.
- [X] `static` type is an imcomplete time therefore, it can be defined as the same class type of the class
- [X] `static` class members are not defined during the object creation of the class type, because they are not part of those indivisual objects. 
- [X]`static` class member functions do not have `this` pointer because they are not bound to the objects of the class.

# 7_57:
- see the `cpp` file.

# 7_58:
```cpp
// example.h
class Example {
public:
    static double rate = 6.5; //should be static double rate || constexpr static double rate = 6.5; 
    static const int vecSize = 20; // should be static constexpr int vecSize = 20;
    static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate; // should be double Examples::rate = 6.5;
vector<double> Example::vec;
```
- `static double rate = 6.5;`: no need for in-class initialization because it is not used for initialization of any other members and hence there is no point to initialize inside a class. Or `constexpr` is mandatory if the initialization with the literal `=6.5` is used.
- `static const int vecSize = 20`: this makes sense because it is necessary to initialize `vec`.
-  if static class member is used for definition of another class member, then it needs to be defined inside the class.
- `static vector<double> vec(vecSize);`: this fails because `vector<Type> obj_name()` is not allowed inside a class.
- the memory allocation for `vector` type is done dynamically not statistically; in other words, its size cannot be fixed at compile time as opposed to `array` type. Hence, either `array` should be used or non-static `vector` should be declared inside class.
- `double Example::rate;`: here the definition `=6.5` should be used outside the class definition.
- --`vector<double> Example::vec;`: definitions should be given? --
- missing `const int Example::vecSize`: even when `static` object is in-class initialized, its definition should be defined outside the class. However, in such a case, the member's definition must not include an initial value because it is already specified insdie the inclass definition.