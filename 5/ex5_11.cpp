#include<iostream>
using std::cout; using std::cin; using std::endl;
int main() {
unsigned  ac=0, ic=0, uc=0, ec=0, oc=0, tabc=0, spacec=0, newlinec=0;
char ch;
while (std::cin >> ch) {
switch (toupper(ch)) {
  case ('A'):
    ++ac;
    break;
  case 'I':
    ++ic;
    break;
  case 'U':
    ++uc;
    break;
  case 'E':
    ++ec;
    break;
  case 'O':
    ++oc;
    break;
  case ' ':
    ++spacec;
    break;
  case '\t':
//    if (prech=='\')
    ++tabc;
    break;
  case '\n':
//    if (prech=='\')
      ++newlinec;
    break;
}
//prech = ch;
}
cout << "Number of vowel a: " << ac << endl; 
cout << "Number of vowel i: " << ic << endl;
cout << "Number of vowel u: " << uc << endl;
cout << "Number of vowel e: " << ec << endl;
cout << "Number of vowel o: " << oc << endl;

cout << "Number of vowel tab: " << tabc << endl;
cout << "Number of vowel space: " << spacec << endl;
cout << "Number of vowel newline: " << newlinec << endl;
}
