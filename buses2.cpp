#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int n, count, count_bus = 0;
	map <vector<string>, int> m;
	vector<string> tmp;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> count;
		for(int j = 0; j < count; j++) {
			string t;
			cin >> t;
			tmp.push_back(t);
		}
		if(m[tmp] > 0) {
			cout << "Already exists for " << m[tmp] << endl;
		}else {
			m[tmp] = ++count_bus;
			cout << "New bus " << m[tmp] << endl;
		}
		tmp.clear();
	}

	return 0;
}


