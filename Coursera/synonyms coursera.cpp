//container set "synonyms"
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
using sorted_pair = pair<string, string>; //тут я решил намудрить, немного не по курсу. Так будут пары слов храниться
sorted_pair make_sorted_pair(const string& slovo1, const string& slovo2) { //эта функция будет возвращать отсортированные пары слов
    return (slovo1 <= slovo2) ? make_pair(slovo1, slovo2) : make_pair(slovo2, slovo1); //тут сортировка
}
bool check(const set<sorted_pair>& synonym, const string& word1, const string& word2) { //тут возвращаем...
    return synonym.count(make_sorted_pair(word1, word2)) != 0; //есть ли такая пара слов уже или нет
}
void add(set<sorted_pair>& synonym, map<string, unsigned>& synonyms_count, const string& word1, const string& word2) {
    if (check(synonym, word1, word2)) return;  //если синоним уже есть, то ничего не добавляем выходим
    ++synonyms_count[word1]; //если нет таких синонимов, то приплюсуем к каждому слову
    ++synonyms_count[word2];
    synonym.insert(make_sorted_pair(word1, word2)); //и добавим эти синонимы
}
int main() {
    set<sorted_pair> synonym;  // пары синонимов
    map<string, unsigned> synonyms_count;  // количество синонимов
    int Q;
    string comand, word1, word2;
    cin >> Q; //количество запросов
    for (int i = 0; i < Q; i++) {
        cin >> comand; //считываем команду
        if (comand == "ADD") { //проверяем какая команда пришла
            cin >> word1 >> word2; //считываем слова
            add(synonym, synonyms_count, word1, word2); //идем в функцию добавления
        }
        else if (comand == "COUNT") {
            string word;
            cin >> word; //считываем слово
            cout << synonyms_count[word] << endl; //проверим какая цифра стоит для этого слова
        }
        else if (comand == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2; //прочитали слова

            if (check(synonym, word1, word2)){ //если функция вернет true, то
                cout << "YES" << endl; //пишем Да
            }
            else cout << "NO" << endl; //иначе НЕТ
        }
    }
    return 0;
}