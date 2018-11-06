#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct day{
	vector<string> aims;

};


int main(){
	int n, month_number = 0;
	string s;
	vector<int> monthes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<day> days(32);
	int j;
	string aim;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		if(s == "ADD") {
			cin >> j;
			cin >> aim;
			days[j].aims.push_back(aim);

        }

		if(s == "DUMP") {
			cin >> j;

			if(days[j].aims.size() == 0) {
				cout << days[j].aims.size() << endl;
			}else {
				cout << days[j].aims.size() << " ";
				for(auto c : days[j].aims) {
					cout << c << " ";
				}
				cout << endl;
			}
		}

		if(s == "NEXT") {
			if(month_number == 11) {
				month_number = 0;
			}else {
				month_number++;
			}

			if(monthes[month_number] < monthes[month_number-1]) {

				int day2 = monthes[month_number-1];
				int day1 = monthes[month_number];

				for(int x = 1; x <= day2 - day1 ; x++) {
					days[day1].aims.insert(end(days[day1].aims), begin(days[day1 + x].aims), end(days[day1 + x].aims));

					for(auto t : days[day1 + x].aims) {
						days[day1 + x].aims.pop_back();
					}

				}
			}
		}

	}

return 0;
}


