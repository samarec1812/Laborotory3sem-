#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>

#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <fstream>


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
        if(denominator == 0) { throw 1;  }
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
    if(q == 0) {
        throw 2;  }
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
    /* ifstream input("input.txt");
     int num1=0, denom1 = 0, num2 =0, denom2 = 0 ; char c;
     if(input){
         input >> num1;
         input.ignore(1);

         input >> denom1;
         input.ignore(1);

         input >> c;
         input.ignore(1);

         input >> num2;
         input.ignore(1);

         input >> denom2;
     }*/
    try {

        Rational r1, r2;
        char c;
        cin >> r1 >> c >> r2;
       // cout << c << endl;


        if (c == '+') { cout << r1 + r2 << endl; }
        else if (c == '-') { cout << r1 - r2 << endl; }
        else if (c == '*') { cout << r1 * r2 << endl; }
        else if (c == '/') { cout << r1 / r2 << endl; }

    }     catch (int x) {
        if (x == 1) {
            std::cout << "Invalid argument";
        } else cout << "Division by zero";
    }
     // cout << num1 << " " << denom1 << " "<<c << " " << num2 <<" " << denom2;


    //cout << "OK" << endl;
    return 0;
}