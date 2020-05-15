#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <system_error>
#include <algorithm>
using namespace std;

//realization 1 
string AskTimeServer() {

}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string time = AskTimeServer();
            last_fetched_time =time;
            return time;

        }catch(system_error& ex){
            return last_fetched_time;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};
/*
//realization 2 

#include <exception>
#include <system_error>

using namespace std;

class TimeServer {
public:
  string GetCurrentTime() {
    // поместим вызов функции AskTimeServer в try-catch блок
    try {
      last_fetched_time = AskTimeServer();
    } catch (const system_error&) {  // ловим только system_error
    }
    // возвращаем значение поля — либо обновлённое, либо нет
    return last_fetched_time;
  }

private:
  string last_fetched_time = "00:00:00";
};*/

int main() {
   //string str = "01:00:59";
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}

