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
