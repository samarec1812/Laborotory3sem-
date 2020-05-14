#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define THROW_EXCEPTION \
  if (index >= front_.size() + back_.size()) { \
    throw out_of_range("Index is out of range"); \
  }

#define GET_INDEX \
  if (index < front_.size()) { \
    return front_[front_.size() - 1 - index]; \
  } \
  return back_[index - front_.size()];

#define FRONT \
  return front_.empty() ? back_.front() : front_.back();

#define BACK \
  return back_.empty() ? front_.front() : back_.back();

template <typename T>
class Deque {
public:
  Deque() {}

  bool Empty() const {
    return front_.empty() && back_.empty();
  }

  size_t Size() const {
    return front_.size() + back_.size();
  }

  T& At(const size_t& index) {
    THROW_EXCEPTION
    GET_INDEX
  }

  const T& At(size_t index) const {
    THROW_EXCEPTION
    GET_INDEX
  }

  T& operator[](size_t index) {
    GET_INDEX
  }

  const T& operator[](size_t index) const {
    GET_INDEX
  }

  T& Front() {
    FRONT
  }

  const T& Front() const {
    FRONT
  }

  T& Back() {
    BACK
  }

  const T& Back() const {
    BACK
  }

  void PushFront(const T& value) {
    front_.push_back(value);
  }

  void PushBack(const T& value) {
    back_.push_back(value);
  }

private:
  vector<T> front_;
  vector<T> back_;
};

