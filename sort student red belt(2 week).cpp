#include "student.h"
#include <algorithm>

using namespace std;

bool Compare(const Student& first, const Student& second){
    return first.Less(second);
}