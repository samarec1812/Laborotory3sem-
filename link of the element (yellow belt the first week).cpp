#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <sstream>
using namespace std;

//для типов
template <typename T>
T Sqr(T value);

//Для словарей
template <typename Key, typename Value>

Value& GetRefStrict( map<Key, Value>& mapa , Key value){
    try{
        return mapa.at(value);
    }
    catch(out_of_range& err){
        throw runtime_error("Out of Range error");
    }
}


int main() {

    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}