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
