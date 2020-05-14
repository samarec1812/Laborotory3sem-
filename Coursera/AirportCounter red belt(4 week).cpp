#include "test_runner.h"
#include "profile.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <vector>


using namespace std;

// TAirport should be enum with sequential items and last item TAirport::Last_
template<typename TAirport>
class AirportCounter {
public:
    // конструктор по умолчанию: список элементов пока пуст
    AirportCounter() {
        database.fill(0);
    }

    // конструктор от диапазона элементов типа TAirport
    template<typename TIterator>
    AirportCounter(TIterator begin, TIterator end) : AirportCounter() {
        TIterator it = begin;
        while (it != end) {
            database[static_cast<size_t>(*it)] += 1;
            ++it;
        }
    }
    // получить количество элементов, равных данному
    size_t Get(TAirport airport) const {
        return database[static_cast<size_t>(airport)];
    }

    // добавить данный элемент
    void Insert(TAirport airport) {
        database[static_cast<size_t>(airport)] += 1;
    }

    // удалить одно вхождение данного элемента
    void EraseOne(TAirport airport) {
        if (database[static_cast<size_t>(airport)] > 0) {
            database[static_cast<size_t>(airport)] -= 1;
        }
    }

    // удалить все вхождения данного элемента
    void EraseAll(TAirport airport) {
        if (database[static_cast<size_t>(airport)] > 0) {
            database[static_cast<size_t>(airport)] = 0;
        }
    }

    using Item = pair<TAirport, size_t>;
    using Items = array<Item, static_cast<size_t>(TAirport::Last_)>; /* ??? */

    // получить некоторый объект, по которому можно проитерироваться,
    // получив набор объектов типа Item - пар (аэропорт, количество),
    // упорядоченных по аэропорту
    Items GetItems() const {
        Items result;
        for (size_t idx = 0; idx < database.size(); ++idx) {
            result[idx] = {static_cast<TAirport>(idx), database[idx]};
        }
        return result;
    }

private:
    // ???
    array<size_t, static_cast<size_t>(TAirport::Last_)> database;
};