#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

class ReadingManager {
public:
    ReadingManager() = default;

    void Read(int user_id, int page_count) {        
        if (readers_id_to_pc.count(user_id) != 0) {
            int old_page_count = readers_id_to_pc[user_id];
            auto it = readers_pc_to_id[old_page_count].find(user_id);
            if (it != readers_pc_to_id[old_page_count].end()) {
                readers_pc_to_id[old_page_count].erase(it);
            }
        }
        readers_id_to_pc[user_id] = page_count;
        readers_pc_to_id[page_count].insert(user_id);
    }

    double Cheer(int user_id) const {
        if (readers_id_to_pc.count(user_id) == 0) {
            return 0;
        }
        auto user_count = readers_id_to_pc.size();
        if (user_count == 1) {
            return 1;
        }

        int count = 0;
        int top_border = readers_id_to_pc.at(user_id);
        for (auto i = 1; i < top_border; ++i) {
            count += readers_pc_to_id[i].size();
        }

        return count * 1.0 / (user_count - 1);
    }

private:
    map<int, int> readers_id_to_pc;
    vector<set<int>> readers_pc_to_id{1001};
};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}
