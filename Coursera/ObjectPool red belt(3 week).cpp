#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate();
    T* TryAllocate();

    void Deallocate(T* object);

    ~ObjectPool();

private:
    // Добавьте сюда поля
    set<T*> dediced ;
    queue<T*>realesed;
};

template<class T>
T *ObjectPool<T>::Allocate() {
   if(!realesed.empty()) {
       T* pv = realesed.front();
      dediced.insert(pv);
      realesed.pop();
      return pv;
   }
   T* pv = new T;
   dediced.insert(pv);
    return pv;
}

template<class T>
T *ObjectPool<T>::TryAllocate() {
    if(!realesed.empty()){
        T* pv = realesed.front();
        dediced.insert(pv);
        realesed.pop();
        return pv;
    }
    return nullptr;
}

template<class T>
void ObjectPool<T>::Deallocate(T *object) {
if(dediced.count(object) != 0){
    realesed.push(object);
    dediced.erase(object);
} else {
    throw invalid_argument("");
}
}

template<class T>
ObjectPool<T>::~ObjectPool() {
  for(auto &w : dediced){
      delete w;
  }
  while(!realesed.empty()){
      delete realesed.front();
      realesed.pop();
  }
}


void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
