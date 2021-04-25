#include<iostream>
using std::cout; using std::cin; using std::endl;
int main() {
unsigned  ac=0, ic=0, uc=0, ec=0, oc=0;
char ch;
char prech;
while (std::cin.get() >> ch) {
switch (toupper(ch)) {
  case 'f':
    if (prech=='f')
      ++ac;
    prech='f';
    break;
  case 'l':
    if (prech=='f')
      ++ic;
    prech='l';
    break;
  case 'i':
    if(prech=='f')
      ++uc;
    prech='i';
}
prech=ch;
}
cout << "Number of vowel a: " << ac << endl; 
cout << "Number of vowel i: " << ic << endl;
cout << "Number of vowel u: " << uc << endl;
cout << "Number of vowel e: " << ec << endl;
cout << "Number of vowel o: " << oc << endl;

}
