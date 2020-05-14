#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

class Rational {
public:
    Rational() {
         numer =0;
         denomin = 1;
        // Реализуйте конструктор по умолчанию
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if(numerator == 0) { denominator = 1; }
        if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            } else if (numerator > 0) {
                denominator = abs(denominator);
                numerator = numerator * (-1);
            }
        }
int del1 = Del(abs(numerator), abs(denominator));
        numer =numerator/del1;
        denomin = denominator/ del1;
    }
    int Numerator() const {
        // Реализуйте этот метод
        return numer;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return denomin;
    }

private:
    int numer, denomin;
    int Del(int a, int b){
        while(a > 0 && b > 0){
            if(a > b) a %= b;
            else b %= a;
        }
return a+b;
    }
    // Добавьте поля
};
Rational operator+(const Rational& one, const Rational& two){
int p = one.Numerator()*two.Denominator() + two.Numerator()*one.Denominator();
int q = one.Denominator()*two.Denominator();
return Rational(p,q);
}
Rational operator-(const Rational& one, const Rational& two){
    int p = one.Numerator()*two.Denominator() - two.Numerator()*one.Denominator();
    int q = one.Denominator()*two.Denominator();
    return Rational(p,q);
}

bool operator==(const Rational& one, const Rational& two){
    if(two.Denominator() == one.Denominator()){
        if(one.Numerator() == two.Numerator()) return true;
        else return false;
    }else return false;
}
Rational operator*(const Rational& one, const Rational& two){
    int p = one.Numerator()*two.Numerator();
    int q = one.Denominator()*two.Denominator();
    return Rational(p,q);
}
Rational operator/(const Rational& one, const Rational& two){
    int p = one.Numerator()*two.Denominator();
    int q = one.Denominator()*two.Numerator();
    return Rational(p,q);
}
istream& operator>>(istream& stream, Rational& value){
    int m,n;
    if(stream >> m && stream.ignore(1) && stream >> n){
    value = {m,n};}
   // stream >> value.Denominator();
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& value){
    stream << value.Numerator()<<"/"<< value.Denominator();
    return stream;
}

bool operator > (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator < (Rational a, Rational b) { //обязательно нужно это дело перегрузить, для использования в map и set
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}
int main() {
    {
        const set<Rational> rs = { { 1, 2 },{ 1, 25 },{ 3, 4 },{ 3, 4 },{ 1, 2 } };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }
    cout << "OK" << endl;
    return 0;
}