#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;
// ответ на запрос ALL_BUSES
void AllBuses(const map<string, vector<string>>& buses) {
    if (buses.empty()) {
        cout << "No buses" << endl;
    } else {
        for (const auto& bus_item : buses) {
            cout << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                cout << stop << " ";
            }
            cout << endl;
        }
    }
}
// ответ на запрос STOPS_FOR_BUS
void StopsForBus(map<string, vector<string>>& buses, map<string, vector<string>>& ostanovki,
        const string& bus) {

    if (buses.count(bus) == 0) {
        cout << "No bus" << endl;
    } else {
        for (const string& stop : buses[bus]) {
            cout << "Stop " << stop << ": ";
            // если через остановку проходит ровно один автобус,
            // то это наш автобус bus, следовательно, пересадки тут нет
            if (ostanovki[stop].size() == 1) {
                cout << "no interchange";
            } else {
                for (const string& other_bus : ostanovki[stop]) {
                    if (bus != other_bus) {
                        cout << other_bus << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}

void BusesForStop(map<string, vector<string>>& ostanovki, const string& stop) {
    if (ostanovki.count(stop) == 0) {
        cout << "No stop" << endl;
    } else {
        for (const string& bus : ostanovki[stop]) {
            cout << bus << " ";
        }
        cout << endl;
    }
}
int main() {
    int q;
    cin >> q;
    map<string, vector<string>> buses, ostanovki;
    for (int i = 0; i < q; ++i) {

        string ss;

        cin >> ss;
        if (ss == "NEW_BUS") {

            string bus; cin >> bus;
            int stop_count; cin >> stop_count;

            // с помощью ссылки дадим короткое название вектору
            // со списком остановок данного автобуса;
            // ключ bus изначально отсутствовал в словаре, поэтому он автоматически
            // добавится туда с пустым вектором в качестве значения
            vector<string>& stops = buses[bus];
            stops.resize(stop_count);
            for (string& stop : stops) {
                cin >> stop;
                // не забудем обновить словарь stops_to_buses
                ostanovki[stop].push_back(bus);
            }
        } else if (ss == "BUSES_FOR_STOP") {

            string stop;
            cin >> stop;
            BusesForStop(ostanovki, stop);

        } else if (ss == "STOPS_FOR_BUS") {
            string bus; cin >> bus;
            StopsForBus(buses, ostanovki, bus);

        } else if (ss == "ALL_BUSES") {
            AllBuses(buses);
        }
    }
    return 0;
}