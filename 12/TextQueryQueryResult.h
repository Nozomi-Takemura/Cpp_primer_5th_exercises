#ifndef TEXTQUERYQUERYRESULT
#define TEXTQUERYQUERYRESULT
#include<vector>
#include<sstream>
#include<iostream>
#include<string>
#include<memory>
#include<fstream>
#include<set>
#include<map>
typedef std::vector<std::string> vec;
typedef std::set<std::size_t> sset;
class QueryResult{
  public:
    QueryResult() = default;
    QueryResult(std::shared_ptr<vec> ip_sp_lines,
        std::shared_ptr<std::map<std::string,sset>> ip_sp_word2lines,
        std::shared_ptr<std::map<std::string,std::size_t>> ip_sp_word2counts,
        const std::string &ip_word):
        sp_lines(ip_sp_lines), sp_word2lines(ip_sp_word2lines),
        sp_word2counts(ip_sp_word2counts), word(ip_word) { }

    // inline vec get_lines() {return *sp_lines;};
    // inline std::map<std::string, sset> get_word2lines() {return *sp_word2lines;};
    // inline std::map<std::string, std::size_t> get_word2counts() {return *sp_word2counts;};
    inline vec get_lines() const {return *sp_lines;};
    inline std::map<std::string, sset> get_word2lines() const {return *sp_word2lines;};
    inline std::map<std::string, std::size_t> get_word2counts() const {return *sp_word2counts;};

    static std::ostream& print(std::ostream&, const QueryResult);

  private:
    std::shared_ptr<vec> sp_lines = std::make_shared<vec>();
    std::shared_ptr<std::map<std::string,sset>> sp_word2lines;
    std::shared_ptr<std::map<std::string,std::size_t>> sp_word2counts;
    const std::string word;
};
class TextQuery{
  public:
    TextQuery() = default;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string &); 
    
  private:
    std::shared_ptr<vec> sp_lines = std::make_shared<vec>();
    std::shared_ptr<sset> sp_line_nums = std::make_shared<sset>();
    std::shared_ptr<std::map<std::string,sset>> sp_word2lines 
      = std::make_shared<std::map<std::string,sset>>();
    std::shared_ptr<std::map<std::string,std::size_t>> sp_word2counts
      = std::make_shared<std::map<std::string,std::size_t>>();
    void create_map(const std::string&);
};
TextQuery::TextQuery(std::ifstream &fin) {
  if(fin.is_open()){
    std::string line;
    while(std::getline(fin, line)){
      sp_lines->push_back(line);
    }
    for(const auto &aline : *sp_lines){
      std::string aword;
      std::istringstream ss(aline);
      while(ss >> aword){
        // if a word has already appeared, then skip
        auto it = sp_word2lines->find(aword);
        if(it  == sp_word2lines->end()){
          // std::cout << "test - " << aword << std::endl;
          create_map(aword);
        sp_line_nums->clear();
        }
      }
    }
  }
}
void TextQuery::create_map(const std::string& ip_word){
  std::size_t line_num = 1;
  std::size_t counts_total = 0;
  for(const auto line : *sp_lines){
    std::string word;
    std::istringstream ss(line);
    while(ss >> word){
      if(!word.compare(ip_word)){
        ++counts_total;
        auto i = (*sp_line_nums).count(line_num);
        if (i == 0 ){
          sp_line_nums->emplace(line_num);
          // std::cout << "current word: " << word << std::endl;
        }
      }
    }
   ++line_num;
  }
  (*sp_word2lines)[ip_word] = *sp_line_nums; 
  (*sp_word2counts)[ip_word] = counts_total;
}

QueryResult TextQuery::query(const std::string& word){
    return QueryResult(sp_lines, sp_word2lines, sp_word2counts, word);
}


std::ostream& QueryResult::print(std::ostream& op, const QueryResult qr){
  if(qr.get_word2lines().find(qr.word)!=(qr.get_word2lines().end())){
    std::cout << "element occurs " << qr.get_word2counts()[qr.word] << 
     ((qr.get_word2counts()[qr.word]>1)? " times":" time") << std::endl;
    //print line number and lines 
    //index number for vector of lines is line number - 1
    const auto aset = qr.get_word2lines()[qr.word]; 
    for (sset::iterator it = aset.cbegin(); 
        it != aset.cend(); ++it){
      std::cout << "   (line " << *it << ") " << (*qr.sp_lines)[*it-1] << std::endl;
    }
  }
  else{
    std::cout << qr.word << " is not appearing in the files." << std::endl;
  }
    return op;
}
#endif
