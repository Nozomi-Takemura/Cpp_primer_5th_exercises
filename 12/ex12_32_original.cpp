#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<map>
#include<string>
#include<new>
#include<set>
#include<sstream>
#include<algorithm>
using std::ifstream;
class QueryResult;
class TextQuery{
  public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    // QueryResult query(const std::string&) const;
    QueryResult query(const std::string&) const;
  private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,
      std::shared_ptr<std::set<line_no>>> wm;
};
TextQuery::TextQuery(std::ifstream& is): file(new std::vector<std::string>){
  std::string text;
  while(std::getline(is, text)){
    file->push_back(text);
    int n = file->size()-1;
    std::istringstream line(text);
    std::string word;
    while(line >> word) {
      auto &lines = wm[word];
      if(!lines){
        lines.reset(new std::set<line_no>);
      }
      std::cout << "----word: " << word << std::endl;
      lines->insert(n);
    }
  }
}
class QueryResult{
  friend std::ostream& print(std::ostream&, const QueryResult&);
  public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p, 
                std::shared_ptr<std::vector<std::string>> f):
      sought(s), lines(p), file(f) { }
  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
QueryResult TextQuery::query(const std::string& s) const {
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
  auto it = wm.find(s);
  if(it != wm.end()){
    std::cout << "----------- it->second -------" << it->second << std::endl;
    return QueryResult(s, it->second, file);
  }
    // return QueryResult(s, wm[s], file);
  else
    return QueryResult(s, nodata, file);
}
std::ostream& print(std::ostream& os, const QueryResult& qr){
try { 
  os << qr.sought << " occurs " << qr.lines->size() << " "
    << ((qr.lines->size()>1)? "time":"times") << std::endl;
  for (auto num : *(qr.lines)){
    os << "\t(line " << num + 1 << ") "
      << *(qr.file->begin()+num) << std::endl;
  }
} catch (const std::exception& e) { 
     std::cout << e.what() << std::endl; 
}
    // throw std::runtime_error("the word does not appear");
    return os;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);  //  store the file and build the query map
    while (true) {
      std::cout << "enter word to look for, or q to quit: ";
      std::string s;
      if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}
int main(int argc, char** argv){
  if(argc < 1)
    throw std::runtime_error("no input file.");
  std::ifstream fin(argv[1], std::ifstream::in);
  runQueries(fin);
}
