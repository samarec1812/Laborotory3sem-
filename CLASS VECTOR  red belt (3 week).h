#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template<typename T>
class SimpleVector {
public:
    SimpleVector() {
        _vector = nullptr;
        _size = 0;
        _capacity = 0;
    }

    explicit SimpleVector(size_t size) {
        _vector = new T[size];
        _size = size;
        _capacity = size;
    }

    ~SimpleVector() {
        delete[] _vector;
    }


    T &operator[](size_t index) { return *(_vector + index); }

    T *begin() { return (_vector + 0); }

    T *end() { return (_vector + _size); }

    size_t Size() const { return _size; }

    size_t Capacity() const { return _capacity; }

    void PushBack(const T &value) {
        if (_size == _capacity) IncreaseCapacity();
        *(_vector + _size) = value;
        ++_size;
    }

private:
    // Добавьте поля для хранения данных вектора
    T *_vector;
    size_t _size;
    size_t _capacity;

    void IncreaseCapacity() {
        if (_capacity == 0) {
            _vector = new T[1];
            _capacity = 1;
            return;
        }

        _capacity *= 2;
        T *temp = new T[_capacity];
        for (auto i = 0; i < _size; ++i) {
            *(temp + i) = *(_vector + i);
        }
        delete[] _vector;

        _vector = temp;
    }

};