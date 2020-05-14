#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

template <typename Iterator>
class Page {
private:
  Iterator first;
  Iterator last;
  size_t page_size;

public:
  Page(Iterator f, Iterator l, size_t s)
  : first(f)
  , last(l)
  , page_size(s)
  {}

  Iterator begin() const{
    return first;
  }

  Iterator end() const {
    return last;
  }

  size_t size() const {
    return page_size;
  }
};

// Write class template Paginator
template <typename Iterator>
class Paginator {
private:
  vector<Page<Iterator>> pages;

public:
  Paginator(Iterator first, Iterator last, size_t size) {
    for (auto begin = first; begin < last; begin += size) {
      auto end = begin + size > last ? last : begin + size;

      pages.push_back(
        { begin, end, static_cast<size_t>(distance(begin, end)) }
      );

    }
  }

  auto begin() const {
    return pages.begin();
  }

  auto end() const {
    return pages.end();
  }

  size_t size() const {
    return pages.size();
  }
};

// Write function template Paginate
template <typename C>
auto Paginate(C& c, size_t page_size) {
     return Paginator{ c.begin(), c.end(), page_size };
}

