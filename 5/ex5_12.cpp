#include<iostream>
using std::cout; using std::cin; using std::endl;
int main() {
unsigned  ac=0, ic=0, uc=0, ec=0, oc=0;
char ch=NULL;
char prech=NULL;
while (std::cin.get() >> ch) {
  switch (toupper(ch)) {
    case 'F':
      if (prech=='f')
        ++ac;
      prech='f';
      break;
    case 'L':
      if (prech=='f')
        ++ic;
      prech='l';
      break;
    case 'I':
      if(prech=='f')
        ++uc;
      prech='i';
      break;
  
    default:
      cout << "ch-prech= " <<  ch <<  prech << endl;
      prech=ch;
      break;
  }
}
cout << "Number of vowel a: " << ac << endl; 
cout << "Number of vowel i: " << ic << endl;
cout << "Number of vowel u: " << uc << endl;
cout << "Number of vowel e: " << ec << endl;
cout << "Number of vowel o: " << oc << endl;

}

