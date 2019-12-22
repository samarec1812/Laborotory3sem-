#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

    int range_length = range_end - range_begin;
    if (range_length < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);

    auto mid = elements.begin() + range_length / 2;


    MergeSort(elements.begin(), mid);
    MergeSort(mid, elements.end());


    merge(elements.begin(), mid, mid, elements.end(), range_begin);
}

int main(){
    vector<int> a = {1,-5, 9, 4, -3, 0};
    for(auto &w :a){ cout << w << ' '; }
cout << endl;
    MergeSort(a.begin(), a.end());
    for(auto &w :a){ cout << w << ' '; }

}