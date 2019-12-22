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

bool IsPalindrom(const string& str) {
/* /  for (int i = 0; i <= str.size(); i++) {
      if (str[i] != str[str.size()-i-1]) return false;
  } */
 // string str1;
 // for (auto a : str) {
 //   if (a == ' ') break;
 //   str1+=a;
 // }
  if (str.size() == 0 || str.size()==1) return true;
    int j = str.size();
  for (int i = 0; i <= j/2; i++) {
//    if (str1[i-1] != str1[j-i]) return false;
  
    if (str[i] != str[j-i-1]) return false;
  }
  return true;
}

void TestEmpty() {
  Assert(IsPalindrom(""), "Empty string");
  Assert(IsPalindrom("a"), "One symbol");
}

void TestPresets() {
  Assert(IsPalindrom("oneeno"), "Pal with even symbols");
  Assert(IsPalindrom("onefeno"), "Pal with odd synbols");
  Assert(IsPalindrom("o neren o"), "Pal with spaces");
  AssertEqual(IsPalindrom("eini"), false, "Pal if without first symbol");
  AssertEqual(IsPalindrom("inie"), false, "Pal if without last symbpl");
  AssertEqual(IsPalindrom("kjdskjfh"), false, "Not pal");
  AssertEqual(IsPalindrom("asjdhsa"), false, "Missing symbols");
  AssertEqual(IsPalindrom("asd hdsa"), false, "Pal if space is missing");
//  AssertEqual(IsPalindrom(" fgdaadgf"), false, "Space in front");
//  AssertEqual(IsPalindrom("fgdaadgf "), false, "Space in end");
  AssertEqual(IsPalindrom("asddsa;"), false, "Pal if ; missing");
  AssertEqual(IsPalindrom("s."), false, "Dots");
  AssertEqual(IsPalindrom("Asdffdsa"), false, "Ignoring register is wrong");
//  AssertEqual(IsPalindrom("asddsaihfgdjf") , false, "Working with half");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "Empty");
  runner.RunTest(TestPresets, "Presets");
  // добавьте сюда свои тесты
  return 0;
}