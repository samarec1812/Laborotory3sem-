// работа с контейнерами шаблонных типов 

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <sstream>
using namespace std;


template <typename Collection>
string Join(const Collection& c, char d){
    stringstream ss;
    bool first = true;
    for( const auto& i : c ){
        if(!first){
            ss << d;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}
 template<typename T >
  ostream& operator<< (ostream& out, const vector<T>& v){
      return out << '[' <<Join(v, ',') << ']';
  }
  template <typename  First, typename  Second>

  ostream& operator<< (ostream& out, const pair<First, Second>& v){
          out  <<'(' <<  v.first << ',' << v.second  <<')';
      return out;
  }
template <typename Key, typename Value>
ostream& operator<< (ostream& out, const map<Key, Value>& v){

    return out << '{'<< Join(v, ',') << '}';
}

int main() {

    vector<vector<int>>a = {{1,0}, {2, 0}};
     cout << a << endl;
   auto p = make_pair(1,2);
   map<int, string>l ={{1, "str"}, {2, "SAMARA"}, {3, "Moscow"}};
cout << l << endl;

cout << max<int>(2,3.4);

    return 0;
}