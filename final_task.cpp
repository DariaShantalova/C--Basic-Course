#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iomanip>
#include <exception>
#include <algorithm>
using namespace std;
class Date {
public:
	Date(int y, int m, int d){
		year = y;
		if(m > 12 || m < 1){
			throw logic_error("Month value is invalid: " + to_string(m));
		}
		month = m;
		if(d > 31 || d < 1){
		     throw logic_error("Day value is invalid: " + to_string(d));
		}
		day = d;
	}

	int GetYear() const{
		return year;
	}
	int GetMonth() const{
		return month;
	}
	int GetDay() const{
		return day;
	}
private:
	int month;
	int day;
	int year;
};

bool operator<(const Date& lhs, const Date& rhs){
	 return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
	           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
ostream& operator<<(ostream& stream, const Date& date){
	cout << setfill('0');
	stream << setw(4) << date.GetYear() << "-";
	stream << setw(2) << date.GetMonth() << "-";
	stream << setw(2) <<  date.GetDay();

	return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event){
	  events[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
      if (events.count(date) > 0 && events[date].count(event) > 0) {
          events[date].erase(event);
          return true;
      }
      return false;
  }

  int DeleteDate(const Date& date) {
      if (events.count(date) == 0) {
          return 0;
      } else {
          const int event_count = events[date].size();
          events.erase(date);
          return event_count;
      }
  }

  set<string> Find(const Date& date) const {
      if (events.count(date) > 0) {
          return events.at(date);
      } else {
          return {};
      }
  }

  void Print() const {
      for (const auto& item : events) {
          for (const string& event : item.second) {
              cout << item.first << " " << event << endl;
          }
      }
  }
private:
  map<Date, set<string>> events;
};
Date ParseDate(const string& date) {
    stringstream date_stream(date);

    int year;
    date_stream >> year;

    if (date_stream.peek() != '-') {
    	//cout << "mistake3";
        throw logic_error("Wrong date format: " + date);
    }
    date_stream.ignore(1);

    int month;
    date_stream >> month;


    if (date_stream.peek() != '-') {
        throw logic_error("Wrong date format: " + date);
    }
    date_stream.ignore(1);

    int day;
    date_stream >> day;


    if (!date_stream.eof()) {
        throw logic_error("Wrong date format: " + date);
    }

    return Date(year, month, day);
}

int main() {
    try {
        Database db;

        string command_line;
        while (getline(cin, command_line)) {
            stringstream ss(command_line);

            string command;
            ss >> command;

            if (command == "Add") {

                string date_str, event;
                ss >> date_str >> event;
                const Date date = ParseDate(date_str);
                db.AddEvent(date, event);

            } else if (command == "Del") {

                string date_str;
                ss >> date_str;
                string event;
                if (!ss.eof()) {
                    ss >> event;
                }
                const Date date = ParseDate(date_str);
                if (event.empty()) {
                    const int count = db.DeleteDate(date);
                    cout << "Deleted " << count << " events" << endl;
                } else {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }

            } else if (command == "Find") {

                string date_str;
                ss >> date_str;
                const Date date = ParseDate(date_str);
                for (const string& event : db.Find(date)) {
                    cout << event << endl;
                }

            } else if (command == "Print") {

                db.Print();

            } else if (!command.empty()) {

                throw logic_error("Unknown command: " + command);

            }
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}



