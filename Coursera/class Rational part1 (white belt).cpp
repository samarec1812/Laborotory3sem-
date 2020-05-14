#include <iostream>
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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
