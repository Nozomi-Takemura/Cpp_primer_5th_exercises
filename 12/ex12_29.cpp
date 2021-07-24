#include<vector>
#include<sstream>
#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<map>
typedef std::vector<std::string> vec;
typedef std::set<std::size_t> sset;
typedef std::map<std::string,std::size_t> szmap;
typedef std::map<std::string,sset> setmap;
using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::cin;
void create_map(const std::string& ip_word, vec &lines, sset &line_nums,
    setmap &word2lines, szmap &word2counts){
  std::size_t line_num = 1;
  std::size_t counts_total = 0;
  for(const auto line : lines){
    std::string word;
    std::istringstream ss(line);
    while(ss >> word){
      if(!word.compare(ip_word)){
        ++counts_total;
        auto i = (line_nums).count(line_num);
        if (i == 0 ){
          line_nums.emplace(line_num);
          // std::cout << "current word: " << word << std::endl;
        }
      }
    }
   ++line_num;
  }
  (word2lines)[ip_word] = line_nums; 
  (word2counts)[ip_word] = counts_total;
}
void TextQuery(std::ifstream &fin, vec &lines, setmap& word2lines, sset &line_nums,
    szmap &word2counts) {
  if(fin.is_open()){
    std::string line;
    while(std::getline(fin, line)){
      lines.push_back(line);
    }
    for(const auto &aline : lines){
      std::string aword;
      std::istringstream ss(aline);
      while(ss >> aword){
        // if a word has already appeared, then skip
        auto it = word2lines.find(aword);
        if(it  == word2lines.end()){
          // std::cout << "test - " << aword << std::endl;
          create_map(aword, lines, line_nums,word2lines,word2counts);
        line_nums.clear();
        }
      }
    }
  }
}
std::ostream& print(std::ostream& op, setmap &word2lines, szmap &word2counts,
    vec &lines ,const std::string &word){
  if(word2lines.find(word)!=(word2lines.end())){
    std::cout << "element occurs " << word2counts[word] << 
     ((word2counts[word]>1)? " times":" time") << std::endl;
    //print line number and lines 
    //index number for vector of lines is line number - 1
    const auto aset = word2lines[word]; 
    for (sset::iterator it = aset.cbegin(); 
        it != aset.cend(); ++it){
      std::cout << "   (line " << *it << ") " << (lines)[*it-1] << std::endl;
    }
  }
  else{
    std::cout << word << " is not appearing in the files." << std::endl;
  }
    return op;
}
int main(int argc, char** argv) {
  if(argc < 1)
    throw std::runtime_error("no input file was found.");
  vec lines; 
  setmap word2lines;
  szmap word2counts;
  const std::string word;
  sset line_nums;
  
  std::ifstream fin(argv[1], std::ifstream::in);
  // create a map
  TextQuery(fin, lines, word2lines, line_nums, word2counts);
  // run query
  string s;
  do {
      cout << "enter a word to look for: ";
      cin >> s;
      print(cout,word2lines,word2counts,lines, s) << endl;
      cout << "enter q to quit: ";
      cin >> s;
  } while ((!s.empty()) and  s != "q");
  // while (true) {
      // cout << "enter word to look for, or q to quit: ";
      // string s;
      // if (!(cin >> s) || s == "q") break;
      // print(cout,word2lines,word2counts,lines, s) << endl;
  // }
}
