#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <sstream>
using namespace std;

//для типов
template <typename T>
T Sqr(T value);

//Для векторов
template <typename T>
vector<T> Sqr(const vector<T>&vec);

//Для словарей
template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& mapa);

//Для пары
template <typename First, typename Second>
pair<First, Second> Sqr( const pair<First, Second>& para);

//реализация функции
template <typename T>
T Sqr(T value){
    return value * value;
}

template <typename T>
vector<T> Sqr (const vector<T>& vec){
    vector<T> answer;
    for(auto& w : vec){
        answer.push_back(Sqr(w));
    }
    return answer;
}
template<typename Key, typename Value>
map<Key, Value>Sqr(const map<Key, Value>& mapa){
    map<Key, Value>answer;
    for(auto& w: mapa){
        answer[w.first] = Sqr(w.second);
    }
    return answer;
}
template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& para){
    return {Sqr(para.first),Sqr(para.second) };
}


int main() {

    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}