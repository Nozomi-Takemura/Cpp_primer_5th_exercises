#ifndef STRBLOB
#define STRBLOB
#include<string>
#include<vector>
#include<memory>
#include<StrBlobPtr.h>
#include<ConstStrBlobPtr.h>
using std::string; 
using std::vector;
using std::make_shared;
class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr; //necessary to use 'a.data' in custructor
  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    inline size_type size() const {return (data->size());};
    inline bool empty() const {return data->empty();};
    // add/remove elements
    void push_back(const std::string& s) {data->push_back(s);};
    void pop_back();
    const string& front() const;
    const string& back() const;
    string& front();
    string& back();
    // using StrBlobPtr class
    // this avoid creating another shared_ptr incrementing ref count
    StrBlobPtr begin(){
      return StrBlobPtr(*this,0);//0 is actually not mandatory
    }
    StrBlobPtr end(){
      return StrBlobPtr(*this, data->size());
    }
  private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>()){};
StrBlob::StrBlob(std::initializer_list<string> il):
  data(std::make_shared<vector<string>>(il)){};

void StrBlob::check(size_type i, const string &msg) const{
  if(i >= data->size()){
    throw std::runtime_error(msg);
  }
};
void StrBlob::pop_back(){
  if(!empty()){
    data->pop_back();
  }
}
const string& StrBlob::front() const
{
  check(0,"front on empty StrBlob");
  return data->front();
}
const string& StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}
string& StrBlob::front()
{
  check(0,"front on empty StrBlob");
  return data->front();
}
string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

// this is a method for StrBlobPtr.h
StrBlobPtr::StrBlobPtr(): curr(0){ }
StrBlobPtr::StrBlobPtr(StrBlob& a, std::size_t sz): wptr(a.data), curr(sz) { }
ConstStrBlobPtr::ConstStrBlobPtr(): curr(0){ }
ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob& a, std::size_t sz): wptr(a.data), curr(sz) { }
#endif
