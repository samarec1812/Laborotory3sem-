#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Learner {
private:
    set<string> set_dict;

public:
    int Learn(const vector<string>& words) {
        size_t old_volume = set_dict.size();
        for (const auto& word : words) {
            set_dict.insert(word);
        }
        return static_cast<int>(set_dict.size() - old_volume);
    }

    vector<string> KnownWords() {        
        return {set_dict.begin(), set_dict.end()};
    }
};