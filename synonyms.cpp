#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(){
	map<string, set<string>> s;
	string tmp, word1, word2;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		if(tmp == "ADD") {
			cin >> word1 >> word2;
            s[word1].insert(word2);
            s[word2].insert(word1);
		}
		if(tmp == "COUNT") {
			cin >> word1;
			cout << s[word1].size() << endl;
		}
		if(tmp == "CHECK") {
			cin >> word1 >> word2;
			if(s[word1].count(word2) == 1) {
				cout << "YES" << endl;
			}else {
				cout << "NO" << endl;
			}
	    }
	}
	return 0;
}


