#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
	string name;
	string last_name;
	int day;
	int month;
	int year;
};
int main() {
	vector<Student> v;
	Student s;
	int N, M;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s.name >> s.last_name >> s.day >> s.month >> s.year;
		v.push_back(s);
	}
	cin >> M;
	for(int i = 0; i < M; i++){
		string str;
		cin >> str;
		int k;
		cin >> k;
		--k;
		if( str == "name" && k < N && k >=0 ){
			cout << v[k].name << " " << v[k].last_name << endl;
		}else{
			if( str == "date" && k < N && k >=0){
				cout << v[k].day << "." << v[k].month << "." << v[k].year << endl;
			}else{
				cout << "bad request" << endl;
			}
		}
	}
    return 0;
}
