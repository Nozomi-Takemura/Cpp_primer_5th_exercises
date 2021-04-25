#include<iostream>
using std::cout; using std::cin; using std::endl;
int main() {
unsigned  ac=0, ic=0, uc=0, ec=0, oc=0, tabc=0, spacec=0, nlc=0, flc=0,ffc=0,fic=0;
char ch;
char prech;
  while (cin >> std::noskipws  >> ch) {
    switch (ch) {
      case 'a': case 'A':
        ++ac;
        break;
      case 'I':
        ++ic;
        break;
      case 'i':
        ++ic;
        if (prech=='f') ++fic;
      case 'u': case 'U':
        ++uc;
        break;
      case 'e': case 'E':
        ++ec;
        break;
      case 'o': case 'O':
        ++oc;
        break;
      case 'f':
        if (prech=='f')
          ++ffc;
        prech='f';
        break;
      case 'l':
        if (prech=='f')
          ++flc;
        prech='l';
        break;
      case ' ':
        ++spacec;
        break;
      case '\t':
        ++tabc;
        break;
      case '\n':
        ++nlc;
        break;
    }
  //  cout << "ch-prech= " <<  ch <<  prech << endl;
    prech=ch;
    cout << "ch = " << ch << endl; 
  }
  cout << "Number of vowel a: " << ac << endl; 
  cout << "Number of vowel i: " << ic << endl;
  cout << "Number of vowel u: " << uc << endl;
  cout << "Number of vowel e: " << ec << endl;
  cout << "Number of vowel o: " << oc << endl;
  cout << "Number of vowel ff: " << ffc << endl; 
  cout << "Number of vowel fi: " << fic << endl;
  cout << "Number of vowel fl: " << flc << endl;
  cout << "Number of vowel tab: " << tabc << endl;
  cout << "Number of vowel space: " << spacec << endl;
  cout << "Number of vowel newline: " << nlc << endl;

}

