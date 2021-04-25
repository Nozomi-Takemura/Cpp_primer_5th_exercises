#include<iostream>
using std::cout; using std::cin; using std::endl;
int main() {
unsigned  ac=0, ic=0, uc=0, ec=0, oc=0;
char ch;
while (std::cin >> ch) {
if (ch=='a')
  ++ac;
else if (ch=='i')
  ++ic;
else if (ch=='u')
  ++uc;
else if (ch=='e')
  ++ec;
else if (ch=='o')
  ++oc;
}
cout << "Number of vowel a: " << ac;
cout << "Number of vowel i: " << ic;
cout << "Number of vowel u: " << uc;
cout << "Number of vowel e: " << ec;
cout << "Number of vowel o: " << oc;




}

