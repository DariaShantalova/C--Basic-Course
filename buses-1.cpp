#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int n, stop_count;
	string s, bus, stop;
	cin >> n;
	map<string, vector<string>> m;
	map<string, vector<string>> m2;
	for(int i = 0; i < n; i++) {
		cin >> s;
        if(s == "NEW_BUS") {
        	cin >> bus >> stop_count;
            for(int k = 0; k < stop_count; ++k) {
        	   	cin >> stop;
        	   	m[stop].push_back(bus);
        	   	m2[bus].push_back(stop);
        	}


		}
		if(s == "BUSES_FOR_STOP"){
			cin >> stop;
			if(m.count(stop) == 0){
				cout << "No stop" << endl;
			} else {
				for(auto t : m[stop]) {
					cout << t << " ";
				}
				cout << endl;
			}
		}
		if(s == "STOPS_FOR_BUS"){
			cin >> bus;
			if(m2.count(bus) == 0){
				cout << "No bus" << endl;
			}else{
				for(auto t : m2[bus]) {
					cout << "Stop " << t << ": ";
					if(m[t].size() <= 1) {
						cout << "no interchange" << endl;
					}else{
						for(auto c : m[t]){
							if(c != bus)
								cout << c << " ";
						}
						cout << endl;
					}
				}
			}
		}

		if(s == "ALL_BUSES"){
			if(m2.size() == 0) {
				cout << "No buses";
			}else{
				for(auto t : m2) {
					cout << "Bus " << t.first << ": ";
					for(auto x: t.second)
						cout << x << " " ;
					cout << endl;
				}
			}
			cout << endl;
		}
	}

	return 0;
}


