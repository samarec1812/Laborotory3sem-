#include <iostream>
#include <algorithm>


using namespace std;

template<typename T>
class SimpleVector{
public:
    SimpleVector(): data(nullptr), size(0), capacity(0){}
    explicit SimpleVector(size_t usize){
        data = new T[usize];
        size = usize;
        capacity = usize;
    }
    ~SimpleVector(){
        delete[] data;
    };
    void PushBack( const T& value){
        if(size == capacity) Add();
         *(data + size) = value;
         ++size;
        
    }
    T& operator[](size_t index){
        return data[index];
    }

    T* begin()  { return data + 0; } ;
    T* end()  { return data + size; };
    const T* begin() const { return data; } ;
    const T* end() const { return data + size; };

   size_t Capacity() const { return capacity;  }
   size_t Size() const { return size; }

    void Add(){
        if(capacity == 0){
            data = new T[1];
            capacity = 1;
            return;
        }
        capacity *=2; 
        T* pv = new T[2*capacity];
        for(size_t i = 0; i < size; i++){
            *(pv + i) = *(data + i);
        }
        delete [] data;
        data = pv;
    }

private:
    T* data;
   size_t size;
   size_t capacity;
};

