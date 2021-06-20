#include<iostream>
// #include<Sales_item.h>
#include<my_Sales_Item.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
using std::placeholders::_1;
using namespace std;
inline bool comparison(const Sales_item &rc_sal_ite1, const Sales_item &rc_sal_ite2){
  return rc_sal_ite1.isbn().size() < rc_sal_ite2.isbn().size();
  // return rc_sal_ite1.get_isbn().size() < rc_sal_ite2.get_isbn().size();
}
inline bool if_str_larger_than(const Sales_item &rc_sal_ite1, const Sales_item &rc_sal_ite2){
  return  rc_sal_ite1.isbn() < rc_sal_ite2.isbn();
  // for(const auto c : rc_sal_ite1)
}
inline bool differentisbn(const Sales_item &rc_sal_ite, const string &rcs){
  return rcs.compare(rc_sal_ite.isbn());
  // return rc_sal_ite.isbn() != rcs;
}
int main(){
 //read all Sales_item into vector<Sales_item> 
 istream_iterator<Sales_item> is_ite(cin), end;
 ostream_iterator<Sales_item> os_ite(cout, "\n");
 vector<Sales_item> v_sal_ite(is_ite, end);
 vector<Sales_item> v_sal_ite2;
 vector<Sales_item>::iterator pre_ite;
 vector<Sales_item>::iterator ite_at_new_bookNo;
 vector<string> v_bookNo;
 Sales_item sum_sal_ite;
 // print initial input
 cout << "-----input vector: -------" << endl;
 copy(v_sal_ite.cbegin(), v_sal_ite.cend(), os_ite);
 cout << endl;
 //sort the vector
 sort(v_sal_ite.begin(), v_sal_ite.end(), if_str_larger_than);
 //create new vector with unique bookNo
 unique_copy(v_sal_ite.cbegin(), v_sal_ite.cend(), back_inserter(v_sal_ite2),
     [] (const Sales_item &rc_sal_ite1, const Sales_item &rc_sal_ite2) 
     -> bool {rc_sal_ite1.if_bookNo_same(rc_sal_ite2);});
 //for each unique bookNo, calculate the sum of the revenue
 cout << "vector after preprocessing: " << endl;
 copy(v_sal_ite.cbegin(), v_sal_ite.cend(), os_ite);
 cout << endl;
 pre_ite = v_sal_ite.begin(); 
 for (const auto &rc_one_of_sal_ite2 : v_sal_ite2){
  sum_sal_ite = Sales_item(rc_one_of_sal_ite2.isbn());
  cout << "---- This is one of the unique bookNo: " << rc_one_of_sal_ite2.isbn() << " ----"<< endl;
  cout << "*pre_ite - " << *pre_ite << endl;
  ite_at_new_bookNo = find_if(pre_ite, v_sal_ite.end(), bind(differentisbn, _1,
        rc_one_of_sal_ite2.isbn()));
  // calculate sum so long as there's new bookNo record
  if(ite_at_new_bookNo != v_sal_ite.end()){
    cout << "*new_ite - " << *ite_at_new_bookNo << endl;
    cout << (pre_ite->isbn() == ite_at_new_bookNo->isbn()) << "<- if 1 then isbns are the same "<< endl;
    // write to the output stream
    cout << "new bookNo: " << (ite_at_new_bookNo->isbn()) << endl;
    *os_ite++ = accumulate(pre_ite,ite_at_new_bookNo , sum_sal_ite);
    cout << endl;
    // set the pre_ite to the current bookNo to calculate sum of Sales_item for next bookNo
    pre_ite = ite_at_new_bookNo;
    cout << "sum-test: " <<  accumulate(pre_ite,ite_at_new_bookNo, sum_sal_ite) << endl;
   }
 }
 cout << endl;
 // the summation for the final record still needs to be computed
 cout << "last bookNo: " << (sum_sal_ite.isbn()) << endl;
 *os_ite++ = accumulate(pre_ite,v_sal_ite.end(), sum_sal_ite);
 cout << endl;
}
