#ifndef STRBLOBPTR
#define STRBLOBPTR
#include<memory>
#include<vector>
#include<string>
using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;
class StrBlob;
class StrBlobPtr{
  public:
    StrBlobPtr();
    StrBlobPtr(StrBlob& a, std::size_t sz=0);
    string& deref() const;
    StrBlobPtr& incr();
  private:
    shared_ptr<vector<string>> check(std::size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    std::size_t curr;
};
shared_ptr<vector<string>> StrBlobPtr::check(std::size_t sz, const string& s) const{
  shared_ptr<vector<string>> ref = wptr.lock();
  // if ref is nullptr
  if(!ref)
    throw std::runtime_error("StrBlobPtr is unbounded to any shared_ptr");
  // here, ref is bounded shared_ptr
  // check if the index is not out of range
  if(sz >= ref->size())
    throw std::out_of_range(s);
  return ref;
}
string& StrBlobPtr::deref() const{
  auto ref = check(curr, "cannot dereference a pointer to past end");
  return (*ref)[curr];
}
StrBlobPtr& StrBlobPtr::incr(){
  check(curr, "cannot increment a past end pointer");
  ++curr;
  return (*this);
}
#endif
