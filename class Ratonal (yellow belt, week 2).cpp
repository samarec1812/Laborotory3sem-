  
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
/* 
int gcd (int a, int b) {
    while (b != 0) {
        int c = a % b;
        a =   b;
        b = c;
    }
    return a;
}
class Rational {
public:
    Rational() {
    num = 0;
    dem = 1;
        // Реализуйте конструктор по умолчанию
    }
    Rational(int numerator, int denominator) {
     if (numerator == 0 ) {
         num = 0;
         dem = 1;
     } else {
    int g = gcd (numerator, denominator);
    num = numerator / g;
    dem = denominator / g;
    if ((num < 0 && dem < 0) || (num > 0 && dem < 0)) {
    num *= -1;
    dem *= -1;
    }
    } // Реализуйте конструктор
//    cout << num << " " << dem << endl;
    }
    int Numerator() const {
     return num;        // Реализуйте этот метод
    }
    int Denominator() const {
       return dem;
    }
private:
    int num;
    int dem;
        // Добавьте поля
};
*/
void TestDefault() {
  Rational def;
  AssertEqual(def.Numerator(), 0, "Default construct. Num. must be 0");
  AssertEqual(def.Denominator(), 1, "Default constract. Den. must be 1");
}

void TestSimple(int num, int den, int n_ans, int d_ans, string comment) {
Rational One (num, den);
AssertEqual(One.Numerator(), n_ans, comment);
AssertEqual(One.Denominator(), d_ans, comment);
}

void TestConstructor() {
TestSimple(1, 2, 1, 2, "Not reduciable construct");
TestSimple(2, 4, 1, 2, "Reduciable construct");
TestSimple(-3, 4, -3, 4, "Negative num");
TestSimple(3, -4, -3, 4, "Negative den");
TestSimple(-5, -7, 5, 7, "Both negative, answer need to be pos");
TestSimple(-4, -8, 1, 2, "Negative reduciable");
TestSimple(0, 4, 0, 1, "Zeor num");
}
int main() {
  TestRunner runner;
  runner.RunTest(TestDefault, "Default construction");
  runner.RunTest(TestConstructor, "Defined construct");
  // добавьте сюда свои тесты
  return 0;