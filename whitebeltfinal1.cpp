
#include <iostream>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>



using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	Date() {
		year = 0001;
		month = 01;
		day = 01;
	}
	Date(int new_year, int new_month, int new_day) {
		if (new_month < 1 || new_month > 12) {
			throw out_of_range("Month value is invalid: " + to_string(new_month));
		}
		else if (new_day < 1 || new_day > 31) {
			throw out_of_range("Day value is invalid: " + to_string(new_day));
		}
		year = new_year;
		month = new_month;
		day = new_day;
	}
	int GetYear() const {
		return year;
	};
	int GetMonth() const {
		return month;
	};
	int GetDay() const {
		return day;
	};


private:
	int year;
	int month;
	int day;
};

ostream& operator << (ostream& out, const Date& date) {
	out << date.GetYear() << '-' << date.GetMonth() << '-' << date.GetDay();
	return out;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		return lhs.GetYear() < rhs.GetYear();
	}
	else if (lhs.GetMonth() == rhs.GetMonth()) {
		return lhs.GetDay() < rhs.GetDay();
	}
	else {
		return lhs.GetMonth() < rhs.GetMonth();
	}
}

class Database {
public:

	void AddEvent(const Date& date, const string& event) {
		if (!event.empty()) {
			all[date].insert(event);
		}
	}
	bool DeleteEvent(const Date& date, const string& event) {
		bool y;
		if (all[date].count(event) > 0) {
			all[date].erase(event);
			y = true;
		}
		else {
			y = false;
		}
		return y;
	}

	int  DeleteDate(const Date& date) {
		int n = 0;
		if (all.count(date) > 0) {
			n = all[date].size();
			all.erase(date);
		}
		return n;
	}

	void Find(const Date& date) const {
		try {
			set<string> s = all.at(date);
			for (const auto& item : s) {
				cout << item << endl;
			}
		}
		catch (out_of_range&) {
			// нет событий
		}
	}

	void Print() const {
		for (const auto& pair : all) {
			for (const auto& event : pair.second) {
				cout << setw(4) << setfill('0') << pair.first.GetYear() << '-';
				cout << setw(2) << setfill('0') << pair.first.GetMonth() << '-';
				cout << setw(2) << setfill('0') << pair.first.GetDay();
				cout << " " << event << endl;
			}
		}
	}

private:
	map<Date, set<string>>all;
	// string event;
};
void EnsureNextSymbolEndSkip(istream &stream) {
	if (stream.peek() != '-') {
		throw runtime_error("");
	}
	
	stream.ignore(1);
}
istream& operator >> (istream& in, Date& date) {
	string input;
	in >> input;
	stringstream stream(input);
	int y; int m; int d;

	try {
		stream >> y;
		EnsureNextSymbolEndSkip(stream);
		stream >> m;
		EnsureNextSymbolEndSkip(stream);
		if (stream.peek() == EOF) {
			string er = "Wrong date format: " + input;
			throw runtime_error(er);
		}
		stream >> d;
		//EnsureNextSymbolEndSkip(stream);
		//int d = stream.peek();
		
		
		if (stream.peek() != -1) {
			throw runtime_error("");
		}
	}
	catch (runtime_error& re) {
		throw runtime_error("Wrong date format: " + input);
	}
	date = Date(y, m, d);

	return in;
}



int main() {
	Database db;

	string command;
	while (getline(cin, command)) {
		// Считайте команды с потока ввода и обработайте каждую
		stringstream stream(command);
		string operation;
		stream >> operation;

		try {
			if (operation == "Add") {
				stream.ignore(1);
				Date date;
				try {
					stream >> date;
				}
				catch (exception& ex) {
					cout << ex.what() << endl;
					//break;
				}
				stream.ignore(1);
				string event;
				stream >> event;
				db.AddEvent(date, event);
			}
			else if (operation == "Del") {
				stream.ignore(1);
				Date date;
				try {
					stream >> date;
				}
				catch (exception& ex) {
					cout << ex.what() << endl;
					break;
				}
				if (stream.peek() != -1) {
					stream.ignore(1);
					string event;
					stream >> event;
					if (db.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					}
					else {
						cout << "Event not found" << endl;
					}
				}
				else {
					int n = 0;
					n = db.DeleteDate(date);
					cout << "Deleted " << n << " events" << endl;
				}
			}
			else if (operation == "Find") {
				stream.ignore(1);
				Date date;
				try {
					stream >> date;
				}
				catch (exception& ex) {
					cout << ex.what() << endl;
					//break;
				}
				db.Find(date);
			}
			else if (operation == "Print") {
				db.Print();
				//break;
			}
			else if (operation == "") {

			}
			else {
				throw runtime_error("Unknown command: " + operation);
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
			//break;
		}
	}

	return 0;
}