
template <class T>
class SimpleVector {
public:

SimpleVector() {
  size_ = capacity_ = 0;
  data_ = end_ = nullptr;
}


SimpleVector( size_t size ) {
  capacity_ = size_ = size;
  data_ = new T[size];
  end_ = data_ + size_;
}

~SimpleVector() {
  delete[] data_;
}


T& operator[](size_t index) {
  return data_[index];
}


T* begin() {
  return data_;
}


T* end() {
  return end_;
}


const T* begin() const {
  return data_;
}


const T* end() const {
  return end_;
}


size_t Size() const {
  return size_;
}


size_t Capacity() const {
  return capacity_;
}


void PushBack(const T& value) {
  if (Size() == 0) {
    data_ = new T[++capacity_];
  } else if (Size() == Capacity()) {
    T* old_data = data_;
    capacity_ *= 2;
    data_ = new T[capacity_];

    for (size_t i = 0; i < Size(); ++i) {
      data_[i] = old_data[i];
    }

    delete[] old_data;
  }

  data_[size_++] = value;
  end_ = data_ + size_;
}
private:
  size_t size_;
  size_t capacity_;
  T* data_;
  T* end_;
};

