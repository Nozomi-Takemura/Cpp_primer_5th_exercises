#include <string>
#include <iostream>
using namespace std;

class Sandbox
{
public:
    Sandbox(const string& n) : member(n) {}
    const string& member;
};

int main()
{
    Sandbox sandbox(string("four"));
    cout << "The answer is: " << sandbox.member << endl;
    return 0;
}
