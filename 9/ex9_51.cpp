#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class ymd {
  public:
    ymd() = default;
    ymd(string s) {
      if(s.find("/")!=string::npos){
        string::size_type sz1 = s.find_first_of("/");
        string::size_type sz2 = s.find_last_of("/");
        day = stoi(s.substr(0, sz1));
        month = stoi(s.substr(sz1+1, sz2));
        year = stoi(s.substr(sz2+1));
      }

      if(s.find(",")!=string::npos){
        const string cstr("JanuaryFebMchApilJgstSmbOoNvD");
        string monthstr;
        string::size_type sz1 = s.find_first_of(cstr);
        string::size_type sz2 = s.find_last_of(cstr);
        // string::size_type sz1 = s.find_first_of("JanuaryFebMchApilJgstSmbOoNvD");
        string::size_type sz3 = s.find_last_of(",");
        day = stoi(s.substr(sz2+1, sz3));
        year = stoi(s.substr(sz3+1));
        monthstr = stoi(s.substr(sz1+1, sz2));
        if (monthstr.find("Ja")!=string::npos)
          month = 1;
        else if (monthstr.find("Fe")!=string::npos)
          month = 2;
        else if (monthstr.find("Mar")!=string::npos)
          month = 3;
        else if (monthstr.find("Ap")!=string::npos)
          month = 4;
        else if (monthstr.find("May")!=string::npos)
          month = 5;
        else if (monthstr.find("Jun")!=string::npos)
          month = 6;
        else if (monthstr.find("Jul")!=string::npos)
          month = 7;
        else if (monthstr.find("Aug")!=string::npos)
          month = 8;
        else if (monthstr.find("Sep")!=string::npos)
          month = 9;
        else if (monthstr.find("Oct")!=string::npos)
          month = 10;
        else if (monthstr.find("Nov")!=string::npos)
          month = 11;
        else if (monthstr.find("DeJ")!=string::npos)
          month = 12;
      }

    }
    unsigned int get_year(){
      return year;
    }
    unsigned int get_month(){
      return month;
    }
    unsigned int get_day(){
      return day;
    }
  private:
    unsigned int year, month, day;
};

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
