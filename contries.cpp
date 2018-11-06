#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
	int n;
	string s, str1, str2;
	map <string, string> contries;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		if (s == "CHANGE_CAPITAL") {
			cin >> str1 >> str2;
			if(contries.count(str1) == 0) {
				cout << "Introduce new country " << str1 << " with capital " << str2 << endl;
			} else
			{
				if(contries[str1] == str2) {
					cout << "Country " << str1 << " hasn't changed its capital" << endl;
				}else {
					cout << "Country " << str1 << " has changed its capital from " << contries[str1] << " to " << str2 << endl;
				}
			}
			contries[str1] = str2;
		}
		if (s == "RENAME") {
			cin >> str1 >> str2;
			if(str1 == str2 || contries.count(str1) == 0 || contries.count(str2) != 0) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				contries[str2] = contries[str1];
				contries.erase(str1);
				cout << "Country " << str1 << " with capital " << contries[str2] << " has been renamed to " << str2 << endl;
			}
		}
		if (s == "ABOUT") {
           cin >> str1;
           if(contries.count(str1) == 0) {
        	   cout << "Country " << str1 <<" doesn't exist" << endl;
           } else {
        	   cout << "Country " << str1 << " has capital " << contries[str1]  << endl;
           }
        }
		if (s == "DUMP") {
			if(contries.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				for ( auto c : contries) {
					cout << c.first << "/" << c.second << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}


