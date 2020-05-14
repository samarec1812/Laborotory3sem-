#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <string>
using namespace std;


enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator>> (istream& is, Query& w){
    int count_stop;
    string type, bus, stop;
    is >> type;
    if( type == "NEW_BUS"){
        is >> bus >> count_stop;
        vector<string> stops(count_stop);
        for( auto & name_of_stop: stops){
            is >> name_of_stop;
        }
        w.type = QueryType::NewBus;
        w.bus = bus;
        w.stops = stops;
    } else if (type == "BUSES_FOR_STOP"){
        is >> stop;
        w.type = QueryType ::BusesForStop;
        w.stop = stop;
    } else if(type == "STOPS_FOR_BUS"){
        is >> bus;
        w.type = QueryType ::StopsForBus;
        w.bus = bus;
    } else if (type == "ALL_BUSES"){
        w.type = QueryType :: AllBuses;
    }
return is;
}
struct BusesForStopResponse {
    // Наполните полями эту структуру
    string stop;
    vector<string> buses;
};

ostream& operator<< (ostream& os, const BusesForStopResponse& r){
    // Реализуйте эту функцию
    bool first = true;
    if (r.buses.empty()){
        os << "No stop";
    } else {
        for(const auto& w: r.buses){
            if(!first) os << " ";
            first = false;
            os << w;
        }
    }
    return os;
}

struct StopsForBusResponse {
    // Наполните полями эту структуру
    string buses;
    vector<string> some_stops;
    map<string, BusesForStopResponse> buses_for_stop;
};

ostream& operator <<(ostream& os, const StopsForBusResponse& r){
    bool f1 = true, f2 = true;
    if (r.some_stops.empty()) os << "No bus";
    else{
        for(const auto& w: r.some_stops){
            f2 = true;
            if(!f1) os << endl;
            f1 = false;
            os << "Stop " << w << ": ";
            if(r.buses_for_stop.at(w).buses.size() == 1 ) {
                os << "no interchange";
            }
            else{
                for(const auto& q: r.buses_for_stop.at(w).buses){
                    if(!f2) os << " ";
                    f2 = false;
                    if(r.buses != q){
                        os << q;
                    }
                }
            }
        }
    }
    return os;
}
struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> marshrut;
};
ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
   bool f1 = true, f2 = true;
   if(r.marshrut.empty()) os << "No buses";
   else{
       for(const auto& w: r.marshrut){
           f2 = true;
           if(!f1) os << endl;
           f1 = false;
           os << "Bus " << w.first << ": ";
           for(const auto& q : w.second){
               if(!f2) os << " ";
               f2 = false;
               os << q;
           }
       }
   }
   return os;
}

class BusManager{
public:
    void AddBus(const string& bus, const vector<string>& stoper) {
        // Реализуйте этот метод
        buses[bus] = stoper;
        for(const auto& w: stoper){
            stops[w]. push_back(bus);
         }
        }
    BusesForStopResponse GetBusesForStop(const string& stop) const {
        // Реализуйте этот метод
    vector<string> buses;
    if (stops.count(stop) > 0 ){
        buses = stops.at(stop);
    }else buses = {};
    return BusesForStopResponse {stop, buses};
    }
    StopsForBusResponse GetStopsForBus(const string& bus) const {
        // Реализуйте этот метод
    vector<string> stop;
    if (buses.count(bus) > 0) stop = buses.at(bus);
    else stop = {};
    map <string, BusesForStopResponse> buser;
    for (const auto& w: stop){
        buser[w] = GetBusesForStop(w);
    }
    return StopsForBusResponse {bus, stop, buser};
    }

    AllBusesResponse GetAllBuses() const {
        // Реализуйте этот метод
    map<string, vector<string>>buser;
    if(!buses.empty()) buser = buses;
    else buser = {};
        return AllBusesResponse{buser};
    }

private:
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
};



int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}